#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n\033[1;34m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
    try {
        printHeader("Testing Intern Form Creation");
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 140);

        AForm* forms[] = {
            someRandomIntern.makeForm("shrubbery creation", "Garden"),
            someRandomIntern.makeForm("robotomy request", "Bender"),
            someRandomIntern.makeForm("presidential pardon", "Criminal"),
            someRandomIntern.makeForm("invalid form", "Target")
        };

        printHeader("Testing Valid Forms");
        for (int i = 0; i < 3; ++i) {
            if (forms[i]) {
                std::cout << *forms[i] << std::endl;
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                std::cout << std::endl;
            }
        }

        printHeader("Testing Grade Requirements");
        if (forms[0]) {  // Shrubbery form
            worker.signForm(*forms[0]);
            worker.executeForm(*forms[0]);
        }

        for (int i = 0; i < 3; ++i) {
            delete forms[i];
        }

        printHeader("Testing Multiple Robotomy Attempts");
        AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Robot");
        if (robotomyForm) {
            boss.signForm(*robotomyForm);
            for (int i = 0; i < 5; ++i) {
                boss.executeForm(*robotomyForm);
            }
            delete robotomyForm;
        }

    } catch (std::exception& e) {
        std::cout << "\033[1;31mException: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
