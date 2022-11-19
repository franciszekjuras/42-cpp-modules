/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:24:26 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/12 18:54:56 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

void Contact::input()
{
	firstName = getField("first name");
	lastName = getField("last name");
	nickName = getField("nickname");
	phoneNumber = getField("phone number");
	darkestSecret = getField("darkest secret");
}

void Contact::print()
{
	printField("first name", firstName);
	printField("last name", lastName);
	printField("nickname", nickName);
	printField("phone number", phoneNumber);
	printField("darkest secret", darkestSecret);
}

void Contact::printField(const std::string& name, const std::string& value)
{
	std::cout << name << ": " << value << std::endl;
}

void Contact::printOneLineHeader()
{
	printStringTrunc("index");
	std::cout << "|";
	printStringTrunc("first name");
	std::cout << "|";
	printStringTrunc("last name");
	std::cout << "|";
	printStringTrunc("nickname");
	std::cout << std::endl;
}

void Contact::printOneLine(int index)
{
	std::ostringstream s;
	s << index;
	std::string indexStr = s.str();
	printStringTrunc(indexStr);
	std::cout << "|";
	printStringTrunc(firstName);
	std::cout << "|";
	printStringTrunc(lastName);
	std::cout << "|";
	printStringTrunc(nickName);
	std::cout << std::endl;
}

void Contact::printStringTrunc(std::string str)
{
	bool isTruncated = str.size() > printWidth;
	if (isTruncated)
		std::cout << std::right << str.substr(0, printWidth - 1) << ".";
	else
		std::cout << std::setw(printWidth) << str;
}

std::string Contact::getField(const std::string& name)
{
	std::string input;
	
	while (input.empty())
	{
		std::cout << name << ": ";
		std::getline(std::cin, input);
	}
	return (input);
}
