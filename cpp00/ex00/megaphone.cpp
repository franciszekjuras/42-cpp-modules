/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:31:45 by fjuras            #+#    #+#             */
/*   Updated: 2022/11/11 20:55:45 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

std::string& capitalize(std::string& str)
{
	for(std::string::iterator it = str.begin(); it != str.end(); ++it)
		*it = toupper(*it);
	return (str);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		std::cout << capitalize(arg);
	}
	std::cout << std::endl;
	return (0);
}