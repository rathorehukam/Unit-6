













#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 10

void add_edge(int adj[][MAX_V], int src, int dest) {
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

void initialize(int *pred, int *dist, int size) {
    for(int i = 0; i < size; i++) {
        pred[i] = -1;
        dist[i] = INT_MAX;
    }
}

int BFS(int adj[][MAX_V], int src, int dest, int v, int pred[], int dist[]) {
    int queue[MAX_V], front = 0, rear = 0;
    int visited[MAX_V];
    memset(visited, 0, sizeof(visited)); 
    
    visited[src] = 1;
    dist[src] = 0;
    queue[rear++] = src; 
    
    while(front != rear) {
        int current = queue[front++]; 
        for(int i = 0; i < v; ++i) {
            if(adj[current][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[current] + 1;
                pred[i] = current;
                queue[rear++] = i; 
                
                if(i == dest) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void printShortestDistance(int adj[][MAX_V], int s, int dest, int v) {
    int pred[MAX_V], dist[MAX_V];
    initialize(pred, dist, v); 

    if (BFS(adj, s, dest, v, pred, dist) == 0) {
        printf("Given source and destination are not connected\n");
        return;
    }

    int path[MAX_V];
    int crawl = dest;
    int pathLength = 0;
    path[pathLength++] = crawl;

    while (pred[crawl] != -1) {
        path[pathLength++] = pred[crawl];
        crawl = pred[crawl];
    }

    printf("Shortest path length is: %d\n", dist[dest]);
    printf("Path is: ");
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}

int main() {
    int v, e, src, dest, source, destination;
    int adj[MAX_V][MAX_V] = {0}; 

    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        add_edge(adj, src, dest);
    }

    scanf("%d", &source);
    scanf("%d", &destination);

    printShortestDistance(adj, source, destination, v);

    return 0;
}
