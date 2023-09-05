#include "trie.h"

/**
 * create_new_node - creates a new node and intializes its values
 * Return: a pointer to the new node
 */
trienode *create_new_node(void)
{
	trienode *newnode = malloc(sizeof(trienode));
	int i;

	if (newnode == NULL)
		return (NULL);

	for (i = 0; i < NUM_CHARS; i++)
		newnode->children[i] = NULL;
	newnode->terminal = false;
	return (newnode);
}

/**
 * trie_insert - insert at the trie
 * @root: root of the trie
 * Return: true if success otherwise false
*/
bool trie_insert(trienode **root, char *text)
{
	trienode *ptr = NULL;
	int length = strlen(text), i;
	unsigned char *unsignedtext = (unsigned *) text;

	if (*(root) == NULL)
	{
		*root = create_new_node();
	}
	ptr = *root;

	for (i = 0; i < length; i++)
	{
		if (ptr->children[unsignedtext[i]] == NULL)
		{
			/*Create a new node to store the current letter*/
			ptr->children[unsignedtext[i]] = create_new_node();
		}
		ptr = ptr->children[unsignedtext[i]];
	}
	if (ptr->terminal == true)
	{
		/*The text already exist*/
		return (false);
	}
	/*The text has been inserted in the trie*/
	ptr->terminal = true;
	return (true);
}

/**
 * trie_search - search in the trie
 * @root: root of the trie
 * @text: the text to search for
 * Return: true if found otherwise false
*/
bool trie_search(trienode *root, char *text)
{
	int length = strlen(text), i;
	unsigned char *text_u = (unsigned *) text;

	if (!root || !text)
	{
		return (false);
	}

	for (i = 0; i < length; i++)
	{
		if (root->children[text_u[i]] == NULL)
		{
			return (false);
		}
		root = root->children[text_u[i]];
	}

	if (root->terminal == false)
	{
		return (false);
	}	
		return (true);
}

/**
 * trie_starts_with - search for a prefix of a word
 * @root: root of the trie
 * @prefix: prefix to search for
 * Return: true if found otherwise false
*/
bool trie_starts_with(trienode *root, char *prefix)
{
	int length = strlen(prefix), i;
	unsigned char *prefix_u = (unsigned *) prefix;

	if (!root || !prefix)
	{
		return (false);
	}
	for (i = 0; i < length; i++)
	{
		if (root->children[prefix_u[i]] == NULL)
		{
			return (false);
		}
		root = root->children[prefix_u[i]];
	}
	return (true);
}

/**
 * remove_trie - remove a node from trie
 * @
*/
bool remove_trie()
{
	
}
/**
 * trie_free - free a trie
 * @root: root of the trie
*/
void trie_free(trienode* root)
{
	int i;

	if (root == NULL)
	{
		return;
	}
    
    for (i = 0; i < NUM_CHARS; ++i)
	{
		if (root->children[i] != NULL)
		{
			trie_free(root->children[i]);
		}
    }

    free(root);
}