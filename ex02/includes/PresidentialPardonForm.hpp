/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:31 by ikota             #+#    #+#             */
/*   Updated: 2026/02/24 16:50:10 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP_
#define EX02_PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm :public AForm {
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	virtual void executeAction() const;
};

#endif
