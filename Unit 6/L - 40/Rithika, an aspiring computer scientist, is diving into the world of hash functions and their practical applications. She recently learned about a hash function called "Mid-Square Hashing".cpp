















v#include <iostream>
using namespace std;

int midSquareHash(int key, int tableSize) 
{
    int squared = key * key;
    int middleDigit = (squared / 10) % 100; 
    int hashIndex = middleDigit % tableSize;
    return hashIndex;
}

int main() {
    int tableSize = 100, in, max; 
    int numKeys;   
    cin >> numKeys;
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        cin >> keys[i];
    }
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int hashIndex = midSquareHash(key, tableSize);
        
        while (hashTable[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % tableSize;
        }
        hashTable[hashIndex] = key;
    }
    
    max = hashTable[0];
    in = 0;
    for (int i = 1; i < tableSize; i++) {
        if (hashTable[i] != -1 && hashTable[i] > max) {
            max = hashTable[i];
            in = i;
        }
    }
    cout << "Weight: " << max << ", Index: " << in;
    return 0;
}
