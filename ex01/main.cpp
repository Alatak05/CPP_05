#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form        f("Form a", 4, 5);
        Bureaucrat  a("Jean", 5);

        std::cout << a << std::endl;
        a.incr_grade();
        std::cout << a << std::endl;
        a.decr_grade();
        std::cout << a << std::endl;
        std::cout << f << std::endl;
        a.signedForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}