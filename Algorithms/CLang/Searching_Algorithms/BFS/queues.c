#include "queues.h"
//i love sama so muchh:hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh

/**
* create_new_qnode - create a new qnode
* @tree_node: tree_node to insert
* Return: a pointer to the new qnode
*/
static qnode *create_new_qnode(node *tree_node)
{
  qnode *newnode = malloc(sizeof(qnode));
  if (newnode == NULL)
  {
    return (NULL);
  }
  newnode->node = tree_node;
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
  queue->length = 0;
}

/**
 * enqueue - add a node to the last of the queue
 * @q: queue given
 * @tree_node: tree_node to be put in the node
 * Return: 1 if success otherwise negative value
*/
int enqueue(queue *q, node *tree_node)
{
  qnode *qnode;

  if (q == NULL)
    return (-1);
  qnode = create_new_qnode(tree_node);

  /* if there exist a node make it points to the newnode 
  * and then make the q->last pointer points to the new last
  */
  if (q->last != NULL)
  {
    q->last->next = qnode;
  }
  q->last = qnode;
  
  /*if the first pointer is NULL make it points to the newnode*/
  if (q->first == NULL)
  {
    q->first = qnode;
  }
  q->length++;
  return (1);
}

/**
* dequeue - remove the first element entered the queue
* @q: queue given
* Return: the tree_node inside the node
*/
node *dequeue(queue *q)
{
  node *tree_node;

  if (q == NULL || q->first == NULL)
    return (NULL);

  /*save the tree_node to return*/
  tree_node = q->first->node;
  
  /* update the first node at the queue
   * if the new address in empty then
   * there was only one element in the queue
   * and make the last pointer points to NULL
   */
  q->first = q->first->next;
  
  if (q->first == NULL)
    q->last = NULL;
  q->length--;
  return (tree_node);
}

/**
* peek - gets the first element entered the queue
* @q: queue given
* Return: the tree_node inside the node
*/
node *peek(queue *q)
{
  qnode *ptr;
  node *curr;

  if (q == NULL)
    return (NULL);

  /*save the tree_node to return*/
  ptr = q->first;
  curr = ptr->node;
  return (curr);
}
