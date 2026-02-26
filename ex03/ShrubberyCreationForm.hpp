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

class ShurubberyCreationForm :public AForm {
	std::string _target;

public:
	ShurubberyCreationForm();
	ShurubberyCreationForm(const std::string& target);
	ShurubberyCreationForm(const ShurubberyCreationForm& other);
	ShurubberyCreationForm& operator=(const ShurubberyCreationForm& other);
	virtual ~ShurubberyCreationForm();

	const std::string getTarget() const;

	virtual void executeAction() const;
};

#endif
