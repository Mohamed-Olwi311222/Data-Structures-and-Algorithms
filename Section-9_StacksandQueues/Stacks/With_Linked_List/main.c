#include "stack.h"

int main(void)
{
  stack stack;
  stack.top = NULL;

  printf("\n\n\nprintStack before push\n");
  printStack(&stack);
  printf("\nlength: %lu\n", length);

  push(&stack, "Google");
  push(&stack, "Udemy");
  push(&stack, "Discord");
  printf("\n\n\nprintStack function after push\n");
  printStack(&stack);
  printf("\nlength: %lu\n", length);





  printf("\n\n\npeek test:\n");
  printf("%s ", peek(&stack));

  printf("\n\n\nFor loop to test pop: \n");
  while (length != 0)
  {
    printf("%s ", pop(&stack));
  }

  printf("\n\n\nprintStack after popping\n");
  printStack(&stack);
  printf("\nLength: %lu\n", length);
  printf("\n");

}
