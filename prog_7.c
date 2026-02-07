#include <stdio.h>
#include <limits.h>//necessary for intmax use

#define v 6

int min_distance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < v; i++)//for all vertices
     {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[v][v], int src) {
    int dist[v];
    int visited[v];

    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = min_distance(dist, visited);
        visited[u] = 1;

        for (int j = 0; j < v; j++) {
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX 
                && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("vertex \t distance from source %d\n", src);
    for (int i = 0; i < v; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[v][v] = {//entering the adjancey matrix
        
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    dijkstra(graph, 0);

    return 0;
}