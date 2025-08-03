#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== Ex02: AForm and Concrete Forms Tests ===" << std::endl;

    // Test 1: ShrubberyCreationForm
    std::cout << "\n--- Test 1: ShrubberyCreationForm ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 100);
        ShrubberyCreationForm shrubForm("home");
        
        std::cout << alice << std::endl;
        std::cout << shrubForm << std::endl;
        
        alice.signForm(shrubForm);
        alice.executeForm(shrubForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: RobotomyRequestForm
    std::cout << "\n--- Test 2: RobotomyRequestForm ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 30);
        RobotomyRequestForm robotForm("Bender");
        
        std::cout << bob << std::endl;
        std::cout << robotForm << std::endl;
        
        bob.signForm(robotForm);
        bob.executeForm(robotForm);
        
        // Try executing again to see different random result
        bob.executeForm(robotForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: PresidentialPardonForm
    std::cout << "\n--- Test 3: PresidentialPardonForm ---" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 1);
        PresidentialPardonForm pardonForm("Arthur Dent");
        
        std::cout << charlie << std::endl;
        std::cout << pardonForm << std::endl;
        
        charlie.signForm(pardonForm);
        charlie.executeForm(pardonForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Insufficient grade for signing
    std::cout << "\n--- Test 4: Insufficient Grade for Signing ---" << std::endl;
    try {
        Bureaucrat david("David", 150);
        PresidentialPardonForm pardonForm("Ford Prefect");
        
        david.signForm(pardonForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Insufficient grade for execution
    std::cout << "\n--- Test 5: Insufficient Grade for Execution ---" << std::endl;
    try {
        Bureaucrat eve("Eve", 25);
        Bureaucrat frank("Frank", 50);
        PresidentialPardonForm pardonForm("Trillian");
        
        // Eve can sign but Frank cannot execute
        eve.signForm(pardonForm);
        frank.executeForm(pardonForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Execution without signing
    std::cout << "\n--- Test 6: Execution Without Signing ---" << std::endl;
    try {
        Bureaucrat george("George", 1);
        ShrubberyCreationForm unsignedForm("garden");
        
        george.executeForm(unsignedForm);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Tests Complete ===" << std::endl;
    return 0;
}
