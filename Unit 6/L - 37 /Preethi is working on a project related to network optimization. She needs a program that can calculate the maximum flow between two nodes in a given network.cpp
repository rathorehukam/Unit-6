






#include <iostream>
#include <climits>

using namespace std;

#define INF 1000000000
#define MAXN 100

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    int graph[MAXN][MAXN];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int source, sink;
    cin >> source;
    cin >> sink;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    if (graph[source][sink] == INF) {
        cout << "Nodes are unreachable. Maximum flow is 0." << endl;
    } else {
        int shortest_distance = graph[source][sink];
        cout << "Maximum flow from node " << source << " to " << sink << " is: " << shortest_distance << endl;
    }

    return 0;
}
