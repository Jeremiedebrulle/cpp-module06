/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:40:37 by jdebrull          #+#    #+#             */
/*   Updated: 2025/12/17 18:47:45 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}



bool	ScalarConverter::isChar(const std::string& s) {
	if (s.length() == 1 && isprint(s[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string& s) {
	if (s.empty())
		return (false);
	
	size_t	i = 0;
	
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (i < s.length()) {
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	
	long	value = std::strtol(s.c_str(), NULL, 10);
	if (value > INT_MAX || value < INT_MIN)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& s) {
	size_t	i = 0;
	
	if (s.empty())
		return (false);
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (i < s.length() && std::isdigit(s[i]))
		i++;
	if (i < s.length() && s[i] != '.')
		return (false);
	while (++i < s.length() - 1)
		if (!std::isdigit(s[i]))
			return(false);
	if (std::isdigit(s[i - 1]) && s[i] == 'f')
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string& s) {
	size_t	i = 0;
	
	if (s.empty())
		return (false);
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (i < s.length() && std::isdigit(s[i]))
		i++;
	if ((i < s.length() && s[i] != '.') || i == 0)
		return (false);
	while (++i < s.length())
		if (!std::isdigit(s[i]))
			return(false);
	return (true);
}

bool	ScalarConverter::isSpecial(const std::string& s) {
	return (s == "nan" || s == "nanf" || s == "+inf" ||
			s == "-inf" || s == "+inff" || s == "-inff");
}

static void	printChar(double d) {
	
}

static void	printInt() {
	std::cout	<< "Int : ";
}

static void	printFloat() {
	std::cout	<< "Float : ";
}

static void	printDouble() {
	std::cout	<< "Double : ";
}

void	ScalarConverter::convert(const std::string& input) {
	double	d;
	
	if (isChar(input)) {
		value = static_cast<double>(input[0]);
	}
}