#include "Bureaucrat.hpp"

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

int Bureaucrat::getGrade(void)
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

std::ostream& operator<<(std::ostream& op, Bureaucrat& b)
{
    op << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
    return (op);
}