#include "list.h"

int main(void)
{
    std::cout << "-------------int--------------------" << std::endl;
    LinkedList<int> i;
    i.prepend_data(1);
    i.prepend_data(10);
    i.prepend_data(20);
    i.prepend_data(30);
    i.prepend_data(40);
    i.prepend_data(110);
    i.append_data(9999);
    i.print_list();
    i.reverse_list();
    i.print_list();
    i.insert_at_index(0, 555);
    i.print_list();
    std::cout <<"Size = "<< i.get_size() << std::endl;
    i.~LinkedList();
    std::cout <<"Size = "<< i.get_size() << std::endl;
    std::cout << "-------------string-----------------" << std::endl;
    LinkedList<std::string> s;
    std::string name = "sama";
    s.prepend_data("mohamed");
    s.prepend_data("mohamed");
    s.prepend_data(name);
    s.prepend_data(name);
    s.append_data("mohamed");
    s.print_list();
    s.reverse_list(); 
    s.print_list();
    s.insert_at_index(2, "love");
    s.print_list();
    s.~LinkedList();
    std::cout <<"Size = "<< s.get_size() << std::endl;
    std::cout << "-------------double-----------------" << std::endl;
    LinkedList<double> d;
    double dd = 19.552131231123213;
    d.prepend_data(1.5);
    d.prepend_data(1.5);
    d.prepend_data(dd);
    d.prepend_data(dd);
    d.append_data(9999.93212319);
    d.print_list();
    d.reverse_list();
    d.print_list();
    d.insert_at_index(d.get_size() - 1, 1.555);
    d.print_list();
    d.~LinkedList();
    std::cout <<"Size = "<< d.get_size() << std::endl;
}