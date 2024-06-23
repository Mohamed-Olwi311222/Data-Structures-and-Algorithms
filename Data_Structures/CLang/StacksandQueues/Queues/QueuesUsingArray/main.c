#include "queues.h"

int main(void)
{
  queue_t *q;
  uint8_t size = 3;
  void *ret_data;
  int i = 0;
  char *data[5] = {"Google", "Udemy", "Discord", "Hello", "CHAD"};
  STD_return_t ret = QUEUE_NOK;
  
  ret = init_queue(&q, size);
  printf("test for enqueue\n\n");
  for (i = 0; i < 3; i++)
  {
      ret = enqueue(&q, &(*data[i]));
      printf("enqueue ret = %i\n", ret);
  }

  ret = dequeue(&q, &ret_data);
  printf("%s ", ((char *)ret_data));
  
  ret = enqueue(&q, &(*data[i]));
  printf("enqueue ret = %i\n", ret);
  printf("\n\n\ntest for peek\n\n");
  ret = peek(&q, &ret_data);
  printf("%s\n", ((char *) ret_data));


  printf("\n\n\ntest for dequeue\n\n");
  while (q->count != 0)
  {
    ret = dequeue(&q, &ret_data);
    printf("%s ", ((char *)ret_data));
  }
  printf("\n");
  ret = enqueue(&q, &(*data[i + 1]));
  printf("enqueue ret = %i\n", ret);
  ret = dequeue(&q, &ret_data);
  printf("%s ", ((char *)ret_data));
  printf("\nlength: %i\n", q->count);
  ret = free_queue(&q);
}
