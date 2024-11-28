// Vamsi krishna -- 2203111
// Harsha Vardhan Reddy -- 2203105

#include <stdio.h>
#include <string.h>
#include "graph.h"

void initGraph(Graph *g, int n) {
    g->numNodes = n;
    memset(g->adjMatrix, 0, sizeof(g->adjMatrix));
}

void addEdge(Graph *g, int from, int to) {
    g->adjMatrix[from][to] = 1;
}

void removeEdge(Graph *g, int from, int to) {
    g->adjMatrix[from][to] = 0;
}

int detectCycleUtil(Graph *g, int node, int visited[], int stack[]) {
    if (!visited[node]) {
        visited[node] = 1;
        stack[node] = 1;

        for (int i = 0; i < g->numNodes; i++) {
            if (g->adjMatrix[node][i]) {
                if (!visited[i] && detectCycleUtil(g, i, visited, stack)) return 1;
                else if (stack[i]) return 1;
            }
        }
    }
    stack[node] = 0;
    return 0;
}

int detectCycle(Graph *g, int node) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES] = {0};
    return detectCycleUtil(g, node, visited, stack);
}