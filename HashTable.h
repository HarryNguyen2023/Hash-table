#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <list>
#include <string>

// Define the class of the hash table 
class HashTable
{
    int capacity;
    std::list<int>* hash_table;

    bool checkPrime(int num);
    int getPrime(int num);
    int Hash(int data);
    bool searchItem(int data);
    int RabinKarp(std::string pattern, std::string text, int q, int d);

    public:

    HashTable(int capacity);
    void insertItem(int data);
    void delItem(int data);
    void search(int data);
    void RabinKarp(std::string pattern, std::string text);
    void displayTable(void);
};

#endif