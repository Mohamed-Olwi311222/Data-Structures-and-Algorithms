#include "stack.h"

int main(void)
{
  stack_t stack;
  stack.top = NULL;
  char *val = malloc(sizeof(char) * 8);

  push(&stack, "Google", 7 * sizeof(char));
  push(&stack, "Discord", 8 * sizeof(char));
  
  printf("%s\n", (char *)stack.top->data);           // Output: Discord
  printf("%s\n", (char *)stack.top->next->data);     // Output: Google
  pop(&stack, val, 8);
  printf("%s\n", (char *)stack.top->data);           // Output: Google
  printf("%s\n", val);                               // Output: Discord

  push(&stack, "AceMido", 8 * sizeof(char));
  peek(&stack, val, sizeof(char) * 8);
  printStack(&stack, print_str);
  printf("%s\n", (char *)stack.top->data);           // Output: AceMido
  printf("%s\n", val);                               // Output: AceMido

}
