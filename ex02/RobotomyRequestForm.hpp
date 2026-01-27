#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
    private :
        std::string _target;
    
    public :
        RobotomyRequestForm(std::string t);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};