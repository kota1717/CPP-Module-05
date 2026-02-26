/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:04:22 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 10:54:32 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _title("Unknown"),
      _is_signed(false),
      _grade_to_sign(Bureaucrat::getHighestGrade()),
      _grade_to_execute(Bureaucrat::getHighestGrade()) {}

Form::Form(const std::string title,
        const int grade_to_sign, const int grade_to_execute)
    : _title(title),
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

Form::Form(const Form& other)
    : _title(other._title),
      _is_signed(other._is_signed),
      _grade_to_sign(other._grade_to_sign),
      _grade_to_execute(other._grade_to_execute) {}

Form& Form::operator=(const Form& other) {
    if (this == &other) {
        return *this;
    }
    _is_signed = other._is_signed;
    return *this;
}

Form::~Form() {}

const std::string& Form::getTitle() const { return _title; }

bool Form::getIsSigned() const { return _is_signed; }

int Form::getGradeToSign() const { return _grade_to_sign; }

int Form::getGradeToExecute() const { return _grade_to_execute; }

void Form::beSigned(const Bureaucrat& other) {
    if (other.getGrade() > _grade_to_sign) {
        throw GradeTooLowException();
    }
    _is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw () {
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw () {
    return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form information:" << std::endl
       << "Name: " << form.getTitle() << std::endl
       << "Is signed? " << std::boolalpha << form.getIsSigned() << std::endl
       << "Grade required to sign: " << form.getGradeToSign() << std::endl
       << "Grade required to execute: " << form.getGradeToExecute();
    return os;
}
