#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Headers/graph.h"
#include "../Headers/appconst.h"
#include "../../AdaptiveQueue/Headers/queue.h"

Graph graph_new(uint32_t size){
    Graph g;
    g.size = size;
    g.neighbours = (Node**)malloc(size * sizeof(Node*));

    for (int i = 0; i < size; ++i){
        g.neighbours[i] = NULL;
    }
    return g;
}

static Node* _make_node_(int32_t data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->node_id = data;
    node->cost = 0;
    node->next = NULL;

    return node;
}

static int32_t _get_neighbour_id_(int32_t node) {
    int32_t neighbour_id;
    printf("Enter neighbour for %d, No neighbour enter 9999\n", node);
    scanf("%d", &neighbour_id);

    return neighbour_id;
}

static int32_t _get_neighbour_cost_(int32_t node) {
    int32_t edge_cost;
    printf("Enter the edge cost %d\n", node);
    scanf("%d", &edge_cost);

    return edge_cost;
}

Graph* graph_adjacency_list(Graph *g){
    int32_t i, neighbour_id;
    uint32_t edge_cost;
    Node *vertex, *lastNode;

    for(i = 0; i < g->size; ++i) {
        g->neighbours[i] = _make_node_(i);
        neighbour_id = _get_neighbour_id_(i);

        while(neighbour_id != 9999){
            vertex = _make_node_(neighbour_id);
            edge_cost = _get_neighbour_cost_(neighbour_id);
            vertex->cost = edge_cost;

            if(g->neighbours[i]->next == NULL) {
                g->neighbours[i]->next = vertex;
            } else {
                lastNode->next = vertex;
            }
            lastNode = vertex;
            neighbour_id = _get_neighbour_id_(i);
        }
    }
    return g;
}    


static void _dfs_(Graph *g, int32_t node) {
    visited[node] = TRUE;
    printf("%d\t", node);

    for (Node *vertex = g->neighbours[node]; vertex != NULL; vertex = vertex->next) {
        if (!visited[vertex->node_id]) {
               _dfs_(g, vertex->node_id);
        }
    }
}

Graph* graph_dfs(Graph *g, int32_t node) {
    for (int i = 0; i < MAX_NODES; ++i) {
        visited[i] = FALSE;
    }
    _dfs_(g, node);

    return g;
}

Graph* graph_bfs(Graph *g, int32_t node_id) {
    assert(g != NULL);
    Queue q1 = queue_new(MAX_NODES);
    Queue *q = &q1;
    QueueResult res;

    for (int i = 0; i < MAX_NODES; ++i) {
        visited[i] = FALSE; 
    }
    printf("\n");
    queue_add(q, g->neighbours[node_id], &res);
    while (!queue_empty(q)) {
        queue_delete(q, &res);
        Node *node = (Node*) res.data;
        for (Node *vertex = g->neighbours[node->node_id]; vertex != NULL; vertex = vertex->next) {
            if (!visited[vertex->node_id]){
                visited[vertex->node_id] = TRUE;
                printf("%d\t", vertex->node_id);
                queue_add(q, vertex, &res);
            }
        }
    }
    return g;
}
