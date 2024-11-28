// Vamsi krishna -- 2203111
// Harsha Vardhan Reddy -- 2203105

#include <stdio.h>
#include "deadlock_detection.h"
#include "graph.h"

int main() {
    Graph resourceGraph;
    initGraph(&resourceGraph, 5); // Initialize a graph with 5 nodes

    setPriority(0, 1);
    setPriority(1, 2);
    setPriority(2, 3);

    simulateScenario(&resourceGraph);
    return 0;
}