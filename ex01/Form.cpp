#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

// Parameterized constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

// Destructor
Form::~Form() {
}

// Assignment operator
// Note: const members (_name, _gradeToSign, _gradeToExecute) cannot be reassigned
// Only _signed state can be copied - this is a limitation of const members
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // Only non-const members can be assigned
        // _name, _gradeToSign, and _gradeToExecute remain unchanged
        _signed = other._signed;
    }
    return *this;
}

// Getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
