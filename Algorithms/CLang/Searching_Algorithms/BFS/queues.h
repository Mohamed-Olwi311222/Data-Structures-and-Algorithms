#ifndef QUEUES_H
#define QUEUES_H

/*-------------------------------------Include files-------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"
/*-------------------------------------Structs-------------------------------------------------------*/
typedef struct qnode
{
  struct node *node;
  struct qnode *next;
} qnode;
typedef struct queue
{
  qnode *first;
  qnode *last;
  int length;
} queue;
/*-------------------------------------Global varaible-----------------------------------------------*/
extern size_t length;
/*-------------------------------------functions prototypes------------------------------------------*/


void init_queue(queue *queue);
int enqueue(queue *q, node *tree_node);
node *dequeue(queue *q);
node *peek(queue *q);
/*-------------------------------------End-----------------------------------------------------------*/
#endif /*QUEUES_H*/
