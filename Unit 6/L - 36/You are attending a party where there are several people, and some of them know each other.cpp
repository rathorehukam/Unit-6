








#include <iostream>
using namespace std;

#define MAX_N 100

int findCelebrity(int acquaintances[MAX_N][MAX_N], int n) {
    int transitiveClosure[MAX_N][MAX_N];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transitiveClosure[i][j] = acquaintances[i][j];
        }
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool isCelebrity = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && (transitiveClosure[i][j] || !transitiveClosure[j][i])) {
                isCelebrity = false;
                break;
            }
        }
        if (isCelebrity)
            return i;
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    int acquaintances[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> acquaintances[i][j];
        }
    }

    int celebrityIndex = findCelebrity(acquaintances, n);

    if (celebrityIndex != -1) {
        cout << "A celebrity is present at index " << celebrityIndex << " in the list of attendees.";
    } else {
        cout << "There is no celebrity at the party.";
    }

    return 0;
}
