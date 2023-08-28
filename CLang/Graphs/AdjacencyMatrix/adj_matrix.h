#ifndef ADJMATRIX_H
#define ADJMARIX_H
/*--------------------------------Include Files-------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
/*--------------------------------Structs-------------------------------------*/
typedef struct mygraph
{
    int numnodes;
    bool **edges;
} graph;
/*--------------------------------Functions Prototypes------------------------*/
graph *create_graph(int numnodes);
bool has_edge(graph *g, int from_node, int to_node);
bool add_edge(graph *g, int from_node, int to_node);
bool remove_edge(graph *g, int from_node, int to_node);
void print_graph(graph *g);
void destroy_graph(graph *g);
/*--------------------------------End files-----------------------------------*/

#endif