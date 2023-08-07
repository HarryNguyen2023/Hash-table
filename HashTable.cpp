#include <iostream>
#include <limits.h>
#include "HashTable.h"

// Function to check if the given number is a prime number
bool HashTable::checkPrime(int num)
{
    if(num == 0 || num == 1)
        return false;
    for(int i = 2; i < num / 2; ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

// Function to get the closest prime number to a given number
int HashTable::getPrime(int num)
{
    if(num % 2 == 0)
        num++;
    while(! checkPrime(num))
        num += 2;
    return num;
}

// Simple hash function using modulus
int HashTable::Hash(int data)
{
    return data % capacity;
}

// Constructor to initiate the hash table
HashTable::HashTable(int capacity)
{
    this->capacity = getPrime(capacity);
    hash_table = new std::list<int>[this->capacity];
}

// Function to insert the new element into the hash table
void HashTable::insertItem(int data)
{
    int key = Hash(data);
    hash_table[key].push_back(data);
}

// Function to search for an input data in the hash table
bool HashTable::searchItem(int data)
{
    int key = Hash(data);
    for(auto it = hash_table[key].begin(); it != hash_table[key].end(); ++it)
    {
        if((*it) == data)
            return true;
    }
    return false;
}

// General function to search item in the hash table
void HashTable::search(int data)
{
    std::cout<<"\nItem "<<data<<" is"<<((searchItem(data)) ? "" : " not")<<" in the hash table"<<std::endl;
}

// Function to delete a given input data from the hash table
void HashTable::delItem(int data)
{
    int key = Hash(data);
    // Remove the data from the associated key
    hash_table[key].remove(data);
}

// Function to display the hash table to the terminal
void HashTable::displayTable()
{
    std::cout<<"\nHash table\n";
    for(int i = 0; i < capacity; ++i)
    {
        std::cout<<"Key "<<i<<": ";
        for(auto it = hash_table[i].begin(); it != hash_table[i].end(); ++it)
            std::cout<<*it<<" ";
        std::cout<<std::endl;
    }
}

// Function to perform the RapinKarp algorithm to find matching strings
int HashTable::RabinKarp(std::string pattern, std::string text, int q, int d)
{
    int m = pattern.length();
    int n = text.length();

    int i, j, p = 0, t = 0, h = 1;

    for(i = 0; i < m; ++i)
        h = (h * d) % q;

    // Calculate the hash value of pattern and text
    for(i = 0; i < m; ++i)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match string
    for(i = 0; i <= n - m; ++i)
    {
        // Case both hash value match
        if(p == t)
        {
            // Start to compare 2 string
            for(j = 0; j < m; ++j)
            {
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == m)
                return i + 1;
        }

        if(i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if(t < 0)
                t += q;
        }
    }
    return INT_MIN;
}

// Function for user to call the Rabin-Karp algorithm
void HashTable::RabinKarp(std::string pattern, std::string text)
{
    int pos = RabinKarp(pattern, text, INT_MAX, 256);
    if(pos != INT_MIN)
        std::cout<<"\nString "<<pattern<<" is found in "<<text<<" at position "<<pos<<std::endl;
    else
        std::cout<<"\nString "<<pattern<<" is not found in "<<text<<std::endl;
}

int main()
{
    HashTable ht(10);
    int key[] = {3, 9, 7, 4, 5, 26, 33, 49, 53, 61, 85, 101, 18, 27};

    // Insert elements into the hash table
    for(int i = 0; i < sizeof(key)/sizeof(int); ++i)
        ht.insertItem(key[i]);

    // Display the table 
    ht.displayTable();

    // Search some element
    ht.search(9);
    ht.search(61);

    // Remove some element
    ht.delItem(61);

    // Search for deleted element
    ht.search(61);

    // Display the hash table once again
    ht.displayTable();

    // Rabin Karp algorithm
    ht.RabinKarp("GEEK", "GEEKS FOR GEEKS");

    return 0;
}