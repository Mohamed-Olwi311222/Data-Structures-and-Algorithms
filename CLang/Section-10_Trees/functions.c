#include "tree.h"
/**
 * create_new_node - create a new node
 * @value: value to store inside the node
 * Return: the address of the new node
 */
node *create_new_node(const int value)
{
	node *newnode = malloc(sizeof(node));

	if (newnode == NULL)
		return (NULL);
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->val = value;

	return (newnode);
}
/**
 * insert_tree - insert in tree
 * @root: tree root
 * @value: value to store in the tree
 */
void insert_tree(node **root, int value)
{
	node *newnode = create_new_node(value);
	node *currentnode;

	if (!root || !newnode)
		return;
	if (!(*root))
	{
		*root = newnode;
		return;
	}
	currentnode = *root;
	while (1)
	{
		if (newnode->val >= currentnode->val)
		{
			/*Right Side*/
			if (currentnode->right == NULL)
			{
				currentnode->right = newnode;
				break;
			}
			currentnode = currentnode->right;
		}
		else
		{
			/*Left Side*/
			if (currentnode->left == NULL)
			{
				currentnode->left = newnode;
				break;
			}
			currentnode = currentnode->left;
		}
	}
	}
/**
 * look_up_tree - look for a specific value
 * @root: tree's root to search in
 * @value: the value to look for
 * Return: true if success otherwise false
 */
bool look_up_tree(node *root, int value)
{
	bool found = false;

	while (root)
	{
		if (root->val <= value)
		{
			/*Right side*/
			if (root->val == value)
			{
				found = true;
				break;
			}
			root = root->right;
		}
		else
		{
			/*Left side*/
			if (root->val == value)
			{
				found = true;
				break;
			}
			root = root->left;
		}
	}
	return (found);
}
