#include "priority_queue.h"

int main(void)
{
    PriorityQueue<int> pq(4);
    pq.enqueue(4, 1);
    pq.enqueue(5, 2);
    pq.enqueue(6, 3);
    pq.enqueue(7, 0);
    pq.dequeue();
    pq.print_priority_queue();
    pq.~PriorityQueue();
    /*______________String____________________*/
    cout << "______________String____________________" << endl;
    PriorityQueue<std::string> spq(4);
    spq.enqueue("sama", 0);
    spq.enqueue("me", 2);
    spq.enqueue("work", 1);
    spq.enqueue("anything else", 3);
    spq.print_priority_queue();
    spq.~PriorityQueue();
    /*______________Double____________________*/
    PriorityQueue<double> dpq(4);
    cout << "______________Double____________________" << endl;
    dpq.enqueue(2.5, 0);
    dpq.enqueue(3.5, 1);
    dpq.enqueue(1.5, -1);
    dpq.enqueue(3214.132213, 3);
    dpq.print_priority_queue();
    cout << dpq.get_size_of_pqueue() << endl;
    cout << dpq.peek() << endl;
    cout << dpq.isEmpty() << endl;
    dpq.~PriorityQueue();
}