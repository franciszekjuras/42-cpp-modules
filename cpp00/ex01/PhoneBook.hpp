/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:50:16 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/12 18:40:05 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	bool input();
		
private:
	void addContact();
	void searchContact();
	void printContactsTable();
	int getIndex();
	Contact& contactAtIdx(int index);

	Contact contacts[8];
	static const int contactsMaxSize = 3;
	int contactsBegin;
	int contactsSize;
};

#endif