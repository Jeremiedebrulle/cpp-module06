/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:29:58 by jdebrull          #+#    #+#             */
/*   Updated: 2025/12/17 18:45:02 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <iostream>
#include <climits>
#include <string>

class ScalarConverter
{
	private :
		ScalarConverter();
		~ScalarConverter();

		static bool	isChar(const std::string& s);
		static bool	isInt(const std::string& s);
		static bool	isFloat(const std::string& s);
		static bool	isDouble(const std::string& s);
		static bool	isSpecial(const std::string& s);

	public :
		static void	convert(const std::string& input);
};

#endif
