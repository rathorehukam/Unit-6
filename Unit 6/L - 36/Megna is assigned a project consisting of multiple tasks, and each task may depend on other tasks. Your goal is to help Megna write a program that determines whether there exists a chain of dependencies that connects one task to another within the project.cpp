





#include <iostream>
using namespace std;

#define MAX_TASKS 100

bool hasChainOfDependencies(int n, int dependencies[MAX_TASKS][MAX_TASKS], int task1, int task2) {
    int isDependent[MAX_TASKS][MAX_TASKS];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            isDependent[i][j] = dependencies[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                isDependent[i][j] = isDependent[i][j] || (isDependent[i][k] && isDependent[k][j]);
            }
        }
    }

    return isDependent[task1][task2];
}

int main() {
    int n; 
    cin >> n;

    int dependencies[MAX_TASKS][MAX_TASKS] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dependencies[i][j];
        }
    }

    int task1, task2;
    cin >> task1 >> task2;

    if (hasChainOfDependencies(n, dependencies, task1, task2)) {
        cout << "There is a chain of dependencies.";
    } else {
        cout << "There is no chain of dependencies.";
    }

    return 0;
}
