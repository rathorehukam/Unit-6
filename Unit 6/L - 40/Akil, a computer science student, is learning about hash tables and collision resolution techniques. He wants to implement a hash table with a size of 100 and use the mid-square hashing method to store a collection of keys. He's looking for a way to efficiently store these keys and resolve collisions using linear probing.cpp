







#include <iostream>
using namespace std;

#define TABLE_SIZE 100

int hashTable[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int midSquareHash(int key) {
    int square = key * key;
    int middleDigits = (square / 10) % 100; 
    return middleDigits % TABLE_SIZE; 
}

int linearProbe(int index) {
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    return index;
}

int main() {
    initializeHashTable();

    int n, key;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;

        int index = midSquareHash(key);

        if (hashTable[index] == -1) {
            hashTable[index] = key;
        } else {
            int newIndex = linearProbe(index);
            hashTable[newIndex] = key;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            cout << "Index " << i << ": Key " << hashTable[i] << endl;
        }
    }

    return 0;
}
