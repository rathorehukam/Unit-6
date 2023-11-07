





#include <iostream>
using namespace std;

int MAX_COURSES = 100;

bool canCompleteAllCourses(int n, int prerequisites[][2]) {
    bool graph[MAX_COURSES][MAX_COURSES] = {false};

    for (int i = 0; i < n; ++i) {
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];
        graph[course][prerequisite] = true;
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

    int prerequisites[MAX_COURSES][2];
    for (int i = 0; i < n; ++i) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    if (canCompleteAllCourses(n, prerequisites)) {
        cout << "It is possible to complete all courses based on the given prerequisites.";
    } else {
        cout << "It is not possible to complete all courses based on the given prerequisites.";
    }

    return 0;
}
