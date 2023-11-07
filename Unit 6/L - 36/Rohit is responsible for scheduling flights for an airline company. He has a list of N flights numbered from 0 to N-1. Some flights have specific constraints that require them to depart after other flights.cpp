






#include <iostream>
using namespace std;

#define MAX_FLIGHTS 100

bool canCreateFlightSchedule(int n, int constraints[][2]) {
    int graph[MAX_FLIGHTS][MAX_FLIGHTS] = {0};

    for (int i = 0; i < n; ++i) {
        int flight = constraints[i][0];
        int mustDepartAfter = constraints[i][1];
        graph[flight][mustDepartAfter] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (graph[i][i]) {
            return false; 
        }
    }

    return true; 
}

int main() {
    int n;
    cin >> n;

    int constraints[MAX_FLIGHTS][2];
    for (int i = 0; i < n; ++i) {
        cin >> constraints[i][0] >> constraints[i][1];
    }

    if (canCreateFlightSchedule(n, constraints)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
