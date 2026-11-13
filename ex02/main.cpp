/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:15:28 by ssukhija          #+#    #+#             */
/*   Updated: 2026/11/13 21:15:28 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "=== 1. 42 SUBJECT INTRANET TEST ===" << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        std::srand(std::time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = std::rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        // SCOPE test: deep copy via assignment and copy constructor
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                delete[] mirror;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Caught expected exception (-2): " << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Caught expected exception (MAX_VAL): " << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = std::rand();
        }
        delete[] mirror;
    }

    std::cout << "\n=== 2. EMPTY ARRAY & DEFAULT INITIALIZATION ===" << std::endl;
    {
        Array<int> emptyArr;
        std::cout << "Empty array size: " << emptyArr.size() << std::endl;
        try
        {
            std::cout << emptyArr[0] << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Accessing emptyArr[0]: " << e.what() << std::endl;
        }

        Array<int> defaultInit(5);
        std::cout << "Default initialized int array (should be all 0s): ";
        for (unsigned int i = 0; i < defaultInit.size(); i++)
            std::cout << defaultInit[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "\n=== 3. DEEP COPY VERIFICATION ===" << std::endl;
    {
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;

        Array<int> copyConstructed(original);
        Array<int> assigned;
        assigned = original;

        original[0] = 999;
        copyConstructed[1] = 888;
        assigned[2] = 777;

        std::cout << "Original:        " << original[0] << ", " << original[1] << ", " << original[2] << std::endl;
        std::cout << "CopyConstructed: " << copyConstructed[0] << ", " << copyConstructed[1] << ", " << copyConstructed[2] << std::endl;
        std::cout << "Assigned:        " << assigned[0] << ", " << assigned[1] << ", " << assigned[2] << std::endl;
    }

    std::cout << "\n=== 4. CONST ARRAY & COMPLEX TYPES (std::string) ===" << std::endl;
    {
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "42";
        strArr[2] = "Templates";

        const Array<std::string> constStrArr(strArr);
        std::cout << "Reading from const Array<std::string> (size " << constStrArr.size() << "): ";
        for (unsigned int i = 0; i < constStrArr.size(); i++)
            std::cout << constStrArr[i] << " ";
        std::cout << std::endl;
        // constStrArr[0] = "Nope"; // Uncommenting this should fail to compile!
    }

    return 0;
}