#include "stack.h"

size_t length = 0;
/**
* create_new_node - create a new newnode
* @data: string to put in the new newnode
* Return: a pointer to the newnode
*/
node *create_new_node(char *data)
{
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL)
  {
    return (NULL);
  }
  newnode->data = strndup(data, strlen(data));
  newnode->next = NULL;
  length++;
  return (newnode);
}
/**
* push - add an element to the stack
* @stack: stack to add the new element
* @data: data to put
*/
void push(stack *stack, char *data)
{
  node *newnode = create_new_node(data);
  if (stack->top == NULL)
  {
    stack->top = newnode;
    return;
  }
  newnode->next = stack->top;
  stack->top = newnode;
}
/**
* pop - remove the top from the stack
* @stack: stack to remove from it
*/
char *pop(stack *stack)
{
  node *top_node = stack->top;
  char *data;

  if (stack->top == NULL)
  {
    return (NULL);
  }
  data = strndup(top_node->data, strlen(top_node->data));
  if (data == NULL)
  {
    return (NULL);
  }
  stack->top = top_node->next;
  free(top_node);
  length--;
  return (data);
}
/**
 * peek - view the top of the stack
 * @stack: stack
 * Return: the data inside the top
 */
char *peek(stack *stack)
{
  char *data;

  if (stack == NULL || stack->top->data == NULL)
  {
    return (NULL);
  }
  data = strndup(stack->top->data, strlen(stack->top->data));
  if (data == NULL)
  {
    return (NULL);
  }
  data = stack->top->data;
  return (data);
}
/**
* printStack - print the stack
* @stack: stack to print
*/
void printStack(stack *stack)
{
  node *current = stack->top;
  if (!stack)
  {
    printf("Empty stack\n");
    return;
  }
  printf("Stack: ");
  while (current != NULL)
  {
    printf("%s ", current->data);
    current = current->next;
  }
  printf("\n");
}
