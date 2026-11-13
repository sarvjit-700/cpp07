/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:48:19 by ssukhija          #+#    #+#             */
/*   Updated: 2026/10/26 10:48:19 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

#define RESET "\033[;0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

// called for non-const elements
void increment(int &n)
{
    n++;
}


// takes const T &, so it can be used for const and non-const arrays
template <typename T>
void printElement(const T &elem)
{
    std::cout << BLUE << elem << RESET << " ";
}


// takes T &, so it can be called on non-const elements
template <typename T>
void incrementT(T &n)
{
    n++;
}


// modifies stings through T &
template <typename T>
void addStar(T &elem)
{
    elem = elem + "*";
    std::cout << BLUE << elem << RESET << " ";
}


int main()
{
    std::cout << YELLOW << "--- Testing with Int Array ---" << RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original ints : ";
    // TEST: non-const array + const T& function
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    // TEST: non-const array + plain function -> the array itself is modified
    std::cout << "Incrementing..." << std::endl;
    ::iter(intArray, intLen, increment);

    std::cout << "Modified ints : ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;
    
    // TEST: instantiated template (incrementT<int>) works as the 3rd argument and modifies the array
    std::cout << "Incrementing with template incrementT..." << std::endl;
    ::iter(intArray, intLen, incrementT<int>);
    std::cout << "Modified ints : ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << YELLOW << "\n--- Testing with String Array ---" << RESET << std::endl;
    std::string strArray[] = {"Hello", "from", "the", "iter", "template"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Strings          : ";
    // TEST: iter works with a class type (std::string), not only built-in types
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "Add *            : ";
    // TEST: std::string elements are modified in place through a T& template
    ::iter(strArray, strLen, addStar<std::string>);
    std::cout << std::endl;

    // Prove string were modified
    std::cout << "Modifiied Strings: ";
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    std::cout << YELLOW << "\n--- Testing with Const Array ---" << RESET << std::endl;
    const double doubleArray[] = {42.42, 21.21, 10.10};
    size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Const doubles : ";
    // TEST: const array + const T& function -> T is deduced as const double, compiles and only reads
    ::iter(doubleArray, doubleLen, printElement<double>);
    std::cout << std::endl;

    std::cout << YELLOW << "\n--- Testing with Length 0 ---" << RESET << std::endl;
    std::cout << "Empty run     : ";
    ::iter(intArray, 0, printElement<int>);
    std::cout << "(nothing printed)" << std::endl;

    // Prove you can't modify a const
    // doubleArray (above) is const, therefore T is const double, and arr[i] is const,
    // but incrementT doesn't accept const because it modifies
    // uncomment this line for compile fail at arr[i] because it tries to modify a const:
    //::iter(doubleArray, doubleLen, incrementT<double>);

    return 0;
}