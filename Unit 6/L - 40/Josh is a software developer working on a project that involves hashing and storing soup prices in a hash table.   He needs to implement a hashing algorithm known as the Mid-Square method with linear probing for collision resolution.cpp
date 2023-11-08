










#include <iostream>
using namespace std;

int midSquareHash(int key, int tableSize) {
    int squared = key * key;
    int middleDigits = (squared / 10) % 100;

    return middleDigits % tableSize;
}

int linearProbe(int hashTable[], int tableSize, int index) {
    while (hashTable[index] != -1) {
        index = (index + 1) % tableSize;
    }
    return index;
}

int main() {
    int tableSize = 100;
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

        hashIndex = linearProbe(hashTable, tableSize, hashIndex);

        hashTable[hashIndex] = key;
    }

    int sum = 0;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            cout << "Index " << i << ": Key " << hashTable[i] << endl;
        }
    }
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            if (i % 2 == 0) {
                sum += hashTable[i];
            }
        }
    }
    cout << "Sum of even indexed soup price: " << sum;

    return 0;
}
