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
 * Return: 0 if sucess otherwise negative val(-1 if root is null)
 */
int insert_tree(node **root, int value)
{
	node *new_node = create_new_node(value);
	node *current_node;
  int stats = -1;

	if (!root || !new_node)
		return (stats);
	if (!(*root))
	{
    stats = 0;
		*root = new_node;
		return (stats);
	}
	current_node = *root;
  stats = -2;
	while (1)
	{
		if (new_node->val >= current_node->val)
		{
			/*Right Side*/
			if (current_node->right == NULL)
			{
        stats = 0;
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
        stats = 0;
				current_node->left = new_node;
				break;
			}
			current_node = current_node->left;
		}
	}
	return (stats);
	}
/**
 * look_up_tree - look for a specific value
 * @root: tree's root to search in
 * @value: the value to look for
 * Return: 0 if success otherwise -1 
 */
int look_up_tree(node *root, int value)
{
	int found = -1;

	while (root)
	{
    /*Val found*/
    if (root->val == value)
		{
			found = 0; 
			break;
		}
		if (root->val < value)
		{
			/*Right side*/
			root = root->right;
		}
		else
		{
			/*Left side*/
			root = root->left;
		}
	}
	return (found);
}
/**
 * remove_node
 * @root: tree's root
 * @value: value to remove from tree
 * Return: 0 if success otherwise negative value
*/
int remove_node(node **root, int value)
{
	node *parent = NULL, *child = NULL, *temp = NULL, *temp_parent = NULL;

	if (!root || !(*root))
		return (-1);
	child = *root;
	/*Root*/
	if (child->val == value)
	{
		/*The node has no children*/
		if (child->left == NULL && child->right == NULL)
		{
			free(child);
			*root = NULL;
		}
		/*The node or root has one child */
		else if ((child->left && !child->right) || (child->right && !child->left))
		{
			if (child->left)
				*root = child->left;
			else
				*root = child->right;
			free(child);
		}
		/*The node has two children*/
		else
		{
			temp = child->right;
			temp_parent = child;
			while (temp->left)
			{
				temp_parent = temp;
				temp = temp->left;
			}
			child->val = temp->val;
			temp_parent->left = NULL;
			free(temp);
		}
		return (0);
	}
	while (child)
	{
		/*The target value is on the left (smaller than the parent)*/
		if (value > child->val)
		{
			parent = child;
			child = parent->right;
		}
		/*The target value is on the right (bigger than the parent)*/
		else if (value < child->val)
		{
			parent = child;
			child = parent->left;
		}
		/*value is found*/
		else
		{
			/*The node has no children*/
			if (child->left == NULL && child->right == NULL)
			{
				if (parent->left == child)
					parent->left = NULL;
				else
					parent->right = NULL;
				free(child);
			}
			/*The node or root has one child */
			else if ((child->left && !child->right) || (child->right && !child->left))
			{
				if (parent->left == child)
				{
					if (child->left)
						parent->left = child->left;
					else
						parent->left = child->right;
				}
				else
				{
					if (child->left)
						parent->right = child->left;
					else
						parent->right = child->right;
				}
				free(child);
			}
			/*The node has two children*/
			else
			{
				temp = child->right;
				temp_parent = child;
				while (temp->left)
				{
					temp_parent = temp;
					temp = temp->left;
				}
				child->val = temp->val;
				temp_parent->left = NULL;
				free(temp);
			}
			return (0);
		}
	}
		return (-1);
}
