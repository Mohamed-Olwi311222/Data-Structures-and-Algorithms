#include "list.h"

int main(void)
{
    std::cout << "-------------int--------------------" << std::endl;
    LinkedList<int> i;
    i.prepend(1);
    i.prepend(10);
    i.prepend(20);
    i.prepend(30);
    i.prepend(40);
    i.prepend(110);
    i.append(9999);
    i.print_list();
    i.reverse_list();
    i.print_list();
    std::cout <<"Size = "<< i.get_size() << std::endl;
    i.~LinkedList();
    i.print_list();
    std::cout <<"Size = "<< i.get_size() << std::endl;
    std::cout << "-------------string-----------------" << std::endl;
    LinkedList<std::string> s;
    std::string name = "sama";
    s.prepend("mohamed");
    s.prepend("mohamed");
    s.prepend(name);
    s.prepend(name);
    s.append("mohamed");
    s.print_list();
    s.reverse_list();
    s.print_list();
    std::cout <<"Size = "<< s.get_size() << std::endl;
    std::cout << "-------------double-----------------" << std::endl;
    LinkedList<double> d;
    double dd = 19.552131231123213;
    d.prepend(1.5);
    d.prepend(1.5);
    d.prepend(dd);
    d.prepend(dd);
    d.append(9999.93212319);
    d.print_list();
    d.reverse_list();
    d.print_list();
    std::cout <<"Size = "<< d.get_size() << std::endl;
}