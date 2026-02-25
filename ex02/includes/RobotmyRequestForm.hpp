/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:34 by ikota             #+#    #+#             */
/*   Updated: 2026/02/25 19:05:03 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_ROBOTMYREQUESTFORM_HPP_
#define EX02_ROBOTMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotmyRequestForm :public AForm {
	std::string _target;

public:
	RobotmyRequestForm();
	RobotmyRequestForm(const std::string& target);
	RobotmyRequestForm& operator=(const RobotmyRequestForm& other);
	virtual ~RobotmyRequestForm();

	const std::string RobotmyRequestForm::getTarget() const;

	virtual void executeAction() const;
};

#endif
