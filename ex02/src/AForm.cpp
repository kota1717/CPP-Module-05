/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:04:22 by ikota             #+#    #+#             */
/*   Updated: 2026/02/23 13:52:01 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Unknown"),
      _is_signed(false),
      _grade_to_sign(Bureaucrat::getHighestGrade()),
      _grade_to_execute(Bureaucrat::getHighestGrade()) {}

AForm::AForm(const std::string name,
        const int grade_to_sign, const int grade_to_execute)
    : _name(name),
      _is_signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {

    const int lowest_grade = Bureaucrat::getLowestGrade();
    const int highest_grade = Bureaucrat::getHighestGrade();

    if (grade_to_sign > lowest_grade || grade_to_execute > lowest_grade) {
        throw GradeTooLowException();
    }

    if (grade_to_sign < highest_grade || grade_to_execute < highest_grade) {
        throw GradeTooHighException();
    }
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _is_signed(other._is_signed),
      _grade_to_sign(other._grade_to_sign),
      _grade_to_execute(other._grade_to_execute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this == &other) {
        return *this;
    }
    _is_signed = other._is_signed;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _is_signed; }

int AForm::getGradeToSign() const { return _grade_to_sign; }

int AForm::getGradeToExecute() const { return _grade_to_execute; }

void AForm::beSigned(const Bureaucrat& other) {
    if (other.getGrade() > _grade_to_sign) {
        throw GradeTooLowException();
    }
    _is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw () {
    return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw () {
    return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "AForm information:" << std::endl
       << "Name: " << form.getName() << std::endl
       << "Is signed? " << std::boolalpha << form.getIsSigned() << std::endl
       << "Grade required to sign: " << form.getGradeToSign() << std::endl
       << "Grade required to execute: " << form.getGradeToExecute();
    return os;
}
