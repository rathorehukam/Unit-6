





#include <iostream>
using namespace std;

int main() {
    
    int tableSize = 10;
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
        int hashIndex = key % tableSize;
        int j = 0;
        while (hashTable[hashIndex] != -1) {
            j++;
            hashIndex = (hashIndex + j * j) % tableSize;
        }
        hashTable[hashIndex] = key;
    }
    int j, f = 0;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            int c = 0;
            for (j = 1; j <= i; j++) {
                if (i % j == 0) {
                    c++;
                }
            }
            if (c == 2) {
                cout << "The price of the dish in prime position: " << i << " is Rs." << hashTable[i] << endl;
                f = 1;
            }
        }
    }
    if (f == 0) {
        cout << "No dish is placed in prime position";
    }
    return 0;
}
