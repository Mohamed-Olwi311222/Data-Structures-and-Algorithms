#include "queues.h"

int main(void)
{
  queue q;
  init_queue(&q);
  printf("test for enqueue\n\n");
  printf("length: %lu\n", length);
  enqueue(&q, "Google");
  printf("length: %lu\n", length);
  enqueue(&q, "Udemy");
  printf("length: %lu\n", length);
  enqueue(&q, "Discord");
  printf("length: %lu\n", length);


  printf("\n\n\ntest for peek\n\n");
  printf("%s\n",peek(&q));


  printf("\n\n\ntest for dequeue\n\n");
  while (length != 0)
  {
    printf("%s ", dequeue(&q));
  }
  printf("\nlength: %lu\n", length);

}
