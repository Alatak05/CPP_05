#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other) {}

Intern& Intern::operator=(const Intern& other) 
{
    return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target)
{
    if(name != "ShrubberyCreationForm" || name != "RobotomyRequestForm" || name != "PresidentialPradonForm")
        return NULL;
    switch (name[0])
    {
        case 'S' :
            ShrubberyCreationForm *s = new ShrubberyCreationForm(target);
            return (s);
        case 'R' :
            RobotomyRequestForm *r = new RobotomyRequestForm(target);
            return (r);
        case 'P' :
            PresidentialPardonForm *f = new PresidentialPardonForm(target);
            return (f);
    }
}
