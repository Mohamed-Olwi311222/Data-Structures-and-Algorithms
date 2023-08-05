#ifndef QUEUES_H
#define QUEUES_H

/*-------------------------------------Include files-------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-------------------------------------Structs-------------------------------------------------------*/
typedef struct list
{
  char *data;
  struct list *next;
  struct list *prev;
} list_d;
typdef struct queue
{
  list_d *first;
  list_d *last;
} queue;
/*-------------------------------------Global varaible-----------------------------------------------*/
extern size_t length;
/*-------------------------------------functions prototypes------------------------------------------*/

/*-------------------------------------End-----------------------------------------------------------*/
#endif /*QUEUES_H*/
