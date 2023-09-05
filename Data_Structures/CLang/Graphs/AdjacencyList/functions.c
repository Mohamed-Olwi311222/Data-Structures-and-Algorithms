#include "adj_list.h"

/**
 * create_new_node - creates a new node
 * @vertex: vertex to be added to the node
 * Return: pointer to the new node
*/
node *create_new_node(unsigned int vertex)
{
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL)
    {
        return (NULL);
    }
    newnode->next = NULL;
    newnode->vertex = vertex;
    return (newnode);
}

/**
 * create_graph - creates an adjacencylist graph
 * @vertices: number of vertices
 * Return: a pointer to the new graph
*/
adj_list *create_graph(unsigned int vertices)
{
    adj_list *g = malloc(sizeof(adj_list));
    int i;

    if (g == NULL)
    {
        return (NULL);
    }
    g->numvertices = vertices;
    g->heads = malloc(sizeof(node *) * vertices);
    if (g->heads == NULL)
    {
        return (NULL);
    }
    /*Intialize each head to NULL*/
    for (i = 0; i < vertices; i++)
    {
        g->heads[i] = NULL;
    }
    return (g);
}

/**
 * add_edge - adds an edge to the graph
 * @g: pointer to the graph
 * @src: source vertex
 * @dest: destination vertex
 * Return: true if successful, false otherwise
*/
bool add_edge(adj_list *g, unsigned int src, unsigned int dest)
{
    node *newnode = NULL;
    node * curr = NULL;

    if (g == NULL || g->heads == NULL || src > (g->numvertices - 1) || dest > (g->numvertices - 1))
    {
        return (false);
    }
    /*The current head is NULL*/
    if (g->heads[src] == NULL)
    {
        newnode = create_new_node(src);
        g->heads[src] = newnode;
    }
    /*Create the destination node in the linked list*/
    newnode = create_new_node(dest);
    curr = g->heads[src];
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = newnode;
   return (true); 
}

/**
 * destroy_graph - deallocate the allocated adjacecny list
 * @g: the graph to deallocate
*/
void destroy_graph(adj_list *g)
{
    node *curr = NULL, *next = NULL;
    int i;

    if (!g || g->heads == NULL)
    {
        return;
    }
    for (i = 0; i < g->numvertices; i++)
    {
        curr = g->heads[i];
        while (curr)
        {
            next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(g->heads);
    free(g);
}

/**
 * print_graph - prints the adjacencylist graph
 * @g: the graph to print
*/
void print_graph(adj_list *g)
{
    node * curr = NULL;
    int i;

    if (g == NULL || g->heads == NULL)
    {
        printf("The graph is NULL\n");
        return;
    }
    for (i = 0; i < g->numvertices; i++)
    {
        curr = g->heads[i];
        printf("Adjacency list of vetex %d: ", i);
        while (curr)
        {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}