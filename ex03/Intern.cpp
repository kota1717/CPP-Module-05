/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:32:44 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:33:42 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace {
AForm* makeShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* makeRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* makePresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
}

Intern::Intern() {}

Intern::Intern(const Intern& other) {}

Intern& Intern::operator=(const Intern& other) {

}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form_title,
									const std::string& form_target) const {
  typedef AForm* (*MakeFormFuncs)(const std::string&);
  MakeFormFuncs helper_functions[] = {&makeShrubberyCreationForm,
                                      &makeRobotomyRequestForm,
                                      &makePresidentialPardonForm};
  const std::string titles[] = {"shruberry creation", "robotomy request",
                                "presidential pardon"};
  for (unsigned int i = 0; i < sizeof(titles) / sizeof(titles[0]); i++) {
    if (titles[i] == form_title) {
        return (helper_functions[i])(form_target);
    }
  }
  
}

// この関数は、パラメータとして渡されたフォーム名
// に対応するAFormオブジェクトへのポインタを返し、
// その対象は2つ目のパラメータで初期化されます。
// もし指定されたフォーム名が存在しない場合は、明確なエラーメッセージの出力
