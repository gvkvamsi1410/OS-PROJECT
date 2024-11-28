// Vamsi krishna -- 2203111
// Harsha Vardhan Reddy -- 2203105

#ifndef DEADLOCK_DETECTION_H
#define DEADLOCK_DETECTION_H
#include "graph.h"

int isDeadlock(Graph *g);
void displayRAG(Graph *g);
void resolveDeadlock(Graph *g);
void resetGraph(Graph *g);
void simulateScenario(Graph *g);
void setPriority(int process, int priority);
void waitWithPriority(int process, int resource);

#endif