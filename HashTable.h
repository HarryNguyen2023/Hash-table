#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <list>

// Define the class of the hash table 
class HashTable
{
    int capacity;
    std::list<int>* hash_table;

    bool checkPrime(int num);
    int getPrime(int num);
    int Hash(int data);
    bool searchItem(int data);

    public:
    HashTable(int capacity);
    void insertItem(int data);
    void delItem(int data);
    void search(int data);
    void displayTable(void);
};

#endif