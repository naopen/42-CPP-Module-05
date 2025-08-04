#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Ex00: Bureaucrat Tests ===" << std::endl;

    // Test 1: Normal bureaucrat creation
    std::cout << "\n--- Test 1: Normal Creation ---" << std::endl;
    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Grade too high exception
    std::cout << "\n--- Test 2: Grade Too High ---" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Grade too low exception
    std::cout << "\n--- Test 3: Grade Too Low ---" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Increment grade functionality
    std::cout << "\n--- Test 4: Increment Grade ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 5);
        std::cout << "Before increment: " << alice << std::endl;
        alice.incrementGrade();
        std::cout << "After increment: " << alice << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Decrement grade functionality
    std::cout << "\n--- Test 5: Decrement Grade ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 140);
        std::cout << "Before decrement: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Increment grade boundary exception
    std::cout << "\n--- Test 6: Increment Boundary ---" << std::endl;
    try {
        Bureaucrat top("TopGrade", 1);
        std::cout << "Before increment: " << top << std::endl;
        top.incrementGrade();
        std::cout << "After increment: " << top << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 7: Decrement grade boundary exception
    std::cout << "\n--- Test 7: Decrement Boundary ---" << std::endl;
    try {
        Bureaucrat bottom("BottomGrade", 150);
        std::cout << "Before decrement: " << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << "After decrement: " << bottom << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 8: Copy constructor
    std::cout << "\n--- Test 8: Copy Constructor ---" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 9: Assignment operator
    std::cout << "\n--- Test 9: Assignment Operator ---" << std::endl;
    try {
        Bureaucrat first("First", 10);
        Bureaucrat second("Second", 100);
        std::cout << "Before assignment:" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << std::endl;
        
        second = first;  // Note: only grade is copied, name remains const
        std::cout << "After assignment:" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 10: Default constructor
    std::cout << "\n--- Test 10: Default Constructor ---" << std::endl;
    try {
        Bureaucrat defaultBureaucrat;
        std::cout << "Default: " << defaultBureaucrat << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Tests Complete ===" << std::endl;
    return 0;
}
