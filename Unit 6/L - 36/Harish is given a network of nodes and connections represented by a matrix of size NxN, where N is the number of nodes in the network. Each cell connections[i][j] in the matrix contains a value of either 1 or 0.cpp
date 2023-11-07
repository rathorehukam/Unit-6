







#include <iostream>
using namespace std;

#define MAX_NODES 100

bool hasChainOfConnections(int n, int connections[MAX_NODES][MAX_NODES], int source, int target) {
    int reachable[MAX_NODES][MAX_NODES];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            reachable[i][j] = connections[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
            }
        }
    }

    return reachable[source][target];
}

int main() {
    int n; 
    cin >> n;

    int connections[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> connections[i][j];
        }
    }

    int source, target;
    cin >> source >> target;

    if (hasChainOfConnections(n, connections, source, target)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
