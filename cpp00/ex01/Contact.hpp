/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:24:31 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/12 18:53:42 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
public:
	static void printOneLineHeader();

	void input();
	void print();
	void printOneLine(int index);

private:
	static void printStringTrunc(std::string str);

	static const int printWidth = 10;

	std::string getField(const std::string& prompt);	
	void printField(const std::string& name, const std::string& value);

	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif