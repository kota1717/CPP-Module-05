/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:31:21 by ikota             #+#    #+#             */
/*   Updated: 2026/02/24 17:31:31 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 掘削音のような音を発生させた後、<target>のロボトミー手術が50%の確率で正常に完了したことを通知します。
// 失敗した場合はロボトミー手術が失敗したことを通知します。

#include "RobotmyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("unknown") {}

RobotmyRequestForm::RobotmyRequestForm(const std::string& target)
	: AForm("Robotmy Request", 72, 45), _target(target) {}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotmyRequestForm& RobotmyRequestForm::operator=(const RobotmyRequestForm& other) {
	if (this == &other) {
		return *this;
	}
	_target = other._target;
	return *this;
}

RobotmyRequestForm::~RobotmyRequestForm() {}
