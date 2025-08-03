#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);

    // Member function
    AForm* makeForm(const std::string& formName, const std::string& target);

    // Exception class
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    // Private member functions for form creation
    AForm* makeShrubberyCreationForm(const std::string& target);
    AForm* makeRobotomyRequestForm(const std::string& target);
    AForm* makePresidentialPardonForm(const std::string& target);
};

#endif
