#include <iostream>
#include <assert.h>
#include <stdexcept>

class Array
{
  private:
    unsigned int size;
    int *arr;
    unsigned int capacity;
    void init_arr()
    {
      for (int i = 0; i < capacity; i++)
        arr[i] = 0;
    }
  public:
    Array(unsigned int init_capacity = 5)
    {
      capacity = init_capacity;
      arr = new int[capacity];
      assert(arr != NULL);
      size = 0;
      this->init_arr();
    } 
    int operator [] (int idx) const
    {
      if (idx >= 0 && idx < size)
      {
        return(arr[idx]);
      }
      else
      {
        throw std::out_of_range("wrong index"); 
      }
    }
    int& operator [] (int idx)
    {
      if (idx >= 0 && idx < size)
      {
        return(arr[idx]);
      }
      else
      {
        throw std::out_of_range("wrong index"); 
      }
    }
    void append(int val)
    {
      if (size < capacity)
        arr[size++] = val;
      else
        throw std::out_of_range("ARRAY IS MAX");
    }
    void print_arr() const
    {
      for (int i = 0; i < size; i++)
        std::cout << arr[i] << "\t";
      std::cout << std::endl;
    }
    ~Array()
    {
      delete[] arr;
    }

};

int main(void)
{
  Array arr(10);
  for (int i = 0; i < 9; i++)
    arr.append(i);
  arr.print_arr();
}
