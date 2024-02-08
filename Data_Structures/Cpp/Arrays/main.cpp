#include "array.h"


int main(void)
{
  std::cout << "-------------int--------------------" << std::endl;
  Array<int> arr(10);
  for (int i = 0; i < 9; i++)
    arr.append(i);  
  arr.print_arr();
  std::cout << "-------------string-----------------" << std::endl;
  Array<std::string> s(5);
  std::string a = "mohamed";
  s.append(a);
  s.append(a);
  s.append(a);
  s.append(a);
  s.print_arr();
  std::cout << "-------------double-----------------" << std::endl;
  Array <double> d(5);
  d.append(1.5);
  d.append(1.5);
  d.append(1.5);
  d.append(1.5);
  d.print_arr();
}
