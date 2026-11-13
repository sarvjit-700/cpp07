/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:01:46 by ssukhija          #+#    #+#             */
/*   Updated: 2026/10/27 11:01:46 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
    private:
        T*              _elements;
        unsigned int    _n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        ~Array();

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif