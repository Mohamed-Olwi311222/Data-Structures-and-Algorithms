#include "stack.h"

static Std_Return_t create_new_node(node_t **node, const void *const data, const uint8_t data_size);
static Std_Return_t delete_node(node_t *node, void *const data, const uint8_t data_size);
static uint8_t check_operator_precedence(char c); 
static inline Std_Return_t is_operator(char c);
static int perform_operation(int operand1, int operand2, char operator);

Std_Return_t init_stack(stack_t *stack)
{
    Std_Return_t ret_status = E_OK;

    stack->length = 0;
    stack->top = NULL;

    return (ret_status);
}
/**
 * @brief create a new newnode
 * @param node: the address to return the allocated node
 * @param data: pointer to the data
 * @param data_size: size of the data
 * @return: E_OK if success, E_NOT_OK if fail
 */
static Std_Return_t create_new_node(node_t **node, const void *const data, const uint8_t data_size)
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

 static Std_Return_t delete_node(node_t *node, void *const data, const uint8_t data_size)
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
 * @param stack The stack to check
 * @return: E_OK if stack is empty, E_NOT_OK if not empty
 */
Std_Return_t stack_is_empty(const stack_t *const stack)
{
    Std_Return_t ret_status = E_OK;

    if (0 != stack->length)
    {
        ret_status = E_NOT_OK;
    }
    return (ret_status);
}
/**
 * @brief: Push the data to the stack to be the new top
 * @param stack: the stack to modify
 * @param data: pointer to the data
 * @param data_size: size of the data
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t push(stack_t *stack, const void *const data, const uint8_t data_size)
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
            stack->length++;
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
Std_Return_t pop(stack_t *stack, void *const data, const uint8_t data_size)
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
        stack->length--;
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
Std_Return_t peek(const stack_t *const stack, void *const addr, const uint8_t data_size)
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
 * @brief: Deallocate the whole stack and its content
 * @param stack the stack to deallocate
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t free_stack(stack_t *const stack)
{
    Std_Return_t ret_status = E_OK;
    node_t *current = NULL;

    if (NULL == stack)
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        current = stack->top;
        while (current)
        {
            stack->top = current->next;
            /* Free the node data */
            free(current->data);
            /* Free the node iself */
            free(current);
            current = stack->top;
        }
        stack->length = 0;
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
/**
 * @brief: Check if the character given is an operator
 * @param c the character to check
 * @return: Return E_OK if it is an operator otherwise E_NOT_OK
 */
static inline Std_Return_t is_operator(char c)
{
    Std_Return_t ret_status = E_OK;

    switch (c)
    {
        /* If any operator exist, return E_OK */
        case '(':
        case ')':
        case '*':
        case '/':
        case '+':
        case '-':
            ret_status = E_OK;
            break;
        /* not an operator, return E_NOT_OK */
        default:
            ret_status = E_NOT_OK;
            break;
    }
    return (ret_status);
}
/**
 * @brief: Check operator precedence
 * @param c The operator to check
 * @return The precedence number
 */
static uint8_t check_operator_precedence(char c) 
{
    switch (c) 
    {
        case '^': 
            return 0;

        case '*':
        case '/': 
            return 1;

        case '+':
        case '-': 
            return 2;

        default:  
            return 3;
    }
}
/**
 * @brief: Change Infix expression to postfix expression using Stack
 * @param infix The infix expression
 * @param infix_arr_size The size of the infix expression
 * @param postfix The address to store the postfix expression
 * @param postfix_arr_size the size of the returned array
 * @return: E_OK if success otherwise E_NOT_OK
 */
