#include "adj_matrix.h"
/**
 * create_graph - creates the adjacency matrix graph 
 * @numnodes: number of nodes inside it
 * Return: a pointer to the address of the new graph
*/
graph *create_graph(int numnodes)
{
    graph *g = malloc(sizeof(graph));
    int row;

    if (g == NULL)
    {
        return (NULL);
    }
    g->numnodes = numnodes;

   /*allocates the rows*/
    g->edges = calloc(sizeof(bool *), g->numnodes);
    if (g->edges == NULL)
    {
        free(g);
        return (NULL);
    }

    /*allocates the elements inside each row*/
    for (row = 0; row < g->numnodes; row++)
    {
            g->edges[row] = calloc(sizeof(bool), g->numnodes);
            if (g->edges[row] == NULL)
            {
                destroy_graph(g);
                return (NULL);
            }
    }
    return (g);
}
/**
 * destroy_graph - deallocates the allocated graph
 * @g: graph to deallocate
*/
void destroy_graph(graph *g)
{
    int row;

    if (g == NULL)
    {
        return;
    }
    else if (g->edges == NULL)
    {
        free(g);
        return;
    }
    /*Free each elements of the rows*/
    for (row = 0; row < g->numnodes; row++)
    {
        if (g->edges[row] != NULL)
        {
            free(g->edges[row]);
        }
    }
    /*Free the rows pointers and the struct itself*/
    free(g->edges);
    free(g);
}
/**
 * print_graph - print the elements of the graph
 * @g: graph to print
*/
void print_graph(graph *g)
{
    int from_node, to_node;

    if (g == NULL)
    {
        printf("Graph doesnt exits\n");
        return;
    }
    printf("digraph {\n");
    for (from_node = 0; from_node < g->numnodes; from_node++)
    {
        for (to_node = 0; to_node < g->numnodes; to_node++)
        {
            if (g->edges[from_node][to_node])
            {
                printf("%d -> %d;\n", from_node, to_node);
            }
        }
    }
    printf("}\n");
}
/**
 * has_edge - checks if the current edge isnt empty
 * @g: graph to check in it
 * @from_node: source node
 * @to_node: destination node
 * Return: true if exist
*/
bool has_edge(graph *g, int from_node, int to_node)
{
    if (!g || from_node > g->numnodes || to_node > g->numnodes )
    {
        return (false);
    }
    return (g->edges[from_node][to_node]);
}
/**
 * add_edge - add an edge in the graph
 * @g: graph to add the edge in
 * @from_node: source node
 * @to_node: destination node
 * Return: true if successfully added
*/
bool add_edge(graph *g, int from_node, int to_node)
{
    if (!g || from_node > g->numnodes || to_node > g->numnodes)
    {
        return (false);
    }
    /*to check if the edge currently exist*/
    if (has_edge(g, from_node, to_node))
    {
        return (false);
    }
    g->edges[from_node][to_node] = true;
    return (true);
}
/**
 * remove_edge - remove an edge from the graph
 * @g: graph to remove the edge from
 * @from_node: source node
 * @to_node: destination node
 * Return: true if successfully removed
*/
bool remove_edge(graph *g, int from_node, int to_node)
{
    if (!g || from_node > g->numnodes || to_node > g->numnodes)
    {
        return (false);
    }
    /*to check if the edge currently exist*/
    if (has_edge(g, from_node, to_node))
    {
        g->edges[from_node][to_node] = false;
        return (true);
    }
    return (false);
}