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

  push(&stack, "Discord", 8 * sizeof(char));
  push(&stack, "Discord", 8 * sizeof(char));
  push(&stack, "Discord", 8 * sizeof(char));
  printStack(&stack, print_str);
  free_stack(&stack);

  char infix[] = "2 + ((8 + 2 * 3) / 2) - 1";
  uint8_t postif_len = 30;
  char *postfix = malloc(sizeof(char) * postif_len);
  infix_to_postfix(infix, 26, postfix, postif_len);
  printf("%s\n", infix);
  printf("%s\n", postfix);
  free(val);
  free(postfix);

  char postfix_expr[] = "53+82-*"; //(5 + 3) * (8 - 2) = 48
  int result = 0;

  evaluate_postfix(postfix_expr, &result);
  printf("%i\n", result);
}
