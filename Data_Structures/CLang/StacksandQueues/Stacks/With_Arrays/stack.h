#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*-------------------------Defines + Stack--------------------------------------*/
#define MAX_LENGTH 10
#define EMPTY (-1)
extern char *stack[MAX_LENGTH];
extern int top;
/*-------------------------Function prototypes----------------------------------*/
bool push(char *data);
char *pop(void);
char *peek(void);
void printStack(void);
void freeStack(void);
/*-------------------------End-------------------------------------------------*/
#endif /*STACK_H*/

