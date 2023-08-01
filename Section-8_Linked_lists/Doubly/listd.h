#ifndef LISTD_H
#define LISTD_H
/*-----------------Header files------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-----------------Structs-----------------------------------------------------*/
typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
    struct LinkedList *prev;
} list_d;
/*-----------------Function prototypes-----------------------------------------*/
size_t print_list(const list_d *h);
list_d *append(list_d **tail, int value);
list_d *insert_at_head(list_d **head, list_d *node_to_insert);
list_d *create_new_node(int value);
list_d *find_node(list_d *head, int value);
list_d *insert(list_d **h, list_d **tail, size_t index, int value);
void freeHead(list_d **h);
void freeNode(list_d **h, list_d **tail,size_t index);
void freeList_d(list_d **h);
list_d *traverseList_d(list_d *h);
void reverseList(list_d **h, list_d **tail);
#endif
