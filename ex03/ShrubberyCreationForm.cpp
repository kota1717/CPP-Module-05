/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:26:35 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:24:17 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm：必須グレード：sign 145、exec 137
// 作業ディレクトリ内に<target>_shrubberyというファイルを作成し、その内部にASCII形式の樹木データを書き込みます。

#include "ShrubberyCreationForm.hpp"

ShurubberyCreationForm::ShurubberyCreationForm()
	: AForm("Shurubbery Creation", 145, 137), _target("unknown") {}

ShurubberyCreationForm::ShurubberyCreationForm(const std::string& target)
	: AForm("Shurubbery Creation", 145, 137), _target(target) {}

ShurubberyCreationForm::ShurubberyCreationForm(const ShurubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShurubberyCreationForm& ShurubberyCreationForm::operator=(const ShurubberyCreationForm& other) {
	if (this == &other) {
		return *this;
	}
	_target = other._target;
	return *this;
}

ShurubberyCreationForm::~ShurubberyCreationForm() {}

const std::string ShurubberyCreationForm::getTarget() const {
	return _target;
}

void ShurubberyCreationForm::executeAction() const {
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open()) {
		std::cout << "Could'nt open file" << std::endl;
		return;
	}
	outfile << "     /\\    " << "\n"
          << "    /  \\   " << "\n"
          << "   /    \\  " << "\n"
          << "  /______\\ " << "\n"
          << "    | |     " << "\n";
}
