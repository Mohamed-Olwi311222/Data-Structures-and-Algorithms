#include "adjMatrix.h"

Graph:: Graph(unsigned int vertices)
{
    matrix.resize(vertices, vector<unsigned int>(vertices));
    this->vertices = vertices;
}

unsigned int Graph::get_number_of_vertices()
{
    return (this->vertices);
}

unsigned int Graph::number_of_edges()
{
    unsigned int num_of_edges = 0;

    /*Calculate the number of edges*/
    for (int row = 0; row < vertices; row++)
    {
        for (int col = row + 1; col < vertices; col++)
        {
            if (matrix[row][col] > 0)
            {
                num_of_edges++;
            }
        }
    }
    return (num_of_edges);
}

void Graph::print_adj_matrix()
{
    /*print the upper row*/
    cout << "\t";
    for (int row = 0; row < vertices; row++)
    {
        cout << row << "\t";
    }
    cout << "\n";
    /*print each col with its vertices and edges*/
    for (int row = 0; row < vertices; row++)
    {
        cout << row << "\t";
        for (int col = 0; col < vertices; col++)
        {
            cout << matrix[row][col] << "\t";
        }
        cout << "\n";
    }
}
void Graph::generateRandomEdges(double density, int minDistance, int maxDistance)
{
    srand(time(0));     /*seed the random number generator with time*/
    for (int row = 0; row < vertices; row++)
    {
        for (int col = row + 1; col < vertices; col++)
        {
            double prob = (double)rand() / RAND_MAX; /*Generate a random number between 0 and 1*/
            if (prob < density)
            {
                int distance = rand() % (maxDistance - minDistance + 1) + minDistance; /*Generate a random distance between minDistance and maxDistance*/
                /*undirected graph*/
                matrix[row][col] = distance;
                matrix[col][row] = distance;
            }
        }
    }
}
