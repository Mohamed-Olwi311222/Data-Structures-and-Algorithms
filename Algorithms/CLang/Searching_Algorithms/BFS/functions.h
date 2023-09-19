#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/*--------------------------------------------Include Section----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
/*--------------------------------------------Struct Section-----------------*/
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
/**
 * node - struct for tree node
 * @val: value stored in node
 * @right: right side of the node
 * @left: left side of the node
*/
typedef struct node
{
	int val;
	struct node *right;
	struct node *left;
} node;
/*--------------------------------------------Function prototypes Section----*/
/*-----------------Tree--------------*/
node *create_new_node(const int value);
bool insert_tree(node **root, int value);
bool print_tree(const node *root);
bool look_up_tree(node *root, int value);
int remove_node(node **root, int value);
int BFS(node *root, int target);
static int BFSR(node *root, int target, queue *q);
int BFS_recursion(node *root, int target);
/*-----------------Queue-------------*/
void init_queue(queue *queue);
int free_queue(queue *q);
int enqueue(queue *q, node *tree_node);
node *dequeue(queue *q);
node *peek(queue *q);
/*--------------------------------------------End Section--------------------*/
#endif