Std_Return_t infix_to_postfix(char *infix, uint8_t infix_arr_size, char *postfix, uint8_t postfix_arr_size)
{
    Std_Return_t ret_status = E_OK;
    uint8_t i = 0, j = 0;
    stack_t stack;
    char temp;

    init_stack(&stack);
    if (NULL == infix || 0 == infix_arr_size || 
        NULL == postfix ||0 == postfix_arr_size)
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        while (i < infix_arr_size)
        {
            if (infix[i] == ' ')
            {
                i++;
                continue;
            }
            /* Operand */
            if (isdigit(infix[i]))
            {
                postfix[j++] = infix[i];
            }
            /* Opening parenthesis */
            else if (infix[i] == '(')
            {
                push(&stack, &infix[i], sizeof(char));
            }
            /* Closing parenthesis */
            else if (infix[i] == ')')
            {
                while (E_NOT_OK == stack_is_empty(&stack))
                {
                    pop(&stack, &temp, sizeof(char));
                    if (temp == '(') 
                    {
                        break;
                    }
                    postfix[j++] = temp;
                }
            }
            /* Operator */
            else if (E_OK == is_operator(infix[i]))
            {
                while (E_NOT_OK == stack_is_empty(&stack) && *(char *)stack.top->data != '(' && 
                check_operator_precedence(*(char *)stack.top->data) <= check_operator_precedence(infix[i]))
                {
                    postfix[j++] = *(char *)stack.top->data;
                    pop(&stack, &temp, sizeof(char));
                }
                push(&stack, &infix[i], sizeof(char));
            }
            i++;
        }
        /* Pop all remaining operators */
        while (!stack_is_empty(&stack))
        {
            pop(&stack, &temp, sizeof(char));
            postfix[j++] = temp;
        }
        postfix[j] = '\0'; // Null-terminate postfix
        postfix_arr_size = j;
        /* free the stack*/
        free_stack(&stack);
    }
    return (ret_status);
}
/**
 * @brief: Perform an operation depending on the operator given
 * @param operand1 The first operand
 * @param operand2 The second operand
 * @param operator The operator to perform its operation
 * @return return the result of the operation
 */
static int perform_operation(int operand1, int operand2, char operator)
{
    switch (operator)
    {
        case '+': 
            return operand1 + operand2;

        case '-': 
            return operand1 - operand2;

        case '*': 
            return operand1 * operand2;

        case '/': 
            return operand2 != 0 ? operand1 / operand2 : 0; // Handle division by zero

        case '^': 
            return (int)pow(operand1, operand2);

        default:  
            return 0;  // Invalid operator
    }
}

/**
 * @brief: A function to evaluate the postfix expression
 * @param postfix The postfix expression
 * @param result The address to return the result to it
 * @return: E_OK if success otherwise E_NOT_OK
 */
Std_Return_t evaluate_postfix(const char *postfix, int *result)
{
    Std_Return_t ret_status = E_OK;
    stack_t stack;
    init_stack(&stack);
    int i = 0;
    int operand = 0;
    int operand2 = 0, operand1 = 0, res = 0;

    if (NULL == postfix || NULL == result) 
    {
        ret_status = E_NOT_OK;
    }
    else
    {
        for (; postfix[i] != '\0'; i++)
        {
            /* Operand */
            if (isdigit(postfix[i]))
            {
                /* Convert to number */
                operand = postfix[i] - '0';
                push(&stack, &operand, sizeof(int));
            }
            /* Operator */
            else if (E_OK == is_operator(postfix[i])) 
            {
                /* Check if the operands are in the stack */
                if (E_OK == stack_is_empty(&stack)) 
                {
                    ret_status =  E_NOT_OK;
                }
                else
                {
                    /* Pop the 2nd operand */
                    pop(&stack, &operand2, sizeof(int));
                    if (E_OK == stack_is_empty(&stack))
                    {
                        ret_status =  E_NOT_OK;
                    }
                    else
                    {
                        /* Pop the 1st operand */
                        pop(&stack, &operand1, sizeof(int));
                        /* Perform the operation depending on the current operator */
                        res = perform_operation(operand1, operand2, postfix[i]);
                        /* Push the result of the operation to the stack */
                        push(&stack, &res, sizeof(int));
                    }
                }
            }
        }

        /* Pop the result */
        if (E_NOT_OK == stack_is_empty(&stack))
        {
            pop(&stack, result, sizeof(int));
            if (E_OK == stack_is_empty(&stack))
            {
                ret_status = E_OK;
            }
            else
            {
                ret_status = E_NOT_OK;
            }
        }
    }
    return (ret_status);
}