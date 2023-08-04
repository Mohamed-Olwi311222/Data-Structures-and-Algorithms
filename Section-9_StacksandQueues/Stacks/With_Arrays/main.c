#include "stack.h"

int main(void)
{

  printf("\n\n\nprintStack before push\n");
  printStack();
  printf("\nlength: %d\n", top);

  push("Google");
  push("Udemy");
  push("Discord");
  printf("\n\n\nprintStack function after push\n");
  printStack();
  printf("\nlength: %d\n", top);





  printf("\n\n\npeek test:\n");
  printf("%s ", peek());

  printf("\n\n\nFor loop to test pop: \n");
  while (top != -1)
  {
    printf("%s ", pop());
  }

  printf("\n\n\nprintStack after popping\n");
  printStack();
  printf("\nLength: %d\n", top);
  printf("\n");

  printf("\n\n\nfreeStack\n");
  freeStack();
  printStack();
}
