/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:43 by ikota             #+#    #+#             */
/*   Updated: 2026/02/23 16:15:13 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_BUREAUCRAT_HPP_
#define	EX02_BUREAUCRAT_HPP_

#include <iostream>

#include "AForm.hpp"

class Bureaucrat {
	const std::string _name;
	int _grade;
	static const int s_highest_grade = 1;
	static const int s_lowest_grade = 150;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;
	static int getLowestGrade() ;
	static int getHighestGrade() ;
	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& form) const;
	void executeForm(AForm const& form) const;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif
