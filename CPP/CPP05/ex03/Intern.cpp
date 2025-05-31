#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    typedef AForm* (Intern::*FormCreator)(const std::string&);
    
    struct FormEntry {
        std::string name;
        FormCreator creator;
    };
    
    const FormEntry forms[] = {
        { "presidential pardon", &Intern::createPresidential },
        { "robotomy request", &Intern::createRobotomy },
        { "shrubbery creation", &Intern::createShrubbery }
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << " now" << std::endl;
            return (this->*forms[i].creator)(target);
        }
    }

    std::cout << "\033[33mIntern cannot create a form called " << formName << "\033[0m" << std::endl;
    return NULL;
}

AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}