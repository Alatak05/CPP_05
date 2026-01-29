#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string const str, int val) : name(str), grade(val)
{
    if (grade < 1 || grade > 150)
        throw grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : name(other.getName()), grade(other.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName(void)
{
    return (name);
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

void Bureaucrat::incr_grade(void)
{
    grade--;
    if (grade < 1 || grade > 150)
    throw grade;
}

void Bureaucrat::decr_grade(void)
{
    grade++;
    if (grade < 1 || grade > 150)
    throw grade;
}

void Bureaucrat::signedForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << getName() << " couldn't sign " << f.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << getName() << " couldn't execute " << form.getName() << " because ";
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& op, Bureaucrat& b)
{
    op << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return (op);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat has GradeTooHighException");
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat has GradeTooLowException");
}
