#ifndef STACK_H
#define STACK_H
/*-------------------------Include Files----------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*-------------------------Global variables-------------------------------------*/
extern size_t length;
/*-------------------------Structs----------------------------------------------*/
typedef struct list
{
  char *data;
  struct list *next;
}node;
typedef struct stack
{
  node *top;
}stack;
/*-------------------------Function prototypes----------------------------------*/
node *create_new_node(char *data);
void push(stack *stack, char *data);
char *pop(stack *stack);
char *peek(stack *stack);
void printStack(stack *stack);
/*-------------------------End-------------------------------------------------*/
#endif /*STACK_H*/

