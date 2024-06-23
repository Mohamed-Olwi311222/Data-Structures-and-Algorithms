#ifndef QUEUES_H
#define QUEUES_H

/*-------------------------------------Include files-------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
/*-------------------------------------MACRO_Tyoes---------------------------------------------------*/

/*A macro for uint8_t zero*/
#define ZERO_INIT    (uint8_t) 0
/*-------------------------------------Predefined_Tyoes----------------------------------------------*/

/*A typedef for signed int with size 1 byte*/
typedef signed char sint8_t;
/**
 * @brief               Enumeration for standard return types for queue operations.
 */
typedef enum STD_return_t
{
    QUEUE_OK,           /**< Operation successful */
    QUEUE_NOK,          /**< Operation not successful */
    QUEUE_NULL,         /**< Null pointer error */
    QUEUE_FULL,         /**< Queue is full */
    QUEUE_EMPTY         /**< Queue is empty */
} STD_return_t;

/**
 * @brief               Structure for a circular queue.
 * @param rear          the rear index of the queue
 * @param front         the front index of the queue
 * @param dataArray     Array of void pointers to store queue elements 
 * @param count         the number of elements in the queue
 * @param size          the Maximum number of elements the queue can hold
 */
typedef struct queue_t
{
    sint8_t rear;
    sint8_t front;
    void **dataArray;
    sint8_t count;
    sint8_t size;
} queue_t;
/*-------------------------------------functions prototypes------------------------------------------*/

/**
 * @brief               initialize the queue
 * @param queue         the address of the pointer to the queue
 * @param size          the size required for the queue
 * @return              STD_return_t enum for each case @ref STD_return_t
 */
STD_return_t init_queue(queue_t **queue, uint8_t);

/**
 * @brief               enqueue the queue with the given data
 * @param queue         the address of the pointer to the queue
 * @param data          the data to enqueue
 * @return              STD_return_t enum for each case @ref STD_return_t
 */
STD_return_t enqueue(queue_t **queue, void *data);

/**
 * @brief               dequeue the queue and return the stored data
 * @param queue         the address of the pointer to the queue
 * @param ret_data      the address to store the returned data
 * @return              STD_return_t enum for each case @ref STD_return_t
 */
STD_return_t dequeue(queue_t **queue, void **ret_data);

/**
 * @brief               return the peak without dequeuing
 * @param queue         the address of the pointer to the queue
 * @param ret_data      the address to store the returned data
 * @return              STD_return_t enum for each case @ref STD_return_t
 */
STD_return_t peek(queue_t **queue, void **ret_data);

/**
 * @brief               free the given queue
 * @param queue         the address of the pointer to the queue
 * @return              STD_return_t enum for each case @ref STD_return_t
 */
STD_return_t free_queue(queue_t **queue);
/*-------------------------------------End-----------------------------------------------------------*/
#endif /*QUEUES_H*/
