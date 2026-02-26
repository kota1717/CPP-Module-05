/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:04:19 by ikota             #+#    #+#             */
/*   Updated: 2026/02/23 13:55:24 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_AFORM_HPP_
#define EX03_AFORM_HPP_

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
    const std::string _title;
    bool _is_signed;
    const int _grade_to_sign;
    const int _grade_to_execute;

protected:
    virtual void executeAction() const = 0;

public:
    AForm();
    AForm(const std::string title,
        const int grade_to_sign, const int grade_to_execute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    ~AForm();
    const std::string& getTitle() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void execute(Bureaucrat const & executor) const;

    void beSigned(const Bureaucrat& other);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw ();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
