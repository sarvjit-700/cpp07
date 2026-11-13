/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:15:10 by ssukhija          #+#    #+#             */
/*   Updated: 2026/10/27 11:15:10 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _elements(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _n(n) 
{
    if (this->_n > 0)
        this->_elements = new T[this->_n]();
}

template <typename T>
Array<T>::Array(const Array &copy) : _elements(NULL), _n(0)
{
    *this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        //remove garbage / existing memory
        if (this->_elements != NULL)
            delete[] this->_elements;

        this->_n = copy._n;
        if (this->_n > 0)
            this->_elements = new T[this->_n]();
        else
            this->_elements = NULL;
        //deep copy
        for (unsigned int i = 0; i < this->_n; i++)
        {
            this->_elements[i] = copy._elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (this->_elements != NULL)
        delete[] this->_elements;
}

//non-const operator
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_n)
        throw Array::OutOfBoundsException();
    return this->_elements[index];
}

//const operator
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_n)
        throw Array::OutOfBoundsException();
    return this->_elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_n;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "Array Exception: Index is out of bounds!";
}

#endif