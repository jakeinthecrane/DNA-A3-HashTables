#pragma once
#include <string>
#include <iostream>

using namespace std;

// Template class for a basic hash function
template <typename T>
class HashFunction 
{
private:
    T* hashedValue; // Pointer to store the dynamically allocated hash value

    // Recursive helper function to calculate the hash value
    int calculateHash(const string& text, int index, int currentHash);

public:
    // Hash Constructor (since it has the same class name it is considered a constructor..)
    HashFunction();

    // 1st hash method for string inputs
    void hash(const string& text);

    // Overloaded hash method for integer inputs
    void hash(int number);

    // Getter for the calculated hash value
    T getHash() const;

    // Destructor
    ~HashFunction();
};
