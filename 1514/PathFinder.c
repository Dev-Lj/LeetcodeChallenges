#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int get_maxdist_idx(int n, double* dist, int* visited) {
    double maxdist = 0;
    int max_idx = -1;
    for (int i = 0; i < n; i++)
    {
        double d = dist[i];
        if (!visited[i] && d > maxdist)
        {
            maxdist = d;
            max_idx = i;   
        }
    }
    return max_idx;
}

void set_unvisited_neighbors(int current, int** edges, int edgesSize, double* succProb, int* visited, int* neighbors, int* amount_neighbors) {
    *amount_neighbors = 0;
    for (int i = 0; i < edgesSize; i++)
    {
        if ((edges[i][0] == current && !visited[edges[i][1]]) || (edges[i][1] == current && !visited[edges[i][0]]))
        {
            neighbors[*amount_neighbors] = i;
            *amount_neighbors += 1;
        }    
    }
}

double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start, int end){
    double dist[n];
    int visited[n];
    int prev[n];
    int unvisited_len = n;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = 0;
    }
    dist[start] = 1;

    int amount_neighbors = 0;
    int* amount_neighbors_p = &amount_neighbors;
    int neighbors[edgesSize];

    while (unvisited_len != 0)
    {
        int u = get_maxdist_idx(n, dist, visited);
        if (u == -1)
        {
            // target can not be reached
            break;
        }
        
        visited[u] = true;
        unvisited_len--;

        if (u == end)
        {
            return dist[u];
        }
        
        set_unvisited_neighbors(u, edges, edgesSize, succProb, visited, neighbors, amount_neighbors_p);
        for (int i = 0; i < amount_neighbors; i++)
        {
            int* edge = edges[neighbors[i]];
            int v = edge[0] == u? edge[1]:edge[0];
            double alt = dist[u] * succProb[neighbors[i]];
            if (alt > dist[v]) {
                dist[v] = alt;
            }
        }
    }
    return 0.0;
}

int main() {
    const int n = 3;
    int* edges[n];
    for (int i = 0; i < 3; i++)
    {
        edges[i] = malloc(2 * sizeof(int));
    }
    int edgecolsize[] = {2,2,2};
    // [[0,1],[1,2],[0,2]]
    edges[0][0] = 0;
    edges[0][1] = 1;
    edges[1][0] = 1;
    edges[1][1] = 2;
    edges[2][0] = 0;
    edges[2][1] = 2;
    double succProb[] = {0.5,0.5,0.3};

    double maxProb = maxProbability(n, edges, 3, edgecolsize,succProb, 3, 0, 2);

    printf("Path wiht max prob: %f\n", maxProb);

    return 0;
}

// To run: gcc PathFinder.c -o PathFinder.exe -g