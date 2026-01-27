#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class Form
{
    private :
        std::string const name;
        bool    is_signed;
        int const grade_sign;
        int const grade_ex;
    
    public :
        Form(const std::string, int gs, int ge);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form(void);

        std::string getName(void) const;
        bool getis_signed(void) const;
        int getGradeSign(void) const;
        int getGradeEx(void) const;

        void beSigned(Bureaucrat& b);
        void check_to_exe(const Bureaucrat& b) const;
        virtual void execute(Bureaucrat const & executor) const = 0;


        class GradeTooHighException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        class NotSigned : public std::exception
        {
            public :
                const char* what() const throw();
        };
};
    
std::ostream& operator<<(std::ostream& op, Form& f);

#endif