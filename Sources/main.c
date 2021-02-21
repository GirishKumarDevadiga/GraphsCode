#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "../Headers/graph.h"

void test_graph() {
    Graph g1 = graph_new(4);
    Graph *g = &g1;

    g = graph_adjacency_list(g);
}

int main() {
    test_graph();
    
    return 0;
}