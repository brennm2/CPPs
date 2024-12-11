/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:42:10 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/11 17:26:19 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main()
{
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Mutant Stack" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << green << "Top in the Stack: " \
			<< blue << mstack.top() << std::endl << reset;
		std::cout << yellow << "All the stack: " << "\n" << reset;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		{
			std::cout << *it << "\n";
		}
		std::cout << "\n";

		std::cout << yellow << "Poping one" << "\n" << reset;
		mstack.pop();
		std::cout << green << "Size of the Stack: " \
			<< blue << mstack.size() << std::endl << reset;
		
		std::cout << yellow << "\nPushing more..." << "\n" << reset ;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);


		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		std::cout << yellow << "\nIterating..." << "\n" << reset ;
		while (it != ite)
		{
			std::cout << green << "Iterator: " << blue \
				<< *it << std::endl << reset;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "List Container" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << green << "Top in the Stack: " \
			<< blue << *--mstack.end() << std::endl << reset;
		std::cout << yellow << "All the stack: " << "\n" << reset;
		for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		{
			std::cout << *it << "\n";
		}
		std::cout << "\n";

		std::cout << yellow << "Poping one" << "\n" << reset;
		mstack.pop_back();
		std::cout << green << "Size of the Stack: " \
			<< blue << mstack.size() << std::endl << reset;
		
		std::cout << yellow << "\nPushing more..." << "\n" << reset ;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);


		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;

		std::cout << yellow << "\nIterating..." << "\n" << reset ;
		while (it != ite)
		{
			std::cout << green << "Iterator: " << blue \
				<< *it << std::endl << reset;
			++it;
		}
		std::list<int> s(mstack);
	}
}