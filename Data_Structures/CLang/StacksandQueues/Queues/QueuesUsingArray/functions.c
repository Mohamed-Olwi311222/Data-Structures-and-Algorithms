#include "queues.h"

/**
 * @brief a helper function to check if the queue is full
 * @param queue the queue to check for the condition
 * @return STD_return_t enum for each case @ref STD_return_t
 */
static uint8_t queue_full(queue_t *queue)
{
    return (queue->count == queue->size);
}

/**
 * @brief a helper function to check if the queue is empty 
 * @param queue the queue to check for the condition
 * @return STD_return_t enum for each case @ref STD_return_t
 */
static uint8_t queue_empty(queue_t *queue)
{
    return (queue->count == 0);
}

STD_return_t init_queue(queue_t **queue, uint8_t size)
{
    STD_return_t ret = QUEUE_NOK;
    if (NULL == queue || size >= UINT8_MAX)
    {
        ret = QUEUE_NULL;
    }
    else
    {
        *queue = (queue_t*) malloc(sizeof(queue_t));
        if (NULL == queue)
        {
            ret = QUEUE_NOK;
        }
        else
        {
           (*queue)->dataArray = (void **) calloc(size, sizeof(void *));
            if (NULL == (*queue)->dataArray)
            {
                free(queue);
                ret = QUEUE_NOK;
            }
            else
            {
                (*queue)->count = ZERO_INIT;
                (*queue)->size = size;
                (*queue)->front = -1;
                (*queue)->rear = -1;
                ret = QUEUE_OK;
            }
        }
    }
    return (ret);
}
STD_return_t enqueue(queue_t **queue, void *data)
{
    STD_return_t ret = QUEUE_NOK;
    if (NULL == queue || NULL == (*queue) || NULL == (*queue)->dataArray|| NULL == data)
    {
        ret = QUEUE_NULL;
    }
    else
    {
        ((*queue)->rear)++;
        if (queue_full(*queue))
        {
            ret = QUEUE_FULL;
        }
        else
        {
            if (((*queue)->rear == (*queue)->size) && ((*queue)->count < (*queue)->size))
            {
                (*queue)->rear = ZERO_INIT;
            }
            if (ZERO_INIT > (*queue)->front)
            {
                (*queue)->front = ZERO_INIT;
            }
            (*queue)->dataArray[(*queue)->rear] = data;
            ((*queue)->count)++;
            ret = QUEUE_OK;
        }
    }
    return (ret);
}
STD_return_t dequeue(queue_t **queue, void **ret_data)
{
    STD_return_t ret = QUEUE_NOK;
    if (NULL == queue || NULL == (*queue) || NULL == (*queue)->dataArray)
    {
        ret = QUEUE_NULL;
    }
    else
    {
        if (queue_empty(*queue))
        {
            ret = QUEUE_EMPTY;
        }
        else
        {
            *ret_data = (*queue)->dataArray[(*queue)->front];
            ((*queue)->front)++;
            if (((*queue)->front == (*queue)->size) && ((*queue)->count > ZERO_INIT))
            {
                (*queue)->front = ZERO_INIT;
            }
            ((*queue)->count)--;
            ret = QUEUE_OK;
        }
    }
    return (ret);
}
STD_return_t peek(queue_t **queue, void **ret_data)
{
    STD_return_t ret = QUEUE_NOK;
    if (NULL == queue || NULL == (*queue) || NULL == (*queue)->dataArray)
    {
        ret = QUEUE_NULL;
    }
    else
    {
        if (ZERO_INIT == (*queue)->count)
        {
            ret = QUEUE_EMPTY;
        }
        else
        {
            *ret_data = (*queue)->dataArray[(*queue)->front];
            ret = QUEUE_OK;
        }
    }
    return (ret);
}

STD_return_t free_queue(queue_t **queue)
{
    STD_return_t ret = QUEUE_NOK;
    if (NULL == queue || NULL == *queue)
    {
        ret = QUEUE_NULL;
    }
    else
    {
        if (NULL != (*queue)->dataArray)
        {
            free((*queue)->dataArray);
            (*queue)->dataArray = NULL;
        }
        free(*queue);
        *queue = NULL;
        ret = QUEUE_OK;
    }
    return (ret);
}
