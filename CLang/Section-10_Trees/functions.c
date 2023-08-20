#include "tree.h"
/**
 * create_new_node - create a new node
 * @value: value to store inside the node
 * Return: the address of the new node or NULL if failed
 */
node *create_new_node(const int value)
{
	node *new_node = malloc(sizeof(node));

	if (new_node == NULL)
		return (NULL);
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->val = value;

	return (new_node);
}
/**
 * insert_tree - insert in tree
 * @root: tree root
 * @value: value to store in the tree
 */
bool insert_tree(node **root, int value)
{
	node *new_node = create_new_node(value);
	node *current_node;

	if (!root || !new_node)
		return (false);
	if (!(*root))
	{
		*root = new_node;
		return (true);
	}
	current_node = *root;
	while (1)
	{
		if (new_node->val >= current_node->val)
		{
			/*Right Side*/
			if (current_node->right == NULL)
			{
				current_node->right = new_node;
				break;
			}
			current_node = current_node->right;
		}
		else
		{
			/*Left Side*/
			if (current_node->left == NULL)
			{
				current_node->left = new_node;
				break;
			}
			current_node = current_node->left;
		}
	}
	return (true);
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
/**
 * remove_node
 * @root: tree's root
 * @value: value to remove from tree
 * Return: true if success otherwise false
*/
bool remove_node(node **root, int value)
{
	node *current_node = NULL;
	node *parent_node = NULL;
	node *tmp = NULL;
	bool leaf = false;
	bool only_one_child = false;
	bool two_childrens = false;

	/*Check if the root doesnt exist*/
	 if (!root || !(*(root)))
	 	return (false);
	/*start with the root of the tree*/
	current_node = *root;
	while (current_node)
	{
		/*Check the value and traverse accordingly*/
		if (value > current_node->val)
		{
			parent_node = current_node;
			current_node = current_node->right;
			continue;
		}
		else if (value < current_node->val)
		{
			parent_node = current_node;
			current_node = current_node->left;
			continue;
		}
		else if (value == current_node->val)
		{
			/*All possiblities*/
			leaf = current_node->right == NULL && current_node->left == NULL;
			only_one_child = current_node->right != NULL && current_node->left == NULL || current_node->right == NULL && current_node->left != NULL;
			two_childrens = current_node->right != NULL && current_node->left != NULL;
			if (leaf)
			{
				if(parent_node->left->val == value)
				{
					parent_node->left = NULL;
				}
				else
				{
					parent_node->right = NULL;
				}
				free(current_node);
			}
			else if (only_one_child)
			{
				/*Right node of the parent*/
				if (parent_node && parent_node->right == current_node )
				{
					/*Right node of the current_node*/
					if (current_node->right != NULL)
					{
						parent_node->right = current_node->right;
						current_node->right = NULL;
					}
					/*Left node of the current node*/
					else
					{
						parent_node->right = current_node->left;
						current_node->left = NULL;
					}
						free(current_node);
				}
				/*Left node of the parent*/
				else if (parent_node && parent_node->left == current_node)
				{
					/*Right node of the current*/
					if (current_node->right != NULL)
					{
						parent_node->left = current_node->right;
						current_node->right = NULL;
					}
					/*Left node of the current*/
					else
					{
						parent_node->left = current_node->left;
						current_node->left = NULL;
					}
					free(current_node);
				}
				/*The root only has one child*/
				else
				{
					/*Right node of the current_node*/
					if (current_node->right != NULL)
					{
						*root = current_node->right;
						current_node->right = NULL;
					}
					/*Left node of the current node*/
					else if (current_node->left != NULL)
					{
						*root = current_node->left;
						current_node->left = NULL;
					}
						free(current_node);
				}
			}
			else if (two_childrens)
			{
				tmp = current_node->right;
				parent_node = current_node;
				while (tmp->left != NULL)
				{
						parent_node = tmp;
						tmp = tmp->left;
				}
				current_node->val = tmp->val;
				if (parent_node->right == tmp)
				{
					parent_node->right = NULL;
				}
				free(tmp);
			}
			break;
		}
		else
		{
			return (false);
		}
	}
	if (!current_node)
	{
		return (false);
	}
	return (true);
}