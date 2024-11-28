// Vamsi krishna -- 2203111
// Harsha Vardhan Reddy -- 2203105

#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 10

typedef struct {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

void initGraph(Graph *g, int n);
void addEdge(Graph *g, int from, int to);
void removeEdge(Graph *g, int from, int to);
int detectCycle(Graph *g, int node);

#endif