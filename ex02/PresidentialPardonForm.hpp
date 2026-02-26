/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:31 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:11:11 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP_
#define EX02_PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm :public AForm {
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	const std::string getTarget() const;

	virtual void executeAction() const;
};

#endif
