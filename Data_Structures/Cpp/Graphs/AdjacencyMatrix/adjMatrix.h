#ifndef ADJMATRIX_H
#define ADJMATRIX_H
/*----------------------Include Dirs-----------*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
/*----------------------Class-------------------*/

/**
 * @brief           Class for adjacency Matrix to represent the graph
*/
class Graph
{
public:
    /**
     * @brief       Constructor for the adjacency Matrix
     * 
     * @param[in]   vertices   number of vertices of the matrix
    */
    Graph(unsigned int vertices = 0);

    /**
     * @brief       Gets the number of vertices of the graph
     * 
     * @return      The number of vertices of the current graph
    */
    unsigned int get_number_of_vertices();
    
    /**
     * @brief       Gets the number of edges of the graph
     * 
     * @return      The number of edges of the current graph
    */
    unsigned int number_of_edges();

    /**
     * @brief       Generate random edges between each vertices
     * 
     * @param[in]   density the density of the graph
     * @param[in]   minDistance the minimum distance required
     * @param[in]   maxDistance the maximum distance required
    */
    void generateRandomEdges(double density, int minDistance, int maxDistance);

    /**
     * @brief       output the graph to stdout
    */
    void print_adj_matrix();
private:
    unsigned int vertices;
    vector<vector<unsigned int>> matrix;
};
#endif /*adjMatrix.h*/