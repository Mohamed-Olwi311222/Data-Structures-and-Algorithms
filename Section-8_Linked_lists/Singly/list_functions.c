#include "list.h"

size_t length = 0;

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
    length++;
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

/**
 * append - append a new node at the end of the list
 * @tail: tail of the list
 * @value: value to put in the now
 * Return: a pointer to the new node
 */
list_t *append(list_t **tail, int value)
{
    list_t *newnode = create_new_node(value), *ptr = *tail;

    if (!tail || !newnode)
    {
        exit(1);
    }
    ptr->next = newnode;
    *tail = newnode;
    return (newnode);
}

/**
 * insert_at_head - insert a node at the head of the list
 * @h: head of the list
 * @node_to_insert: the node to insert at the beginning
 * Return: a pointer to the inserted node
 */
list_t *insert_at_head(list_t **h, list_t *node_to_insert)
{
    node_to_insert->next = *h;
    *h = node_to_insert;
    return (node_to_insert);
}

/**
 * find_node - find the node with the passed value
 * @h: head of the list
 * @value: the value to search for
 * Return: the found node
 */
list_t *find_node(list_t *h, int value)
{
    list_t *ptr = h;
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

/**
 * traverseList - traverse the list to the end
 * @h: head of the list
 * Return: the tail of the list
 */
list_t *traverseList(list_t *h)
{
  list_t *ptr = h;

  if (!h)
    return (NULL);

  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }

  return (ptr);
}
/**
 * insert - insert at given index
 * @head: head of the list
 * @tail: tail of the list
 * @index: index to insert the new node
 * @value: value to put
 * Return: a pointer to the newnode
 */
list_t *insert(list_t **h, list_t **tail,size_t index, int value)
{
	list_t *newnode, *ptr = *h;
	int i = 0;

	if (!h)
		return (NULL);
  if (index >= length)
  {
    return (append(tail, value));
  }
  newnode = create_new_node(value);
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
	}
	return (newnode);
}
/**
 * freeHead - free the head of the list
 * @h: head of the list
 */
void freeHead(list_t **h)
{
	list_t *ptr = *h;

	if (!h)
		return;
	*h = (*h)->next;
  length--;
	free(ptr);
}
/**
 * freeNode - remove a node from list
 * @h: head of the list
 * @index: index of the node to remove
 */
void freeNode(list_t **h, size_t index)
{
	list_t *curr = *h, *next = NULL;
	size_t i = 0;

	if (!h)
		return;
	if (index == 0)
	{
	  freeHead(h);
	  return;
	}
  else if (index >= length)
  {
    index = length - 1;
  }

	next = curr->next;
	while (i < index - 1 && next->next != NULL)
	{
		next = next->next;
		curr = curr->next;
		i++;
	}
	curr->next = next->next;
	free(next);
  length--;
}
/**
 * freeList - free the whole list
 * @h: head of the list
 */
void freeList_t(list_t **h)
{
	list_t *node = *h;

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
* reverseList - reverse singly linked list
* @h: head of the list
* @tail: tail of the list
*/
void reverseList(list_t **h, list_t **tail)
{
  list_t *prev = *h, *curr = (*h)->next;
  list_t *next = curr->next;
  if (!h || !curr)
    return;
  *tail = *h;
  prev->next = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *h = prev;
}
