









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

        while (hashTable[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % tableSize;
        }

        hashTable[hashIndex] = key;
    }

    int f = -1, l = -1;
    int f_index = -1, l_index = -1;
    
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            if (f == -1) {
                f = hashTable[i];
                f_index = i;
            }
            l = hashTable[i];
            l_index = i;
        }
    }
    
    if (f != -1 && l != -1) {
        cout << "First index: " << f_index << ", Value: " << f << endl;
        cout << "Last index: " << l_index << ", Value: " << l << endl;
    } 
    
    return 0;
}
