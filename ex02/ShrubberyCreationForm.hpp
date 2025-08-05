#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;

private:
    // Assignment operator is private because of const members
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    // Getters
    const std::string& getTarget() const;

    // Execution - using base class execute() method

protected:
    virtual void executeAction() const;
};

#endif
