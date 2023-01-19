#include "graph.h"

int isEmpty(queuenode** head);
int peek(queuenode** head);
pnode remove(queuenode** head);
void insert(queuenode** head, pnode d, int p);

queuenode* newQueueNode(pnode data, int value);
pedge newEdge(int weight, pedge next, pnode dest);