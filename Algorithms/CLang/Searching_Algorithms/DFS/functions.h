#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/*--------------------------------------------Include Section----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
/*--------------------------------------------Struct Section-----------------*/

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
/**
 * struct list - linked list
 * @next: pointer to the next snode
*/
typedef struct list
{
  node *tree_node;
  struct list *next;
}snode;
typedef struct stack
{
  int length;
  snode *top;
}stack;
/*--------------------------------------------Function prototypes Section----*/
/*-----------------Tree--------------*/
node *create_new_node(const int value);
bool insert_tree(node **root, int value);
bool print_tree(const node *root);
bool look_up_tree(node *root, int value);
int remove_node(node **root, int value);

int DFS_ordered(node *root);
static stack *inorder_DFS(node *root, stack *s);

int DFS_preordered(node *root);
static stack *preorder_DFS(node *root, stack *s);

int DFS_postordered(node *root);
static stack *postorder_DFS(node *root, stack *s);
/*-----------------Stack-------------*/
snode *create_new_snode(node *tree_node);
void push(stack *stack, node *tree_node);
node *pop(stack *stack);
node *peek(stack *stack);
void printStack(stack *stack);
void free_stack(stack *stack);
/*--------------------------------------------End Section--------------------*/
#endif
