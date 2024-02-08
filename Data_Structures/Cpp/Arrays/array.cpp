#include "array.h"

template <typename T>
void Array<T>::init_arr()
{
  for (int i = 0; i < capacity; i++)
    arr[i] = T();
}

template <typename T>
Array<T>::Array(unsigned int init_capacity)
{
  capacity = init_capacity;
  arr = new T[capacity];
  assert(arr != NULL);
  size = 0;
  this->init_arr();
}

template <typename T>
T Array<T>::operator [] (int idx) const
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

template <typename T>
T& Array<T>::operator [] (int idx)
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

template <typename T>
int Array<T>::append(T val)
{
  int status = -1;
  if (size < capacity)
  {
    arr[size++] = val;
    status = 0;
  }
  else
  {
    throw std::out_of_range("ARRAY IS MAX");
  }
  return (status);
}

template <typename T>
void Array<T>::print_arr() const
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << "\t";
  std::cout << std::endl;
}

template <typename T>
Array<T>::~Array()
{
  delete[] arr;
}