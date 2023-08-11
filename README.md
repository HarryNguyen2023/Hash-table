# Hash-table
## Author: Harry Nguyen (created 08/07/2023)

### Introduction:
Hash table is a very popular data structure, invented to accommodate a huge amount of data. Each data in the hash table will go along with a label called key, which help to classified the data and improve search runtime.

It's is ideal to have only one data asscoiated with each key, however, due to storage and hashing algorithm problem, we must accept hash collision and find the way to resolve that. There are 2 main ways to represent a hash table, separate chain or single-data-per-key. Meanwhile the former simply links data having the same key together using linked list, the latter one requires a collision resolve method to redistribute the data over the key.

In this project, I have build a header file for hash table using seperate chain method, and a simple hashing algorithm based on modulua.

### References:
[1]. Programiz, Hash Table, https://www.programiz.com/dsa/hash-table.

[2]. Narasimha Karumanchi, 2017, DATA STRUCTURE AND ALGORITHMS MADE EASY, CareerMonk.com.

