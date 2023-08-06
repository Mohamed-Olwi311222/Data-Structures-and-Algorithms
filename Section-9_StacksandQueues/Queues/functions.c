#include "queues.h"
//i love sama so muchhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
size_t length = 0;
/**
* create_new_node - create a new newnode
* @data: data to insert
* Return: a pointer to the new node
*/
list_t *create_new_node(char *data)
{
  list_t *newnode = malloc(sizeof(list_t));
  if (newnode == NULL)
  {
    return (NULL);
  }
  length++;
  newnode->data = strndup(data, strlen(data));
  newnode->next = NULL;
  return (newnode);
}

/**
  * init_queue - initialze the queue
  * @queue: queue to initialze
  */
void init_queue(queue *queue)
{
  queue->first = NULL;
  queue->last = NULL;
}

/**
 * enqueue - add a node to the last of the queue
 * @q: queue given
 * @data: data to be put in the node
*/
bool enqueue(queue *q, char *data)
{
  list_t *node;

  if (q == NULL)
    return (false);
  node = create_new_node(data);

  /* if there exist a node make it points to the newnode 
  * and then make the q->last pointer points to the new last
  */
  if (q->last != NULL)
  {
    q->last->next = node;
  }
  q->last = node;
  
  /*if the first pointer is NULL make it points to the newnode*/
  if (q->first == NULL)
  {
    q->first = node;
  }
  return (true);
}

/**
* dequeue - remove the first element entered the queue
* @q: queue given
* Return: the data inside the node
*/
char *dequeue(queue *q)
{
  list_t *ptr;
  char *data;

  if (q == NULL)
    return (NULL);

  /*save the data to return*/
  ptr = q->first;
  data = strndup(ptr->data, strlen(ptr->data));
  
  /* update the first node at the queue
   * if the new address in empty then
   * there was only one element in the queue
   * and make the last pointer points to NULL
   */
  q->first = q->first->next;
  if (q->first == NULL)
    q->last = NULL;
  free(ptr->data);
  free(ptr);
  length--;
  return (data);
}

/**
* peek - gets the first element entered the queue
* @q: queue given
* Return: the data inside the node
*/
char *peek(queue *q)
{
  list_t *ptr;
  char *data;

  if (q == NULL)
    return (NULL);

  /*save the data to return*/
  ptr = q->first;
  data = strndup(ptr->data, strlen(ptr->data));
  return (data);;
}
