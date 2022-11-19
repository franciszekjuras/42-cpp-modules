/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:07:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/12 19:04:38 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include "Contact.hpp"

PhoneBook::PhoneBook() :
	contactsBegin(0),
	contactsSize(0)
{
}

bool PhoneBook::input()
{
	std::string cmd;

	std::cout << "(ADD|SEARCH|EXIT)" << std::endl;
	std::cout << "% ";
	std::getline(std::cin, cmd);
	if (cmd == "ADD")
		addContact();
	else if (cmd == "SEARCH")
		searchContact();
	else if (cmd == "EXIT")
		return (false);
	return (true);
}

void PhoneBook::addContact()
{
	int contactsNext = (contactsBegin + contactsSize) % contactsMaxSize;
	if (contactsSize != contactsMaxSize)
		++contactsSize;
	else
		++contactsBegin;
	Contact& contact = contacts[contactsNext];
	contact.input();
}

void PhoneBook::searchContact()
{
	printContactsTable();
	int index = getIndex();
	if (index < 0 || index >= contactsSize)
		std::cout << "Invalid index" << std::endl;
	else
		contactAtIdx(index).print();
}

int PhoneBook::getIndex()
{
	std::cout << "Index: ";
	int index;
	std::cin >> index;
	if (!std::cin.good())
	{
		index = -1;
		std::cin.clear();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (index);
}

Contact& PhoneBook::contactAtIdx(int index)
{
	return (contacts[(contactsBegin + index) % contactsMaxSize]);
}

void PhoneBook::printContactsTable()
{
	Contact::printOneLineHeader();
	for (int i = 0; i < contactsSize; ++i)
		contactAtIdx(i).printOneLine(i);
}
