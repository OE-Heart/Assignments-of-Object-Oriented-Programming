/*
 * @Author: Ou Yixin
 * @Date: 2021-05-29 13:30:41
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-29 13:44:36
 * @Description: 
 * @FilePath: /Vector/myvector.hpp
 */
#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <class T>
class Vector {
public:
  Vector();                   // creates an empty vector
  Vector(int size);           // creates a vector for holding 'size' elements
  Vector(const Vector& r);    // the copy ctor
  ~Vector();                  // destructs the vector 
  T& operator[](int index);   // accesses the specified element without bounds checking
  T& at(int index);           // accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
  int size() const;           // return the size of the container
  void push_back(const T& x); // adds an element to the end 
  void clear();               // clears the contents
  bool empty() const;         // checks whether the container is empty 
private:
  void inflate();             // expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
  T *m_pElements;             // pointer to the dynamically allocated storage
  int m_nSize;                // the number of elements in the container
  int m_nCapacity;            // the number of elements that can be held in currently allocated storage
};

/**
 * @description: creates an empty vector
 * @param {None}
 * @return {None}
 */
template <class T>
Vector<T>::Vector()
{
    m_nSize = 0;
    m_nCapacity = 5;
    m_pElements = (T*)malloc(sizeof(T)*m_nCapacity);
    std::cout << "Vector<T>::Vector()" << std::endl;
}

/**
 * @description: creates a vector for holding 'size' elements
 * @param {the size of new vector}
 * @return {None}
 */
template <class T>
Vector<T>::Vector(int size)
{
    m_nSize = 0;
    m_nCapacity = size;
    m_pElements = (T*)malloc(sizeof(T)*m_nCapacity);
    std::cout << "Vector<T>::Vector(" << size << ")" << std::endl;

}

/**
 * @description: the copy ctor
 * @param {the reference of copy object}
 * @return {None}
 */
template <class T>
Vector<T>::Vector(const Vector& r)
{
    m_nSize = r.size();
    m_nCapacity = r.size();
    m_pElements = (T*)malloc(sizeof(T)*m_nCapacity);

    for (int i = 0; i < m_nSize; i++)
    {
        m_pElements[i] = r.m_pElements[i];
    }

    std::cout << "Vector<T>::Vector(const Vector& r)" << std::endl;

}

/**
 * @description: destructs the vector 
 * @param {None}
 * @return {None}
 */
template <class T>
Vector<T>::~Vector()
{
    m_nSize = 0;
    m_nCapacity = 0;
    free(m_pElements);
    std::cout << "Vector<T>::~Vector()" << std::endl;
}

/**
 * @description: accesses the specified element without bounds checking
 * @param {the index of the specified element to be accessed}
 * @return {the specified element accessed}
 */
template <class T>
T& Vector<T>::operator[](int index)
{
    std::cout << "T& Vector<T>::operator[](int index)" << std::endl;
    return m_pElements[index];

}

/**
 * @description: accesses the specified element, throws an exception of type 'std::out_of_range' when index
 * @param {the index of the specified element to be accessed}
 * @return {the specified element accessed}
 */
template <class T>
T& Vector<T>::at(int index)
{
    if (index < 0 || index >= m_nSize) throw std::out_of_range("Error"); //bounds checking
    std::cout << "T& Vector<T>::at(int index)" << std::endl;
    return m_pElements[index];
}

/**
 * @description: return the size of the container
 * @param {None}
 * @return {the size of the container}
 */
template <class T>
int Vector<T>::size() const
{
    return m_nSize;
}

/**
 * @description: adds an element to the end
 * @param {the element to be added}
 * @return {None}
 */
template <class T>
void Vector<T>::push_back(const T& x)
{
    if (m_nSize == m_nCapacity) inflate();
    m_pElements[m_nSize++] = x;
}

/**
 * @description: clears the contents
 * @param {None}
 * @return {None}
 */
template <class T>
void Vector<T>::clear()
{
    m_nSize = 0;
    std::cout << "void Vector<T>::clear()" <<std::endl;
}

/**
 * @description: checks whether the container is empty 
 * @param {None}
 * @return {true if the container is empty otherwise false}
 */
template <class T>
bool Vector<T>::empty() const
{
    return (m_nSize == 0);
}

/**
 * @description: expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
 * @param {None}
 * @return {None}
 */
template <class T>
void Vector<T>::inflate()
{
    m_nCapacity *= 2;  //expand the storage
    T *p = m_pElements;
    m_pElements = (T*)malloc(sizeof(T)*m_nCapacity);
    for (int i = 0; i < m_nSize; i++)  //copy to the new vector
    {
        m_pElements[i] = p[i];
    }
    free(p);
    std::cout << "void Vector<T>::inflate()" << std::endl;
}