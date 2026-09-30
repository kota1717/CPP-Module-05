/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:31:21 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 10:58:56 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this == &other) {
		return *this;
	}
	_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "Vvvvvvvv...! (drilling noises)" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "The robotomy on " << getTarget() << " failed." << std::endl;
	}
}

