/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:26:35 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:39:12 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm：必須グレード：sign 145、exec 137
// 作業ディレクトリ内に<target>_shrubberyというファイルを作成し、その内部にASCII形式の樹木データを書き込みます。

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("nowhere") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this == &other) {
		return *this;
	}
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::executeAction() const {
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
