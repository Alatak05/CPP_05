#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::srand(std::time(0));

        ShrubberyCreationForm s1("home");
        ShrubberyCreationForm s2("jojo");
        RobotomyRequestForm r("salut");
        PresidentialPardonForm P("hello");
        Bureaucrat a("jean", 6);
        //a.signedForm(yo);
        // yo.execute(a);
        // a.signedForm(ye);
        // ye.execute(a);
        // a.signedForm(ya);
        // ya.execute(a);
        // a.signedForm(P);
        // P.execute(a);
        a.signedForm(s2);
        a.executeForm(s2);
        a.signedForm(s1);
        a.executeForm(s1);
        a.signedForm(P);
        a.executeForm(P);
        a.signedForm(r);
        a.executeForm(r);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
