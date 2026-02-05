/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:40:37 by jdebrull          #+#    #+#             */
/*   Updated: 2026/02/05 18:18:15 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(const std::string& s) {
	if (s.length() == 1 && !std::isdigit(s[0]) && std::isprint(s[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string& s) 
{
	if (s.empty())
		return (false);
	
	size_t	i = 0;
	
	if ((s[0] == '+' || s[0] == '-'))
		i = 1;
	if (i >= s.length())
		return (false);
	while (i < s.length()) {
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	
	try
	{
		long value = std::stol(s);
		if (value > INT_MAX || value < INT_MIN)
			return (false);
	}
	catch (const std::exception&) {
		return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& s) 
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);
	if (s.empty() || s.length() < 2)
		return (false);
	if (s[s.length() -1] != 'f')
		return (false);

	size_t	i = 0;

	if (s[0] == '+' || s[0] == '-')
		i++;
	bool	hasDot = false;
	bool	hasWholeNum = false;
	bool	hasFractionalNum = false;

	while (i < s.length() && std::isdigit(s[i]))
	{
		hasWholeNum = true;
		i++;
	}
	
	if (i < (s.length() - 1) && s[i] == '.') {
		hasDot = true;
		i++;
	}
	
	while (i < s.length() - 1 && std::isdigit(s[i])) {
		hasFractionalNum = true;
		i++;
	}
	if (!hasDot || (!hasWholeNum && !hasFractionalNum))
		return (false);

	if (i != s.length() - 1)
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(const std::string& s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);
	if (s.empty())
		return (false);

	size_t	i = 0;

	if (s[0] == '+' || s[0] == '-')
		i++;

	bool	hasDot = false;
	bool	hasWholeNum = false;
	bool	hasFractionalNum = false;

	while (i < s.length() && std::isdigit(s[i])) {
		hasWholeNum = true;
		i++;
	}
	
	if (i < s.length() && s[i] == '.') {
		hasDot = true;
		i++;
	}
	
	while (i < s.length() && std::isdigit(s[i])) {
		hasFractionalNum = true;
		i++;
	}
	
	if (!hasDot || (!hasWholeNum && !hasFractionalNum))
		return (false);
	
	if (i != s.length())
		return(false);

	return (true);
}

static bool isInf(double d) {
	if (d < 0)
		d *= -1;
	return (d == std::numeric_limits<double>::infinity());
}

static void	printChar(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
		std::cout << "impossible\n";
		return;
	}
	char c = static_cast<char>(d);
	if (!std::isprint(c)) {
		std::cout << "Non displayable\n";
		return;
	}
	std::cout << "'" << c << "'\n";
}

static void	printInt(double d) {
	std::cout	<< "int: ";
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
		std::cout << "impossible\n";
		return;
	}
	std::cout	<< static_cast<int>(d) << std::endl;
}

static void	printFloat(double d) {
	std::cout	<< "float: ";
	if (std::isnan(d)) {
		std::cout	<< "nanf" << std::endl;
		return ;
	}
	if (std::isinf(d)) {
		if (d < 0)
			std::cout	<< "-inff" << std::endl;
		else
			std::cout	<< "+inff" << std::endl;
		return ;
	}
	
	float f = static_cast<float>(d);
	if (f == static_cast<int>(f) && f >= INT_MIN && f <= INT_MAX)
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

static void	printDouble(double d) {
	std::cout	<< "double: ";
	if (std::isnan(d)) {
		std::cout	<< "nan" << std::endl;
		return ;
	}
	if (isInf(d)) {
		if (d < 0)
			std::cout	<< "-inf" << std::endl;
		else
			std::cout	<< "+inf" << std::endl;
		return ;		
	}
	std::cout	<< d << std::endl;
}

void	ScalarConverter::convert(const std::string& input) {
	double	d;
	
	try {
		if (isChar(input))
			d = static_cast<double>(input[0]);
		else if (isInt(input))
			d = static_cast<double>(std::stoi(input));
		else if (isFloat(input))
		{
			if (input == "nanf")
				d = std::numeric_limits<double>::quiet_NaN();
			else if (input == "+inff")
				d = std::numeric_limits<double>::infinity();
			else if (input == "-inff")
				d = -std::numeric_limits<double>::infinity();
			else
				d = std::stod(input);
		}
		else if (isDouble(input))
		{
			if (input == "nan")
				d = std::numeric_limits<double>::quiet_NaN();
			else if (input == "+inf")
				d = std::numeric_limits<double>::infinity();
			else if (input == "-inf")
				d = -std::numeric_limits<double>::infinity();
			else
				d = std::stod(input);
		}
		else {
			std::cout << "Error: unknown literal\n";
			return ;
		}
	} catch (...) {
		std::cout << "Error: conversion failed\n";
		return ;
	}
	
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}