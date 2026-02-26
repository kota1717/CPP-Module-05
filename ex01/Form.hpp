/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:04:19 by ikota             #+#    #+#             */
/*   Updated: 2026/02/26 10:54:24 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP_
#define EX01_FORM_HPP_

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
    const std::string _title;
    bool _is_signed;
    const int _grade_to_sign;
    const int _grade_to_execute;

public:
    Form();
    Form(const std::string title,
        const int grade_to_sign, const int grade_to_execute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    const std::string& getTitle() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& other);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
