#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target) {
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // Note: _target is const, so we can't assign it
    }
    return *this;
}

// Getters
const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}

// Protected member function
void RobotomyRequestForm::executeAction() const {
    std::cout << "* drilling noises *" << std::endl;
    
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // 50% chance of success
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy of " << _target << " failed!" << std::endl;
    }
}
