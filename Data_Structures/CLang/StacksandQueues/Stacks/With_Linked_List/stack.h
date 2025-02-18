#ifndef STACK_H
#define STACK_H
/*-------------------------Include Files----------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/*-------------------------Global variables-------------------------------------*/
extern size_t length;
/*-------------------------Macros-----------------------------------------------*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK            (Std_Return_t)0x00u
#define E_NOT_OK        (Std_Return_t)0x01u
#endif
/*-------------------------Data types-------------------------------------------*/
typedef uint8_t Std_Return_t;
/**
 * struct node - A linked list nodes type
 * @data: The data to store in each node
 * @next: The pointer to the next node
 */
typedef struct node
{
  void *data;
  struct node *next;
} node_t;
/**
 * stack - A stack data type
 * @top: The pointer to the top of the stack
 */
typedef struct
{
  node_t *top;
} stack_t;
/*-------------------------Function prototypes----------------------------------*/
/**
 * @brief:
 * @param stack: the stack to modify
 * @param data: pointer to the data
 * @param data_size: size of the data
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t push(stack_t *stack, const void *const data, const size_t data_size);
/**
 * @brief: Pop the top of the stack and return its value
 * @param stack: the stack to modify
 * @param addr: The address to return the deleted top
 * @param data_size: The data size of the returned top
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t pop(stack_t *stack, void *const data, const size_t data_size);
/**
 * @brief: Peak at the top of the stack and return its value
 * @param stack: the stack to peak at the top of it
 * @param addr: The address to return the peaked data
 * @param data_size: The data size of the returned data
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t peek(const stack_t *const stack, void *const addr, const size_t data_size);
/**
 * @brief: Print the whole stack and return its value
 * @param stack: the stack to print
 * @param print_data_type: The type of the stack data to print
 * @return: E_OK if success, E_NOT_OK if fail
 */
Std_Return_t printStack(const stack_t *const stack, void (*print_data_type)(void *));
/**
 * @brief: Print int data type
 * @param data: The int data type to print
 */
void print_int(void *data);
/**
 * @brief: Print String data type
 * @param data: The string data type to print
 */
void print_str(void *data);
/**
 * @brief: Print char data type
 * @param data: The char data type to print
 */
void print_char(void *data);
/**
 * @brief: Print float data type with .2 precision
 * @param data: The float data type to print
 */
void print_float(void *data);
/*-------------------------End-------------------------------------------------*/
#endif /*STACK_H*/

