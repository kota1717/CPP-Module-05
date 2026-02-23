/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikota <ikota@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:04:22 by ikota             #+#    #+#             */
/*   Updated: 2026/02/19 16:04:23 by ikota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
    : _name("Unknown"),
      _is_signed(false),
      _grade_to_sign(Bureaucrat::getHighestGrade()),
      _grade_to_execute(Bureaucrat::getHighestGrade()) {}

Form::Form(const std::string name, 
        const int grade_to_sign, const int grade_to_execute) 
    : _name(name),
      _is_signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {

    // throwとかするみたい
}

Form::Form(const Form& other) 
    : _name(other._name),
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

const std::string& Form::getName() const { return _name; }
    
bool Form::getIsSigned() const { return _is_signed; };
    
const int Form::getGradeToSign() const { return _grade_to_sign; }
    
const int Form::getGradeToExecute() const { return _grade_to_execute; }

void Form::beSigned(Bureaucrat& bureaucrat) {
    //官僚の階級が必要以上であればフォームの状態を署名済みにする
    //階級が低すぎればForm::GradeTooLowExceptionにthrow
    
}

void Form::signForm() {
    //Form::beSigned()を呼び出してフォームへの署名を試みる必要がある
    //Formが正常に署名または失敗したらメッセージを出力する
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    
}