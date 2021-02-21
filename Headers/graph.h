#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <stdint.h>
#include <stdlib.h>
#include "../Headers/appconst.h"

typedef struct _node_ Node;
typedef struct _graph_ Graph;

/* data structures to represent the indiviual vertex of graph. */

struct _node_ {
   int32_t node_id;
   uint32_t cost;
   Node *next;
};

struct _graph_ {
   uint32_t size;
   Node **neighbours;
};

uint8_t visited[MAX_NODES];

/* public intefaces */

Graph graph_new(uint32_t size);
Graph* graph_adjacency_list(Graph *g);
Graph* graph_dfs(Graph *g, int32_t vertex); 
Graph* graph_bfs(Graph *g, int32_t vertex); 

#endif // GRAPH_H_INCLUDED