#include "Intern.hpp"

// Default constructor
Intern::Intern() {
}

// Copy constructor
Intern::Intern(const Intern& other) {
    (void)other; // Suppress unused parameter warning
}

// Destructor
Intern::~Intern() {
}

// Assignment operator
Intern& Intern::operator=(const Intern& other) {
    (void)other; // Suppress unused parameter warning
    return *this;
}

// Member function
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Array of form names
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    // Array of pointers to member functions
    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };
    
    // Find the matching form name and create the form
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    
    // If no form name matches, throw exception
    throw FormNotFoundException();
}

// Private member functions for form creation
AForm* Intern::makeShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Exception implementation
const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
