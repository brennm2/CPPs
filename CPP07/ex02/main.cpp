/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:42 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 11:44:36 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"


int main( void )
{

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Int Array" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Array<int> intArray(10);
		std::cout << "Array: " << intArray[4] << "\n";
		std::cout << "Size of the Array: " << intArray.size() << "\n";
		std::cout << intArray[10] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "String Array" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Array<std::string> stringArray(500);
		std::cout << "Array: " << stringArray[4] << "\n";
		std::cout << "Size of the Array: " << stringArray.size() << "\n";
		std::cout << stringArray[-5] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	
}

// #include <iostream>
// #include "Array.hpp"
// #include <stdlib.h>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }

// 	for (int i = 0; i < MAX_VAL; i++)
//     {
//         std::cout << "A: " << numbers[i] << "\n";
//     }

//     delete [] mirror;//
//     return 0;
//}