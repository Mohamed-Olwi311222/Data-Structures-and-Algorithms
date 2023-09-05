#include "adj_list.h"

int main(void)
{
    int numVertices = 2;
    adj_list* graph = create_graph(numVertices);
    
    add_edge(graph, 0, 0);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 1);
    add_edge(graph, 1, 0);
    print_graph(graph);
    destroy_graph(graph);
    /**
Adjacency list of vetex 0: 0 -> 1 -> 4 ->
Adjacency list of vetex 1: 1 -> 2 -> 3 -> 4 ->
Adjacency list of vetex 2: 2 -> 3 ->
Adjacency list of vetex 3: 3 -> 4 ->
    */
}