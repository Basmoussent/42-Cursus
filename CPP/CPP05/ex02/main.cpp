#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Test ShrubberyCreationForm
        Bureaucrat b1("John", 136);
        ShrubberyCreationForm sf("garden");
        std::cout << sf << std::endl;
        b1.signForm(sf);
        b1.executeForm(sf);

        // Test RobotomyRequestForm
        Bureaucrat b2("Jane", 44);
        RobotomyRequestForm rf("target1");
        std::cout << rf << std::endl;
        b2.signForm(rf);
        b2.executeForm(rf);

        // Test PresidentialPardonForm
        Bureaucrat b3("Boss", 4);
        PresidentialPardonForm pf("criminal");
        std::cout << pf << std::endl;
        b3.signForm(pf);
        b3.executeForm(pf);

        // Test execution without signing
        RobotomyRequestForm rf2("target2");
        b2.executeForm(rf2);

        // Test execution with insufficient grade
        Bureaucrat b4("Lowrank", 150);
        b4.executeForm(sf);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
