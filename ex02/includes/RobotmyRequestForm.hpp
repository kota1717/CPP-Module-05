/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:12:34 by ikota             #+#    #+#             */
/*   Updated: 2026/02/24 16:50:19 by ikota            ###   ########.fr       */
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

	virtual void executeAction() const;
};

#endif
