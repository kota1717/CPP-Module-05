/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:31:46 by ikota             #+#    #+#             */
/*   Updated: 2026/02/25 19:12:46 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm：必須グレード：sign 25、exec 5
// <target>がザフォド・ビーブルブロックスによって恩赦を受けたことを通知します。
// これらのクラスはすべてコンストラクタに1つのパラメータのみを必要とします：フォームの対象です。
// 例えば、自宅で低木を植える場合は「home」を指定します。

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), _target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string& target)
	: AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this == &other) {
		return *this;
	}
	_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::executeAction() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
