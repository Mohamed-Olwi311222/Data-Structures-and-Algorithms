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
#include <string.h>
#include <stdbool.h>
/*--------------------------------------------Struct Section-----------------*/
#define NUM_CHARS 256

/**
 * trienode - struct for trie node
 * @children: will work as a Look up table for children
 * @terminal: to indicate the end of a word
*/
typedef struct trienode
{
	struct trienode *children[NUM_CHARS];
	bool terminal;
} trienode;
/*--------------------------------------------Function prototypes Section----*/
trienode *create_new_node(void);
bool trie_insert(trienode **root, char *text);
bool trie_search(trienode *root, char *word);
bool trie_starts_sith(trienode *root, char *prefix);
void trie_free(trienode* root);
/*--------------------------------------------End Section--------------------*/
#endif
