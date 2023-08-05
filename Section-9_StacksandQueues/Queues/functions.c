#include "queues.h"

size_t length = 0;

list_d *create_new_node(char *data)
{
  list_d *newnode = malloc(sizeof(list_d));
  if (newnode == NULL)
  {
    return (NULL);
  }
  newnode->data = strndup(data, strlen(data));
  newnode->next = NULL;
  newnode->prev = NULL;
}

