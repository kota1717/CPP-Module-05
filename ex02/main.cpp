/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:40 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 11:42:48 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat ichiro("ichiro", 1);
	ShrubberyCreationForm shrubbery_form("home");

	ichiro.signForm(shrubbery_form);
	ichiro.executeForm(shrubbery_form);

	Bureaucrat jiro("jiro", 44);
	RobotomyRequestForm robotomy_form("robot");

	jiro.signForm(robotomy_form);
	jiro.executeForm(robotomy_form);

	Bureaucrat saburo("saburo", 3);
	PresidentialPardonForm president_form("president");

	saburo.signForm(president_form);
	saburo.executeForm(president_form);

	return 0;
}
