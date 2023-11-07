













#include <iostream>
using namespace std;

#define MAX_TASKS 100

bool canCompleteAllTasks(int n, int dependencies[][2]) { 
    int graph[MAX_TASKS][MAX_TASKS] = {0};
 
    for (int i = 0; i < n; ++i) {
        int taskID = dependencies[i][0];
        int prerequisiteTaskID = dependencies[i][1];
        graph[taskID][prerequisiteTaskID] = 1;
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

    int dependencies[MAX_TASKS][2];
    for (int i = 0; i < n; ++i) {
        cin >> dependencies[i][0] >> dependencies[i][1];
    }

    if (canCompleteAllTasks(n, dependencies)) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }

    return 0;
}
