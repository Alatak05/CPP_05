#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
    private :
        std::string _target;

    public :
        ShrubberyCreationForm(const std::string& name);
        ShrubberyCreationForm(ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};