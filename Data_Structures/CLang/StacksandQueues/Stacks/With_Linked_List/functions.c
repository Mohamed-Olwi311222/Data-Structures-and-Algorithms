#include "stack.h"
static Std_Return_t create_new_node(node_t **node, const void *const data, const size_t data_size);
static Std_Return_t delete_node(node_t *node, void *const data, const size_t data_size);

size_t length = 0;
/**
 * @brief create a new newnode
 * @param node: the address to return the allocated node
 * @param data: pointer to the data
 * @param data_size: size of the data
 * @return: E_OK if success, E_NOT_OK if fail
 */
static Std_Return_t create_new_node(node_t **node, const void *const data, const size_t data_size)
{
    Std_Return_t ret_status = E_OK;

    if (NULL == node || NULL == data || data_size == 0)
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        *node = malloc(sizeof(node_t));
        if (NULL != *node)
        {
            (*node)->data = malloc(data_size);
            if (NULL != (*node)->data)
            {
                memcpy((*node)->data, data, data_size);
                (*node)->next = NULL;
            }
            else
            {
                free(*node);
                *node = NULL;
                ret_status = E_NOT_OK;
            }
        }
        else
        {
            ret_status = E_NOT_OK;
        }
    }
    return (ret_status);
}
/**
 * @brief Deletes a node
 * @param node: the address to return the data which was stored in the node
 * @param addr: The address to return the deleted node
 * @param data_size: The data size of the returned node
 * @return: E_OK if success, E_NOT_OK if fail
 */

 static Std_Return_t delete_node(node_t *node, void *const data, const size_t data_size)
{
  Std_Return_t ret_status = E_OK;

  if (NULL == node || NULL == data || data_size == 0)
  {
    ret_status = E_NOT_OK;
  }
  else
  {
      /* make a copy of the data to store into the node */
      memcpy(data, node->data, data_size);
      /* Clear the next pointer */
      node->next = NULL;
      /* free the allocated memory of the node */
      free(node->data);
      free(node);
  }
  return (ret_status);
}
/**
 * @brief: Check if stack is empty
 * @return: E_OK if stack is empty, E_NOT_OK if not empty
 */
Std_Return_t stack_is_empty(void)
{
    Std_Return_t ret_status = E_OK;

    if (0 != length)
    {
        ret_status = E_NOT_OK;
    }
    return (E_OK);
}
/**
 * @brief: Push the data to the stack to be the new top
 * @param stack: the stack to modify
 * @param data: pointer to the data
 * @param data_size: size of the data
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t push(stack_t *stack, const void *const data, const size_t data_size)
{
    Std_Return_t ret_status = E_OK;
    node_t *newnode = NULL;

    if (NULL == stack || NULL == data || data_size == 0)
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        /* Create a new node */
        ret_status = create_new_node(&newnode, data, data_size);
        if (E_OK == ret_status)
        {
            /* Make the newnode the new top */
            newnode->next = stack->top;
            stack->top = newnode;
            length++;
        }
    }
    return (ret_status);
}
/**
 * @brief: Pop the top of the stack and return its value
 * @param stack: the stack to modify
 * @param addr: The address to return the deleted top
 * @param data_size: The data size of the returned top
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t pop(stack_t *stack, void *const data, const size_t data_size)
{
  Std_Return_t ret_status = E_OK;
  node_t *temp = NULL;

  if (NULL == stack || NULL == data || data_size == 0)
  {
    ret_status = E_NOT_OK;
  }
  else
  {
      /* Copy the data to the returned address */
      temp = stack->top;
      stack->top = stack->top->next;
      ret_status = delete_node(temp, data, data_size);
      if (E_OK == ret_status)
      {
        length--;
      }
  }
  return (ret_status);
}
/**
 * @brief: Peak at the top of the stack and return its value
 * @param stack: the stack to peak at the top of it
 * @param addr: The address to return the peaked data
 * @param data_size: The data size of the returned data
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t peek(const stack_t *const stack, void *const addr, const size_t data_size)
{
  Std_Return_t ret_status = E_OK;

  if (NULL == stack || NULL == addr || data_size == 0)
  {
    ret_status = E_NOT_OK;
  }
  else
  {
      /* Copy the data to the returned address */
      memcpy(addr, stack->top->data, data_size);
  }
  return (ret_status);
}
/**
 * @brief: Print the whole stack and return its value
 * @param stack: the stack to print
 * @param print_data_type: The type of the stack data to print
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t printStack(const stack_t *const stack, void (*print_data_type)(void *))
{
    Std_Return_t ret_status = E_OK;
    node_t *current = NULL;

    if (NULL == stack || NULL == print_data_type)
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        current = stack->top;
        while (current)
        {
            print_data_type(current->data);
            printf("->");
            current = current->next;
        }
        printf("\n");
    }
    return (ret_status);
}
/**
 * @brief: Print int data type
 * @param data: The int data type to print
 */
void print_int(void *data)
{
    printf("%i", *((int *)data));
}
/**
 * @brief: Print String data type
 * @param data: The string data type to print
 */
void print_str(void *data)
{
    printf("%s", ((char *)data));
}
/**
 * @brief: Print char data type
 * @param data: The char data type to print
 */
void print_char(void *data)
{
    printf("%c", *((char *)data));
}
/**
 * @brief: Print float data type with .2 precision
 * @param data: The float data type to print
 */
void print_float(void *data)
{
    printf("%.2f", *((float *)data));
}
Std_Return_t infix_to_postfix(char *infix, size_t infix_arr_size)
{
    Std_Return_t ret_status = E_NOT_OK;
    uint8_t i = 0;

    if (NULL == infix || 0 == infix_arr_size)
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        for (; i < infix_arr_size; i++)
        {

        }
    }
    return (ret_status);
}