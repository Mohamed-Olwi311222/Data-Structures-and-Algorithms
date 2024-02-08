#ifndef LIST_H
#define LIST_H

/*----------------Include Dirs-----------------*/
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

/*----------------Class------------------------*/

/**
 * @brief      A template class for a linked list.
 *
 * @tparam     T     The type of data stored in the list nodes.
 */
template<class T>
class LinkedList {
public:
    /**
     * @brief      Constructs the linked list.
     */
    LinkedList() : head(nullptr) ,size(0) {}

    /**
     * @brief       get the size of the current linked list
     * @return      the size of the list
    */
    int get_size();

    /**
     * @brief      Destroys the linked list, freeing all memory.
     */
    ~LinkedList();

    /**
     * @brief      Prints the elements of the list.
     *
     * @return     0 if successful otherwise -1.
     */
    const int print_list();

    /**
     * @brief      Inserts a new node with the given data at the beginning of the list.
     *
     * @param[in]  d     The data to insert into the new node.
     *
     * @return     0 if the prepending is successful, otherwise -1.
     */
    int prepend(const T& d);

    /**
     * @brief       Inserts a new node with the given data the end of the list
     * @param[in]   d   The data to insert into the new node
     * @return      0 if appending is successful, otherwise -1
    */
   int append(const T& d);

    /**
     * @brief       Reverse the list
     * @return      0 if reversing is successful, otherwise -1
    */
   int reverse_list();
private:
    /**
     * @brief      Struct defining a node in the linked list.
     */
    struct Node
    {
        /**
         * @brief       Constructs the node
         * @param[in]   data the data to put in the new node
        */
        Node(const T& data) : data(data), next(nullptr) {}
        Node *next;     /**< Pointer to the next node. */
        T data;         /**< Data stored in the node. */
    };

    int size;  /** Size of the list. */
    Node *head;       /**< Pointer to the head of the list. */
};

#include "list.cpp"
#endif // LIST_H
