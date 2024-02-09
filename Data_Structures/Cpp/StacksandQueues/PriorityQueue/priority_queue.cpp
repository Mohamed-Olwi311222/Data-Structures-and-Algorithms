#include "priority_queue.h"


template <typename T>
int PriorityQueue<T>::isEmpty()
{
    if (this->head)
        return (0);
    else
        return (1);
}

template <typename T>
int PriorityQueue<T>::get_size_of_pqueue()
{
    return (this->size_of_the_pqueue);
}

template <typename T>
int PriorityQueue<T>::enqueue(T data, int priority)
{
    int status = -1;
    Node *newnode = new Node(data, priority);
    assert(newnode != 0);
    if (!head || priority < head->priority)
    {
        newnode->next = head;
        head = newnode;
        status = 0;
    }
    else
    {
        Node *iterator = head;
        while (iterator->next && iterator->next->priority < priority)
        {
            iterator = iterator->next;
        }
        newnode->next = iterator->next;
        iterator->next = newnode;
        status = 0;
    }
    return (status);
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    if (head)
    {
        T data = head->data;
        Node *dequeued_node = head;
        head = head->next;
        delete dequeued_node;
        return (data);
    }
    throw std::runtime_error("Head is NULL");
}
 
template <typename T>
T PriorityQueue<T>::peek()
{
    if (head)
        return (this->head->data);
    throw std::runtime_error("Head is NULL");
}

template <typename T>
void PriorityQueue<T>::print_priority_queue()
{
    Node *iterator = head;
    while (iterator)
    {
        cout << iterator->data << "-> ";
        iterator = iterator->next;
    }
    cout << endl;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    if (head)
    {
        Node *iterator = head;
        while (head)
        {
            head = head->next;
            delete iterator;
            iterator = head;
        }
    }
}