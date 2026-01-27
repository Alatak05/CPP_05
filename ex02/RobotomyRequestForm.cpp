#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string t) 
    : Form("RobotomyRequestForm", 72, 45), _target(t)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : Form(other), _target(other._target) 
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        Form::operator=(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    check_to_exe(executor);
    std::cout << "Bzzzzz KKKK AAAAAAAAAAA\n AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n QASDXERSTGQSRWESYWDSEWYDSRYTSD...\n FOR SHHUUUUURRRRR" << std::endl;
    if ((std::rand() % 2) == 0)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << _target << " hasn't been robotomized." << std::endl;
}
