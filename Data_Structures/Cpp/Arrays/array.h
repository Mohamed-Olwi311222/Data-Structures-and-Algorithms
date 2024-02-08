#ifndef ARRAY_H
#define ARRAY_H
/*---------------Include Dirs-------------------*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>

/*--------------Class---------------------------*/


/**
 * @brief       A template class for an Array
 * @tparam      T the type of data stored in the Array
*/
template <class T>
class Array
{
private:
  unsigned int size;           /**<Represent the size of the taken indices in the array */
  T *arr;                      /**<A pointer to the given type */
  unsigned int capacity;       /**<Size of the whole array */
  /**
    * @brief     initialize the array when constructing it
  */
  void init_arr();
public:
  /**
   * @brief       Constructor for array class with default capacity 5
   * @param[in]   init_capacity initial capacity
  */
  Array(unsigned int init_capacity = 5);


  /**
   * @brief       opertor overload for [] to access the array for readonly
   * @param[in]   idx index to access it for readonly
   * @return      the data inside the current index for readonly or raise an exception if wrong index
  */
  T operator [] (int idx) const;
    /**
   * @brief       opertor overload for [] to access the array for read and write
   * @param[in]   idx index to access it for read and write
   * @return      the data inside the current index for read and write or raise an exception if wrong index
  */
  T& operator [] (int idx);

  /**
   * @brief       append the given data in the array
   * @param[in]   val the value to append to the array
   * @return      0 if success otherwise -1 and throw an exception if array is max
  */
  int append(T val);


  /**
   * @brief       print the whole array
  */
  void print_arr() const;
  ~Array();
};

#include "array.cpp"
#endif /*array.h*/