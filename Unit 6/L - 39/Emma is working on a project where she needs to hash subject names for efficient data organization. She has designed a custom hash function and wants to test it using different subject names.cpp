







#include <iostream>
#include <string>
using namespace std;

#define HASH_TABLE_SIZE 1000

unsigned int customHash(string key) {
    unsigned int hashValue = 0;

    for (size_t i = 0; i < key.length(); ++i) {
        hashValue = (hashValue * 37) + key[i];
    }

    return hashValue % HASH_TABLE_SIZE;
}

int main() {
    string key;
    while (true) {
        cin >> key;

        if (key == "exit") {
            break;
        }

        unsigned int hashValue = customHash(key);
        cout << hashValue << endl;
    }

    return 0;
}
