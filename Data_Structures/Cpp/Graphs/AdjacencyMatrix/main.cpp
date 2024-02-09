#include "adjMatrix.h"


int main(void)
{
    Graph g(5);
    g.generateRandomEdges(1, 1, 5);
    g.print_adj_matrix();
    cout << g.number_of_edges() << endl;
    cout << g.get_number_of_vertices() << endl;
}