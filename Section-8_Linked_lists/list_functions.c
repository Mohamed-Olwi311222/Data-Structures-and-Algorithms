#include "list.h"
/**
 * create_new_node - create a new node with value = value
 * @value: value to add
 * Return: a pointer to the new node
 */
list_t *create_new_node(int value)
{
    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
    {
        return (NULL);
    }

    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

/**
 * append - append a new node at the end of the list
 * @head: head of the list
 * @value: value to put in the now
 * Return: a pointer to the new node
 */
list_t *append(list_t **head, int value)
{
    list_t *ptr = *head;
    list_t *newnode = malloc(sizeof(list_t));

    if (!head || !newnode)
    {
        exit(1);
    }

    newnode->value = value;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    return (newnode);
}

/**
 * insert_at_head - insert a node at the head of the list
 * @head: head of the list
 * @node_to_insert: the node to insert at the beginning
 * Return: a pointer to the inserted node
 */
list_t *insert_at_head(list_t **head, list_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return (node_to_insert);
}

/**
 * find_node - find the node with the passed value
 * @head: head of the list
 * @value: the value to search for
 * Return: the found node
 */
list_t *find_node(list_t *head, int value)
{
    list_t *ptr = head;
    if (!head)
    {
        return (NULL);
    }

    while (ptr != NULL)
    {
        if (ptr->value == value)
            return (ptr);
        ptr = ptr->next;
    }
    return (NULL);
}

/**
 * print_list - print the given list
 * @head: head of the list
 * Return: the number of the members
 */
size_t print_list(const list_t *h)
{
	const list_t *node = h;
	size_t count = 0;

	if (h == NULL)
		return (0);
	while (node)
	{
		printf("%d - ", node->value);
		count++;
		node = node->next;
	}
    printf("\n");
	return (count);
}