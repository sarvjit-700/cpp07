/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 12:04:42 by ssukhija          #+#    #+#             */
/*   Updated: 2026/10/25 12:04:42 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

#define RESET "\033[;0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"




int main( void ) {
/*
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
    std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
    std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;

*/

    int a = 2;
    int b = 3;

    std::cout << YELLOW << "--- Testing Ints ---" << RESET << std::endl;
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap : a = " << a << RESET << ", b = " << b << RESET << std::endl;
    
    std::cout << "min(a, b)  : " << GREEN << ::min(a, b) << RESET << std::endl;
    std::cout << "max(a, b)  : " << GREEN << ::max(a, b) << RESET << std::endl;

    std::cout << YELLOW << "\n--- Testing Strings ---" << RESET << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap : c = " << c << RESET << ", d = " << d << RESET << std::endl;
    
    std::cout << "min(c, d)  : " << GREEN << ::min(c, d) << RESET << std::endl;
    std::cout << "max(c, d)  : " << GREEN << ::max(c, d) << RESET << std::endl;

    std::cout << YELLOW << "\n--- Testing Equal Values ---" << RESET << std::endl;

    int x = 5; 
    int y = 5;
    std::cout << "If values are the same return the second argument," <<std::endl;
    std::cout << "if the second argument is returned output 1" <<std::endl;
    std::cout << "Test MIN: " << GREEN << (&::min(x, y) == &y) << RESET << std::endl; //compare to y
    std::cout << "Test MAX: " << GREEN << (&::max(x, y) == &y) << RESET << std::endl; //comapre to y
    std::cout << "Test MIN: " << GREEN << (&::min(x, y) == &x) << RESET << std::endl; //compare to x
    std::cout << "Test MAX: " << GREEN << (&::max(x, y) == &x) << RESET << std::endl; //compare to x
    std::cout << "Test strings:" << std::endl;
    std::string g = "test"; std::string h = "test";
    std::cout << "Test MIN: " << GREEN << (&::min(g, h) == &h) << RESET << std::endl; //compare to h

    return 0;
}