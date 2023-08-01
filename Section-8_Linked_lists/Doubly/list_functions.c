#include "listd.h"

size_t length = 0;
/**
 * create_new_node - create a new node with value = value
 * @value: value to add
 * Return: a pointer to the new node
 */
list_d *create_new_node(int value)
{
    list_d *new_node = malloc(sizeof(list_d));
    if (!new_node)
    {
        exit(1);
    }
    length++;
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

/**
 * append - append a new node at the end of the list
 * @tail: tail of the list
 * @value: value to put in the now
 * Return: a pointer to the new node
 */
list_d *append(list_d **tail, int value)
{
    list_d *newnode = create_new_node(value);

    if (tail == NULL)
    {
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
  	    newnode->prev = *tail;
	      newnode->next = NULL;
        (*tail) = newnode;
    }
    return (newnode);
}
/**
 * traverseList_d - traverse the list
 * @h: head of the list
 * Return: a pointer to the end node
 */
list_d *traverseList_d(list_d *h)
{
	if (!h)
		return (NULL);
	while (h->next != NULL)
		h = h->next;
	return (h);
}

/**
 * insert_at_head - insert a node at the head of the list
 * @h: head of the list
 * @node_to_insert: the node to insert at the beginning
 * Return: a pointer to the inserted node
 */
list_d *insert_at_head(list_d **h, list_d *node_to_insert)
{
	if (!h || !node_to_insert)
		return (NULL);

	node_to_insert->next = *h;
	node_to_insert->prev = NULL;

	if ((*h) != NULL)
		(*h)->prev = node_to_insert;

	*h = node_to_insert;
	return (node_to_insert);
}

/**
 * find_node - find the node with the passed value
 * @h: head of the list
 * @value: the value to search for
 * Return: the found node
 */
list_d *find_node(list_d *h, int value)
{
    list_d *ptr = h;
    if (!h)
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
 * @h: head of the list
 * Return: the number of the members
 */
size_t print_list(const list_d *h)
{
	const list_d *node = h;
	size_t count = 0;

	if (h == NULL)
		return (0);
	while (node)
	{
		printf("%d <-> ", node->value);
		count++;
		node = node->next;
	}
    printf("\n");
	return (count);
}
/**
 * insert - insert at given index
 * @head: head of the list
 * @tail: tail of the list
 * @index: index to insert the new node
 * @value: value to put
 * Return: a pointer to the newnode
 */
list_d *insert(list_d **h, list_d **tail, size_t index, int value)
{
	list_d *newnode, *ptr = *h;
	int i = 0;

  if (index >= length)
  {
    return (append(tail, value));
  }
  newnode = create_new_node(value);
  if (!h)
		return (NULL);
	if (index == 0)
	{
		newnode->next = *h;
		*h = newnode;
	}
	else
	{
		while (ptr != NULL && i < index - 1)
		{
			ptr = ptr->next;
			i++;
		}
		if (ptr == NULL)
		{
			free(newnode);
			return (NULL);
		}
		newnode->next = ptr->next;
		ptr->next = newnode;
		newnode->prev = ptr;
		ptr = ptr->next;
		ptr->prev = newnode;
	}
	return (newnode);
}
/**
 * freeHead - free the head of the list
 * @h: head of the list
 */
void freeHead(list_d **h)
{
	list_d *ptr = *h;
	if (!h)
		return;
	*h = (*h)->next;
  (*h)->prev = NULL;
  length--;
	free(ptr);
}
/**
 * freeNode - remove a node from list
 * @h: head of the list
 * @tail: tail of the list
 * @index: index of the node to remove
 */
void freeNode(list_d **h, list_d **tail,size_t index)
{
	list_d *curr = *h, *next = NULL;
	size_t i = 0;

  if (index >= length)
    index = length - 1;
	if (!h)
		return;
	if (index == 0)
	{
	freeHead(h);
	return;
	}
	next = curr->next;
	while (i < index - 1 && next != NULL)
	{
		next = next->next;
		curr = curr->next;
		i++;
	}
	curr->next = next->next;
	free(next);
  *tail = curr;
  if (index != length - 1)
  {
    next = curr->next;
    next->prev = curr;
  }
  length--;
}
/**
 * freeList_d - free the whole list
 * @h: head of the list
 */
void freeList_d(list_d **h)
{
	list_d *node = *h;

	if (!h)
		return;
	while (*h != NULL)
	{
		*h = (*h)->next;
		free(node);
		node = *h;
    length--;
	}
}
/**
* reverseList - revere a doubly linked list
* @h: head of the list
* @tail: tail of the list
*/
void reverseList(list_d **h, list_d **tail)
{
  list_d *curr = *h, *next = NULL, *tmp;

  if(!h)
    return;
  while (curr != NULL)
  {
	next = curr->next;
	curr->next = curr->prev;
	curr->prev = next;
	curr = next;
  }
	tmp = *h;
	*h = *tail;
	*tail = tmp;
}
