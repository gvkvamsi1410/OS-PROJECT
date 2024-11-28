// Vamsi krishna -- 2203111
// Harsha Vardhan Reddy -- 2203105

#include <stdio.h>
#include "semaphore.h" // provides semaphore-related utilities.
#include "graph.h"     // provide graph-related functions like addEdge and removeEdge.
#include "deadlock_detection.h" //provides functions to detect deadlocks in the resource graph.

// The graph maintains relationships between processes and resources.
extern Graph resourceGraph;

/**
 * Function: wait
 * ----------------
 * Simulates the request of a resource by a process. 
 * Adds an edge from the process to the resource in the resource allocation graph,
 * indicating that the process is waiting for the resource.
 */
void wait(int process, int resource) {
    // Add an edge from the process to the resource in the resource graph.
    // This represents that the process is now waiting for the resource.
    addEdge(&resourceGraph, process, resource);
    printf("Process P%d is requesting Resource R%d.\n", process, resource);

    // Check if adding this edge introduces a deadlock in the system.
    if (isDeadlock(&resourceGraph)) {
        // Notify that a deadlock has been detected.
        // This warns the user/system about potential problems due to this request.
        printf("Warning: Deadlock detected. Process P%d's request may cause issues.\n", process);
    }
}

/**
 * Function: signal
 * ----------------
 * Simulates the release of a resource by a process.
 * Removes the edge from the process to the resource in the resource allocation graph,
 * indicating that the resource is no longer held or needed by the process.
 */
void signal(int process, int resource) {
    // Remove the edge from the process to the resource in the resource graph.
    // This signifies that the process has released the resource.
    removeEdge(&resourceGraph, process, resource);
    printf("Process P%d released Resource R%d.\n", process, resource);
}

