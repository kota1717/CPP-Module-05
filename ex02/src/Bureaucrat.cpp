/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:11:16 by ikota             #+#    #+#             */
/*   Updated: 2026/02/23 16:16:03 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(s_lowest_grade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < s_highest_grade) {
		throw GradeTooHighException();
	}
	if (grade > s_lowest_grade) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) {
		return *this;
	}
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

int Bureaucrat::getLowestGrade() {
	return s_lowest_grade;
}

int Bureaucrat::getHighestGrade() {
	return s_highest_grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= s_highest_grade)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= s_lowest_grade)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
}

void Bureaucrat::signForm(AForm& form) const {
	if (form.getIsSigned()) {
		std::cout << "Form is already signed." << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << _name << " couldn't sign "
		<< form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const {

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too Low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
