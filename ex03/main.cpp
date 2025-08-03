#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "=== Ex03: Intern Tests ===" << std::endl;

    // Test 1: Create ShrubberyCreationForm via Intern
    std::cout << "\n--- Test 1: Create ShrubberyCreationForm ---" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        
        Bureaucrat alice("Alice", 100);
        std::cout << alice << std::endl;
        std::cout << *rrf << std::endl;
        
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        
        delete rrf;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Create RobotomyRequestForm via Intern
    std::cout << "\n--- Test 2: Create RobotomyRequestForm ---" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        Bureaucrat bob("Bob", 30);
        std::cout << bob << std::endl;
        std::cout << *rrf << std::endl;
        
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
        
        delete rrf;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Create PresidentialPardonForm via Intern
    std::cout << "\n--- Test 3: Create PresidentialPardonForm ---" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        
        Bureaucrat charlie("Charlie", 1);
        std::cout << charlie << std::endl;
        std::cout << *rrf << std::endl;
        
        charlie.signForm(*rrf);
        charlie.executeForm(*rrf);
        
        delete rrf;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Invalid form name
    std::cout << "\n--- Test 4: Invalid Form Name ---" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("invalid form", "Target");
        
        // This should not be reached
        std::cout << *rrf << std::endl;
        delete rrf;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Multiple Intern instances
    std::cout << "\n--- Test 5: Multiple Intern Instances ---" << std::endl;
    try {
        Intern intern1;
        Intern intern2;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "home");
        AForm* form2 = intern2.makeForm("robotomy request", "office");
        
        Bureaucrat david("David", 50);
        
        david.signForm(*form1);
        david.signForm(*form2);
        david.executeForm(*form1);
        david.executeForm(*form2);
        
        delete form1;
        delete form2;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Copy constructor and assignment operator
    std::cout << "\n--- Test 6: Copy Constructor and Assignment ---" << std::endl;
    try {
        Intern original;
        Intern copy(original);
        Intern assigned;
        assigned = original;
        
        AForm* form1 = copy.makeForm("shrubbery creation", "copy_target");
        AForm* form2 = assigned.makeForm("robotomy request", "assigned_target");
        
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        
        delete form1;
        delete form2;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Tests Complete ===" << std::endl;
    return 0;
}
