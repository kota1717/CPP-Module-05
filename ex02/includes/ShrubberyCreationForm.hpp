/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:36 by ikota             #+#    #+#             */
/*   Updated: 2026/02/25 18:50:21 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP_
#define EX02_SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <fstream>

class ShurubberyCreationForm :public AForm {
	std::string _target;

public:
	ShurubberyCreationForm();
	ShurubberyCreationForm(const std::string& target);
	ShurubberyCreationForm& operator=(const ShurubberyCreationForm& other);
	virtual ~ShurubberyCreationForm();

	const std::string getTarget() const;

	virtual void executeAction() const;
};

#endif
