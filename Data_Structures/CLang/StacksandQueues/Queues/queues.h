#ifndef QUEUES_H
#define QUEUES_H

/*-------------------------------------Include files-------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*-------------------------------------Structs-------------------------------------------------------*/
typedef struct list
{
  char *data;
  struct list *next;
} list_t;
typedef struct queue
{
  list_t *first;
  list_t *last;
} queue;
/*-------------------------------------Global varaible-----------------------------------------------*/
extern size_t length;
/*-------------------------------------functions prototypes------------------------------------------*/
list_t *create_new_node(char *data);
void init_queue(queue *queue);
bool enqueue(queue *q, char *data);
char *dequeue(queue *q);
char *peek(queue *q);
/*-------------------------------------End-----------------------------------------------------------*/
#endif /*QUEUES_H*/
