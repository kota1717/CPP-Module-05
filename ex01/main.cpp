/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:40 by ikota             #+#    #+#             */
/*   Updated: 2026/02/23 14:33:48 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Form form("test1", 0, 100);
	} catch (const Form::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form("test2", 100, 0);
	} catch (const Form::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form("test3", 151, 100);
	} catch (const Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form("test4", 100, 151);
	} catch (const Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat ichiro("Ichiro", 40);
	Form test5("test5", 50, 30);
	std::cout << test5 << std::endl;
	ichiro.signForm(test5); // sign false -> true
	std::cout << test5 << std::endl;

	Bureaucrat jiro("jiro", 100);
	Form test6("test6", 50, 20);
	std::cout << test6 << std::endl;
	jiro.signForm(test6); // can't sign
	std::cout << test6 << std::endl;

	return 0;
}
