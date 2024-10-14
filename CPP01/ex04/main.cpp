/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:33:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/14 13:46:54 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string	get_content(std::ifstream *inFile)
{
	std::stringstream buffer;

	buffer << inFile->rdbuf();
	return buffer.str();
}


std::string	replace_words(std::string &fileContent, std::string str1, std::string str2)
{
	std::string buffer = fileContent;

	std::size_t index = buffer.find(str1);
	if (index == std::string::npos)
	{
		std::cout << "No string to be replaced found :(\n";
		return ("");
	}
	while(index != std::string::npos)
	{
		buffer.erase(index, str1.size());
		buffer.insert(index, str2);
		index = buffer.find(str1, index + str2.size());
	}
	return (buffer);
}

bool	place_string_outFile(std::string fileContent, std::string fileName)
{
	std::ofstream outFile;
	std::string fileName_replace = fileName + "_replace";
	
	outFile.open(fileName_replace.c_str());
	if (outFile.fail())
	{
		std::cout << "Fail to open outFile\n";
		return (false);
	}

	outFile << fileContent;
	outFile.close();
	std::cout << "\033[34m" << fileName_replace << "\033[0m" << " created!\n";
	return (true);
}

bool	takeInput(std::string& inputBuffer)
{
	std::getline(std::cin, inputBuffer);
	if (std::cin.fail() || std::cin.eof() || inputBuffer.empty())
	{
		std::cout << "Problem with input\n";
		return(false);
	}
	std::cout << "\n";
	return (true);
}

int main(void)
{
	std::string fileName, str1, str2, fileContent;
	std::ifstream inFile;

	std::cout << "File name: ";
	if (!takeInput(fileName))
		return (1);
	std::cout << "String to be replaced: ";
	if (!takeInput(str1))
		return (1);
	std::cout << "Model string: ";
	if (!takeInput(str2))
		return (1);

	inFile.open(fileName.c_str());
	if (inFile.fail())
	{
		std::cout << "Fail to open " + fileName + "\n";
		return (1);
	}
	fileContent = get_content(&inFile);
	if (fileContent == "")
	{
		std::cout << "Empty file!\n";
		return (1) ;
	}
	fileContent = replace_words(fileContent, str1, str2);
	if (fileContent.empty())
		return (1);
	place_string_outFile(fileContent, fileName);
	inFile.close();

	return (0);
}