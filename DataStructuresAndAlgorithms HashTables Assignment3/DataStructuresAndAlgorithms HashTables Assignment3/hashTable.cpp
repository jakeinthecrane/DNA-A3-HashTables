#include "hashTable.h"

// Constructor: dynamically allocates memory for the hash value here.
template <typename T>
HashFunction<T>::HashFunction() : hashedValue(new T(0)) // referance HashFunction from .h file and named it hashedValue with an assigned parameter with data type set to 0
{}

// Recursive helper function: calculates the hash value
template <typename T>
int HashFunction<T>::calculateHash(const string& text, int index, int currentHash) 
{
    if (index >= text.length()) 
    {
        return currentHash; // Base case: end of the string, this is where recursion stops.  From here the function starts whats called "unwinding" which means each previous call with the computed result is propagated back to the previous call on the stack. By defining where recursion stops we are preventing infinite recursion...
    }
    // Hash logic: multiply hash by 31 (prime number) and add ASCII value and divide that result by 1000 modulo.  
    currentHash = (currentHash * 31 + text[index]) % 1000; // 31 is used often in hash functions and reduces chances of collisions, and modulo 1000 helps keep hash values small and that makes them faster to work compare and work with.  
    return calculateHash(text, index + 1, currentHash); // Process the next character creating the recursion instance since this 
}

// 1st hash method for string inputs... using these next 2 functions for cleaner better ux.... high-leverinterface.. creates abstraction.  
template <typename T>
void HashFunction<T>::hash(const string& text) 
{
    *hashedValue = calculateHash(text, 0, 0); // Start hash calculation
} 

// Overloaded hash method for integer inputs
template <typename T>
void HashFunction<T>::hash(int number)
{
    string text = to_string(number); // Convert integer to string here 
    hash(text);                      // Reuse the string hash method
}

// Getter for the calculated hash value
template <typename T>
T HashFunction<T>::getHash() const
{
    return *hashedValue; // Return the hash value
}

// Destructor: frees dynamically allocated memory
template <typename T>
HashFunction<T>::~HashFunction()
{
    delete hashedValue; // Prevent memory leaks
}

// Explicit template instantiation for int here otherwise the compiler has trouble generating the required code making available for the linker. 
template class HashFunction<int>;


/* recursive example..

calculateHash("abc", 0, 0)	    354  
calculateHash("abc", 1, 97)  	354
calculateHash("abc", 2, 105)	354
calculateHash("abc", 3, 354)	354   

currentHash = (currentHash * 31 + text[0]) % 1000;
currentHash = (0 * 31 + 97) % 1000;
currentHash = (0 + 97) % 1000;
currentHash = 97;

currentHash = (currentHash * 31 + text[1]) % 1000;
currentHash = (97 * 31 + 98) % 1000;
currentHash = (3007 + 98) % 1000;
currentHash = 3105 % 1000;
currentHash = 105;

currentHash = (currentHash * 31 + text[2]) % 1000;
currentHash = (105 * 31 + 99) % 1000;
currentHash = (3255 + 99) % 1000;
currentHash = 3354 % 1000;
currentHash = 354            */