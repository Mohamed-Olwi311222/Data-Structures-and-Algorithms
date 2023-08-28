#include "adj_matrix.h"

int main(void)
{
    graph *g = create_graph(5);

    print_graph(g);
    printf("\n\n\n");
    add_edge(g, 0, 0);
    add_edge(g, 0, 1);
    add_edge(g, 1, 0);
    add_edge(g, 1, 2);
    add_edge(g, 2, 1);
    print_graph(g);
    destroy_graph(g);
}