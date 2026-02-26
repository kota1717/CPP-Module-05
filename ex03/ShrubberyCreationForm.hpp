/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:36 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:33:01 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_SHRUBBERYCREATIONFORM_HPP_
#define EX03_SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm :public AForm {
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();

	const std::string getTarget() const;

	virtual void executeAction() const;
};

#endif
