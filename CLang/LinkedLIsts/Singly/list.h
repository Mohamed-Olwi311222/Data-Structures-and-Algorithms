#ifndef LIST_H
#define LIST_H
/*-----------------Header files------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-----------------Structs-----------------------------------------------------*/
typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} list_t;
/*-----------------Global Variables--------------------------------------------*/
extern size_t length;
/*-----------------Function prototypes-----------------------------------------*/
size_t print_list(const list_t *h);
list_t *traverseList(list_t *h);
list_t *append(list_t **tail, int value);
list_t *insert_at_head(list_t **head, list_t *node_to_insert);
list_t *create_new_node(int value);
list_t *find_node(list_t *head, int value);
list_t *insert(list_t **h, list_t**tail, size_t index, int value);
void freeHead(list_t **h);
void freeNode(list_t **h, size_t index);
void freeList_t(list_t **h);
void reverseList(list_t **h, list_t **tail);
#endif
