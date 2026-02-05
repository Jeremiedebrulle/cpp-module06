/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:29:58 by jdebrull          #+#    #+#             */
/*   Updated: 2026/02/05 18:06:18 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <climits>
# include <limits>
# include <string>
# include <cstdlib>
# include <cctype>

class ScalarConverter
{
	private :
		ScalarConverter();
		~ScalarConverter();

		static bool	isChar(const std::string& s);
		static bool	isInt(const std::string& s);
		static bool	isFloat(const std::string& s);
		static bool	isDouble(const std::string& s);

	public :
		static void	convert(const std::string& input);
};

#endif
