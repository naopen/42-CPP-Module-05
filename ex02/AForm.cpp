#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

// Parameterized constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

// Destructor
AForm::~AForm() {
}

// Assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Note: _name, _gradeToSign, and _gradeToExecute are const, so we can't assign them
        // For now, we only assign the _signed state
        _signed = other._signed;
    }
    return *this;
}

// Getters
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);
    executeAction();
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
