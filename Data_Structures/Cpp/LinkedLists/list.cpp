#include "list.h"

template <typename T>
int LinkedList<T>::get_size()
{
    return (this->size);
}


template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        LinkedList<T>::size--;
    }
}

template <typename T>
int LinkedList<T>::prepend(const T& d)
{
    int status = -1;
    if (!head)
    {
        head = new Node(d);
        assert(head != nullptr);
        size++;
        status = 0;
    }
    else
    {
        Node *newnode = new Node(d);
        assert(newnode != nullptr);
        newnode->next = head;
        head = newnode;
        size++;
        status = 0;
    }
    return (status);
}

template <typename T>
const int LinkedList<T>::print_list()
{
    int status = -1;
    Node *curr = head;
    if (head)
    {
        while (curr)
        {
            std::cout << curr->data << "-->" << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
        status = 0;
    }
    else
    {
        std::cout << "EMPTY LIST" << std::endl;
    }
    return (status);
}

template <typename T>
int LinkedList<T>::append(const T& d)
{
    int status = -1;
    Node *curr = head;

    if (head)
    {
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new Node(d);
        assert(curr->next != nullptr);
        size++;
        status = 0;
    }
    else
    {
        head = new Node(d);
        assert(head != nullptr);
        size++;
        status = 0;
    }
    return (status);
}
template <typename T>
int LinkedList<T>:: reverse_list()
{
    int status = -1;

    if (head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        status = 0;
    }
    return (status);
}