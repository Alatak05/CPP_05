#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string n, int gs, int ge) : name(n), is_signed(false), grade_sign(gs), grade_ex(ge)
{
    std::cout << "Form constructor called" << std::endl;
    if (grade_sign > 150 || grade_ex > 150)
        throw Form::GradeTooHighException();
    else if (grade_sign < 1 || grade_ex < 1)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : 
            name(other.getName()),
            is_signed(getis_signed()),
            grade_sign(getGradeSign()),
            grade_ex(getGradeEx())
{
    std::cout << "Form copie constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.getis_signed();
    }
    return (*this);
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName(void) const
{
    return (name);
}

bool    Form::getis_signed(void) const
{
    return (is_signed);
}

int Form::getGradeSign(void) const
{
    return (grade_sign);
}

int Form::getGradeEx(void) const
{
    return (grade_ex);
}

void    Form::beSigned(Bureaucrat& b)
{
    if(b.getGrade() <= getGradeSign())
        is_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& op, Form& f)
{
    op << "Name form : " << f.getName() << "| is_signed : " << f.getis_signed() << "| grade required to sign it : " << f.getGradeSign() << "| grade required to execute it : " << f.getGradeEx();
    return (op);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Form::GradeTooHighException");
}


const char* Form::GradeTooLowException::what() const throw()
{
    return("Form::GradeTooLowException");
}
