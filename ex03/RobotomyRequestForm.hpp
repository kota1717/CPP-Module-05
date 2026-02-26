/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:34 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:32:57 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_ROBOTOMYREQUESTFORM_HPP_
#define EX03_ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

#include <cstdlib>

class RobotomyRequestForm :public AForm {
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

	const std::string getTarget() const;

	virtual void executeAction() const;
};

#endif
