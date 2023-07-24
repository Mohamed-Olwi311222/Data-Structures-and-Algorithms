#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
    int length;
} list_t;
size_t print_list(const list_t *h);
list_t *append(list_t **head, int value);
list_t *insert_at_head(list_t **head, list_t *node_to_insert);
list_t *create_new_node(int value);
list_t *find_node(list_t *head, int value);
int main(void)
{
    list_t *head = NULL;
    list_t *tmp;
    tmp = create_new_node(10);
    insert_at_head(&head, tmp);
   
    tmp = create_new_node(20);
    insert_at_head(&head, tmp);
    tmp = append(&head, 30);
    tmp = append(&head, 40);
    tmp = append(&head, 50);
    tmp = append(&head, 60);
    tmp = append(&head, 70);
    list_t *what = find_node(head, 30);
    size_t count = print_list(head);
}





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

list_t *insert_at_head(list_t **head, list_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return (node_to_insert);
}
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