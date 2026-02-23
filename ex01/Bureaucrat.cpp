/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:45 by ikota             #+#    #+#             */
/*   Updated: 2026/02/19 16:02:24 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(s_LowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < s_HighestGrade) {
		throw GradeTooHighException();
	}
	if (grade > s_LowestGrade) {
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
	return s_LowestGrade;
}
	
int Bureaucrat::getHighestGrade() {
	return s_HighestGrade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
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
