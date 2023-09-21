#include "functions.h"

/**
* create_new_snode - create a new newnode
* @treee_node: tree node to store in the stack
* Return: a pointer to the new snode
*/
snode *create_new_snode(node *tree_node)
{
  snode *newnode = malloc(sizeof(snode));
  if (newnode == NULL)
  {
    return (NULL);
  }
  newnode->tree_node = tree_node;
  newnode->next = NULL;
  return (newnode);
}
/**
* push - add an element to the stack
* @stack: stack to add the new element
* @tree_node: tree_node to add to the stack
*/
void push(stack *stack, node *tree_node)
{
  snode *newnode = create_new_snode(tree_node);
  if (stack->top == NULL)
  {
    stack->top = newnode;
  }
  else
  {
    newnode->next = stack->top;
    stack->top = newnode;
  }
  stack->length++;
}
/**
* pop - remove the top from the stack
* @stack: stack to remove from it
*/
node *pop(stack *stack)
{
  node *tree_node;
  snode *top_node;

  if (stack->top == NULL || stack->length <= 0)
  {
    return (NULL);
  }
  top_node = stack->top;
  tree_node = top_node->tree_node;

  stack->top = top_node->next;
  free(top_node);
  stack->length--;
  return (tree_node);
}
/**
 * peek - view the top of the stack
 * @stack: stack
 * Return: the tree node inside the stack
 */
node *peek(stack *stack)
{
  node *tree_node;

  if (stack == NULL || stack->top->tree_node == NULL)
  {
    return (NULL);
  }
  tree_node = stack->top->tree_node;

  return (tree_node);
}
/**
* printStack - print the stack
* @stack: stack to print
*/
void printStack(stack *stack)
{
  snode *current = stack->top;
  if (!stack)
  {
    printf("Empty stack\n");
    return;
  }
  printf("Stack: ");
  while (current != NULL)
  {
    printf("%d ", current->tree_node->val);
    current = current->next;
  }
  printf("\n");
}
/**
 * free_Stack - free a stack
 * @stack: stack to free
*/
void free_stack(stack *stack)
{
   if (stack && stack->length <= 0)
    {
      return;
    }
    while(stack->length > 0)
    {
      pop(stack);
    } 
}
