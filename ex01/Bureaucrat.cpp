#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const str, int val) : name(str), grade(val)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
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

int Bureaucrat::getGrade(void)
{
    return (grade);
}

void Bureaucrat::incr_grade(void)
{
    grade--;
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decr_grade(void)
{
    grade++;
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signedForm(Form& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& op, Bureaucrat& b)
{
    op << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return (op);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat::GradeTooHighException");
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat::GradeTooLowException");
}
