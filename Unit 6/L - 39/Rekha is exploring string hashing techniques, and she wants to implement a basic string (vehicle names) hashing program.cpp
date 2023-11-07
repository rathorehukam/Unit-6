







#include <iostream>
#include <string>
using namespace std;

#define HASH_TABLE_SIZE 100

unsigned int customHash(string& key) {
    unsigned int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31) + c;
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
