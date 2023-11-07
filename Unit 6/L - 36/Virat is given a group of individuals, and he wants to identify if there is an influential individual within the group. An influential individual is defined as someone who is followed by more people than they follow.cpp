






#include <iostream>
using namespace std;

#define MAX_N 100

int findInfluentialIndividual(int acquaintances[MAX_N][MAX_N], int n) {
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
        bool isInfluential = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && (transitiveClosure[i][j] || !transitiveClosure[j][i])) {
                isInfluential = false;
                break;
            }
        }
        if (isInfluential)
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

    int influentialIndividualIndex = findInfluentialIndividual(acquaintances, n);

    if (influentialIndividualIndex != -1) {
        cout << "Influential Individual: " << influentialIndividualIndex;
    } else {
        cout << "There is no influential individual in the group";
    }

    return 0;
}
