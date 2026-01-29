#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string n, int gs, int ge) : name(n), is_signed(false), grade_sign(gs), grade_ex(ge)
{
    if (grade_sign > 150 || grade_ex > 150)
        throw AForm::GradeTooHighException();
    else if (grade_sign < 1 || grade_ex < 1)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
            name(other.getName()),
            is_signed(getis_signed()),
            grade_sign(getGradeSign()),
            grade_ex(getGradeEx())
{
    std::cout << "AForm copie constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->is_signed = other.getis_signed();
    }
    return (*this);
}

AForm::~AForm(void) {}

std::string AForm::getName(void) const
{
    return (name);
}

bool    AForm::getis_signed(void) const
{
    return (is_signed);
}

int AForm::getGradeSign(void) const
{
    return (grade_sign);
}

int AForm::getGradeEx(void) const
{
    return (grade_ex);
}

void    AForm::beSigned(Bureaucrat& b)
{
    if(b.getGrade() <= getGradeSign())
        is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::check_to_exe(const Bureaucrat& b) const
{
    if(is_signed == false)
        throw AForm::NotSigned();
    if(grade_ex < b.getGrade())
        throw AForm::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& op, AForm& f)
{
    op << "Name AForm : " << f.getName() << "| is_signed : " << f.getis_signed() << "| grade required to sign it : " << f.getGradeSign() << "| grade required to execute it : " << f.getGradeEx();
    return (op);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("AForm has GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("AForm has GradeTooLowException");
}

const char* AForm::NotSigned::what() const throw()
{
    return("AForm has NotSigned");
}
