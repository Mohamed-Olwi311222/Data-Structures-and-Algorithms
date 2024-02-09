#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
/*----------------------Include Dirs------------*/
#include <iostream>
#include <stdexcept>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
/*----------------------Class------------------*/

/**
 * @brief       A template class for priority queue using linked list
 * 
 * @tparam      T the type of data stored in the Array
*/
template <class T>
class PriorityQueue
{
public:
    /**
     * @brief       Constructs the priority queue
     * 
     * @param[in]   size_of_the_pqueue  the size of the priority queue
    */
    PriorityQueue(int size_of_the_pqueue) : size_of_the_pqueue(size_of_the_pqueue), head(nullptr){}
    /**
     * @brief               Checks whether the queue is empty or not
     * 
     * @return              1 if success otherwise 0
    */
    int isEmpty();
    /**
     * @brief                   enqueue to the priority queue
     * 
     * @param[in]   T           data to enqueue to the queue
     * @param[in]   priority    priority of the enqueued node
     * 
     * @return      0 if enqueue is success otherwise -1
    */
    int enqueue(T data, int priority);
    /**
     * @brief               remove the highest priority node of the queue
     * 
     * @return              The data of the dequeued node
    */
    T dequeue();
    /**
     * @brief               view the highest priority node of the queue
     * 
     * @return              the data of the highest priority node
    */
    T peek();

    /**
     * @brief               gets the size of the priority queue
     * 
     * @return              the size of the priority queue
    */
    int get_size_of_pqueue();

    /**
     * @brief               prints the priority queue to stdout
    */
    void print_priority_queue();

    /**
     * @brief               frees all the taken memory
    */
    ~PriorityQueue();
private:
    struct Node
    {
        /**
         * @brief       Constructs the node
         * 
         * @param[in]   data the data to put in the new node
         * @param[in]   priority    the priority to store in the node
        */
        Node(const T& data, int priority) : data(data), next(nullptr), priority(priority) {}
        Node *next;     /**< Pointer to the next node. */
        T data;         /** Data stored in the node. */
        int priority;   /* Priority of the current node lower number means higher priority*/ 
    };
    Node *head;                 /**< Pointer to the head of the list*/
    int size_of_the_pqueue;     /*Size of the priority queue*/

};

#include "priority_queue.cpp"
#endif /*priority_queue.h*/
