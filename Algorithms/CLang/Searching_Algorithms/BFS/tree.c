#include "functions.h"
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
			if (temp_parent->left == temp)
				temp_parent->left = NULL;
			else
				temp_parent->right = NULL;
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
				if (temp_parent->left == temp)
					temp_parent->left = NULL;
				else
					temp_parent->right = NULL;
				free(temp);
			}
			return (0);
		}
	}
		return (-1);
}
/**
 * BFS - breadth search through a tree
 * @root: root of the tree
 * @target: target value
 * Return: 0 if found otherwise -1
*/
int BFS(node *root, int target)
{
	node *curr = NULL;
	queue q;

	if (root == NULL)
	{
		return (-1);
	}
	curr = root;

	init_queue(&q);
	enqueue(&q, curr);
	while (q.length >= 0)
	{
		curr = dequeue(&q);
		if (curr && curr->val == target)
		{
			free_queue(&q);
			return (0);
		}
		if (curr)
		{
			if (curr->left != NULL)
			{
				enqueue(&q, curr->left);
			}
			if (curr->right != NULL)
			{
				enqueue(&q, curr->right);
			}
		}
		else
		{
			free_queue(&q);
			return (-2);
		}
	}

	free_queue(&q);
	return (-2);
}
/**
 * BFS_recursion - BFS through a tree using recursion
 * @root: root of the tree to search in
 * @target: target value to search for
 * Return: 0 if found otherwise -1
*/
int BFS_recursion(node *root, int target)
{
	queue q;
	int res = 0;

	if (root == NULL)
	{
		return (-1);
	}
	init_queue(&q);

	enqueue(&q, root);
	res = BFSR(root, target, &q);

	free_queue(&q);
	return (res);
}
/**
 * BFSR - helper functions of BFS_recursion
 * @root: root of the tree to seach in
 * @q: queue to use it in BFS
 * Return: return 0 if found otherwise -1
*/
static int BFSR(node *root, int target, queue *q)
{
	if (q->length <= 0)
	{
		return (-1);
	}
	node *curr = dequeue(q);
	if (curr && curr->val == target)
	{
		return (0);
	}
	if (curr)
	{
		if (curr->left != NULL)
		{
			enqueue(q, curr->left);
		}
		if (curr->right != NULL)
		{
			enqueue(q, curr->right);
		}
	}
	return (BFSR(root, target, q));
}