// Vamsi krishna -- 2203111
// Harsha Vardhan Reddy -- 2203105

#include <stdio.h>
#include "deadlock_detection.h" 
#include "graph.h"             
#include "semaphore.h"         //provides semaphore-related utilities.

Graph resourceGraph; // represents the Resource Allocation Graph (RAG).

int processPriority[MAX_NODES] = {0}; // stores priority values for each process.

// checks if there is a deadlock in the Resource Allocation Graph (RAG).
int isDeadlock(Graph *g) {
    // Iterate through all nodes in the graph to detect cycles.
    for (int i = 0; i < g->numNodes; i++) {
        // If a cycle is detected starting from node `i`, a deadlock exists.
        if (detectCycle(g, i)) return 1;
    }
    return 0; // No deadlock found.
}

// Function to display the current state of the Resource Allocation Graph.
void displayRAG(Graph *g) {
    printf("Resource Allocation Graph:\n");
    for (int i = 0; i < g->numNodes; i++) {
        for (int j = 0; j < g->numNodes; j++) {
            if (g->adjMatrix[i][j]) {
                // Print all edges in the graph (i.e., resource requests or allocations).
                printf("Node %d -> Node %d\n", i, j);
            }
        }
    }
}

// Function to resolve deadlock by terminating a process and releasing its resources.
void resolveDeadlock(Graph *g) {
    printf("Attempting to resolve deadlock...\n");
    for (int i = 0; i < g->numNodes; i++) {
        // Check if a cycle (deadlock) exists starting from node `i`.
        if (detectCycle(g, i)) {
            printf("Process P%d is involved in deadlock.\n", i);
            printf("Terminating Process P%d to resolve deadlock.\n", i);

            // Release all resources held by Process P[i].
            for (int j = 0; j < g->numNodes; j++) {
                removeEdge(g, i, j);
            }

            printf("Deadlock resolved.\n");
            return; // Exit after resolving the deadlock.
        }
    }
    printf("No deadlock to resolve.\n");
}

// Function to simulate a resource allocation scenario and test deadlock detection and resolution.
void simulateScenario(Graph *g) {
    printf("Simulating resource allocation scenario...\n");

    // Initialize a graph with 6 nodes (3 processes + 3 resources).
    initGraph(g, 6);

    // Create resource requests and allocations that lead to a deadlock.
    addEdge(g, 0, 3); // P0 -> R3 (Process P0 requests Resource R3)
    addEdge(g, 3, 1); // R3 -> P1 (Resource R3 allocated to Process P1)
    addEdge(g, 1, 4); // P1 -> R4 (Process P1 requests Resource R4)
    addEdge(g, 4, 2); // R4 -> P2 (Resource R4 allocated to Process P2)
    addEdge(g, 2, 5); // P2 -> R5 (Process P2 requests Resource R5)
    addEdge(g, 5, 0); // R5 -> P0 (Resource R5 allocated to Process P0)

    printf("Resource Allocation Graph created.\n");
    displayRAG(g); // Display the current state of the graph.

    // Check for deadlock in the graph.
    if (isDeadlock(g)) {
        printf("Deadlock detected after allocations.\n");
        resolveDeadlock(g); // Attempt to resolve the detected deadlock.
    } else {
        printf("No deadlock detected.\n");
    }

    // Reset the graph for a clean state.
    resetGraph(g);
}

// Function to set priority for a specific process.
void setPriority(int process, int priority) {
    if (process >= 0 && process < MAX_NODES) {
        // Update the priority value for the process.
        printf("Setting priority of Process P%d to %d\n", process, priority);
        processPriority[process] = priority;
    } else {
        // Handle invalid process ID.
        printf("Invalid process ID: %d\n", process);
    }
}

// Function to reset the Resource Allocation Graph (RAG).
void resetGraph(Graph *g) {
    printf("Resetting Resource Allocation Graph...\n");
    initGraph(g, g->numNodes); // Reinitialize the graph to its original state.
    printf("Graph reset successfully.\n");
}
