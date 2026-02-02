#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  a("Jean", 555);
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
    catch (std::exception & e)
    {
        std::cout << "Warning : " << e.what() << std::endl;
    }
    return 0;
}