#include "list.h"

template <typename T>
int LinkedList<T>::get_size()
{
    return (this->size_of_the_list);
}


template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        LinkedList<T>::size_of_the_list--;
    }
}

template <typename T>
int LinkedList<T>::prepend_data(const T& data)
{
    int status = -1;
    if (!head)
    {
        head = new Node(data);
        assert(head != nullptr);
        size_of_the_list++;
        status = 0;
    }
    else
    {
        Node *newnode = new Node(data);
        assert(newnode != nullptr);
        newnode->next = head;
        head = newnode;
        size_of_the_list++;
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
int LinkedList<T>::append_data(const T& data)
{
    int status = -1;
    Node *curr = head;

    if (head)
    {
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new Node(data);
        assert(curr->next != nullptr);
        size_of_the_list++;
        status = 0;
    }
    else
    {
        head = new Node(data);
        assert(head != nullptr);
        size_of_the_list++;
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

template <typename T>
int LinkedList<T>::insert_at_index(const int index, const T &data)
{
    int status = -1;

    if (index >= size_of_the_list || index < 0)
    {
        return (status);
    }
    if (index == 0)
        this->prepend_data(data);
    else if (index == size_of_the_list - 1)
        this->append_data(data);
    else
    {
        Node *curr = head;
        int idx = 0;
        while (idx < index - 1 && curr)
        {
            curr = curr->next;
            idx++;
        }
        Node *newnode = new Node(data);
        newnode->next = curr->next;
        curr->next = newnode;
        status = 0;
        size_of_the_list++;

    }
    return (status);
}
