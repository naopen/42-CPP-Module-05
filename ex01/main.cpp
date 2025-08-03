#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Ex01: Form and Bureaucrat Tests ===" << std::endl;

    // Test 1: Normal form creation
    std::cout << "\n--- Test 1: Normal Form Creation ---" << std::endl;
    try {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Form with invalid grades
    std::cout << "\n--- Test 2: Invalid Form Grades ---" << std::endl;
    try {
        Form invalidForm("Invalid Form", 0, 25);
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid Form 2", 25, 151);
        std::cout << invalidForm2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Successful form signing
    std::cout << "\n--- Test 3: Successful Form Signing ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form importantForm("Important Form", 50, 25);
        
        std::cout << "Before signing:" << std::endl;
        std::cout << alice << std::endl;
        std::cout << importantForm << std::endl;
        
        alice.signForm(importantForm);
        
        std::cout << "After signing:" << std::endl;
        std::cout << importantForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Failed form signing (grade too low)
    std::cout << "\n--- Test 4: Failed Form Signing ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form restrictedForm("Restricted Form", 50, 25);
        
        std::cout << "Before signing attempt:" << std::endl;
        std::cout << bob << std::endl;
        std::cout << restrictedForm << std::endl;
        
        bob.signForm(restrictedForm);
        
        std::cout << "After signing attempt:" << std::endl;
        std::cout << restrictedForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Direct beSigned() call
    std::cout << "\n--- Test 5: Direct beSigned() Call ---" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 20);
        Form directForm("Direct Form", 30, 15);
        
        std::cout << "Before beSigned():" << std::endl;
        std::cout << directForm << std::endl;
        
        directForm.beSigned(charlie);
        
        std::cout << "After beSigned():" << std::endl;
        std::cout << directForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Direct beSigned() failure
    std::cout << "\n--- Test 6: Direct beSigned() Failure ---" << std::endl;
    try {
        Bureaucrat david("David", 100);
        Form highGradeForm("High Grade Form", 50, 25);
        
        std::cout << "Before beSigned():" << std::endl;
        std::cout << highGradeForm << std::endl;
        
        highGradeForm.beSigned(david);
        
        std::cout << "After beSigned():" << std::endl;
        std::cout << highGradeForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Tests Complete ===" << std::endl;
    return 0;
}
