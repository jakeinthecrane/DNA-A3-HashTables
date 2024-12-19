#include "hashTable.h"

int main() 
{
    // Prompt the user for a string input
    cout << "Enter text to hash: ";
    string input;
    getline(cin, input);

    // Create a HashFunction object with integer as a result type
    HashFunction<int> hasher;

    // Hash function is called with the input stringfrom the caller.  The result will be stored as an integer however.. 
    hasher.hash(input);

    // Display the hash value message to screen for the user with the getHash function called right after
    cout << "Hashed value: " << hasher.getHash() << endl;

    // Prompt the user for an integer input to run the hash for integer numbers to be hashed
    cout << "\nEnter an integer to hash: ";
    int number;
    cin >> number;

    // Hash the integer input
    hasher.hash(number);

    // Display the hash value for the integer
    cout << "Hashed value: " << hasher.getHash() << endl;

    return 0;
}
