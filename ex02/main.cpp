#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::srand(std::time(0));

        ShrubberyCreationForm yo("home");
        RobotomyRequestForm ya("salut");
        Bureaucrat a("jean", 1);
        a.signedForm(yo);
        yo.execute(a);
        ya.execute(a);
        a.signedForm(ya);
        ya.execute(a);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
