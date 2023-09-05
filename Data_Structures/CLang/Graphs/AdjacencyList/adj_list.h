#ifndef ADJLIST_H
#define ADJLIST_H

/*------------------------Include Files-----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*------------------------Structs-----------------------------------*/
typedef struct node
{
    int vertex;
    struct node *next;
} node;
typedef struct adj_list
{
    int numvertices;
    struct node **heads;
} adj_list;
/*------------------------Functions Prototypes----------------------*/
node *create_new_node(unsigned int vertex);
adj_list *create_graph(unsigned int vertices);
bool add_edge(adj_list *g, unsigned int src, unsigned int dest);
void destroy_graph(adj_list *g);
void print_graph(adj_list *g);
/*------------------------End File----------------------------------*/
#endif