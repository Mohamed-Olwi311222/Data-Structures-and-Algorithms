#ifndef TREE_H
#define TREE_H
/*--------------------------------------------Include Section----------------*/
#include <stdio.h>
#include <stdlib.h>

#ifdef __UNIX__ 
#include <unistd.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

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
/*--------------------------------------------Function prototypes Section----*/
node *create_new_node(const int value);
bool insert_tree(node **root, int value);
bool print_tree(const node *root);
bool look_up_tree(node *root, int value);
bool remove_node(node **root, int value);
/*--------------------------------------------End Section--------------------*/
#endif
