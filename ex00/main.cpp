#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  a("Jean", 5);
        Bureaucrat  b(a);

        std::cout << a << std::endl;
        a.incr_grade();
        std::cout << a << std::endl;
        a.decr_grade();
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        a.incr_grade();
        b = a;
        std::cout << b << std::endl;
    }
    catch (int grade)
    {
        if (grade > 150)
            std::cout << "bureaucrat::GradeTooHighException\n";
        else
            std::cout << "bureaucrat::GradeTooLowException\n";
    }
    return 0;
}