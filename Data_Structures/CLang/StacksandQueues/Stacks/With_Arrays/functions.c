#include "stack.h"

char *stack[MAX_LENGTH] = {"NULL"};
static char *my_strndup(char *data, size_t len)
{
  char *temp = NULL;
  if (NULL != data)
  {
    temp = (char *)malloc((sizeof(char) * len) + 1);
    if (NULL != temp)
    {
      memcpy(temp, data, len);
      temp[len] = '\0';
    }
  }
  return (temp);
}
int top = EMPTY;
/**
 * push - push element to the stack
 * Return: true if success otherwise false
 */
bool push(char *data)
{
  if (top >= MAX_LENGTH - 1 )
  {
    return (false);
  }
  top++;
  stack[top] = my_strndup(data, strlen(data));
  return (true);
}

/**
 * pop - get the top value and delete it
 * Return: the top
 */
char *pop(void)
{
  if (top == EMPTY)
    return "NULL";
  char *result = my_strndup(stack[top], strlen(stack[top]));
  stack[top] = "NULL";
  top--;
  return (result);
}

/**
* peek - gets the top of the stack
* Return: the top value
*/
char *peek(void)
{
  if (top == EMPTY)
    return ("NULL");
  char *result = my_strndup(stack[top], strlen(stack[top]));
  return (result);
}

/**
* printStack - print the stack
*/
void printStack(void)
{
  int i;

  if (top == EMPTY)
  {
    printf("Stack is empty\n");
    return;
  }
  for (i = 0; i <= top; i++)
    printf("%s ", stack[i]);
  printf("\n");
}

/**
* freeStack - free the stack
*/
void freeStack(void)
{
  int i =0;

  while (stack[i] != "NULL")
  {
    free(stack[i]);
    i++;
  }
}
