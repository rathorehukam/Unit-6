












#include <iostream>
#include <vector>

using namespace std;

void depthFirstTraversal(vector<vector<int>>& adjacencyList, int startVertex, vector<bool>& visited) {
    visited[startVertex] = true;
    cout << startVertex << " ";

    for (int neighbor : adjacencyList[startVertex]) {
        if (!visited[neighbor]) {
            depthFirstTraversal(adjacencyList, neighbor, visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adjacencyList(V);

    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        adjacencyList[v].push_back(w);
    }

    int startVertex;
    cin >> startVertex;
    vector<bool> visited(V, false);

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    depthFirstTraversal(adjacencyList, startVertex, visited);

    return 0;
}
