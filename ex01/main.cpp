/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:43:40 by ikota             #+#    #+#             */
/*   Updated: 2026/02/19 15:57:17 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat("itirou", 0);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat("jirou", 151);
	} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
	}

	Bureaucrat saburou("saburou", 3);
	std::cout << saburou << std::endl;

	try {
		for (int i = 0; i < 5; i++) {
			saburou.incrementGrade();
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat shirou("shirou", 148);

	try {
		for (int i = 0; i < 5; i++) {
			shirou.decrementGrade();
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
