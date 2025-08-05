#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

private:
    // Assignment operator is private because of const members
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    // Getters
    const std::string& getTarget() const;

    // Execution - using base class execute() method

protected:
    virtual void executeAction() const;
};

#endif
