#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
    private :
        std::string const   name;
        int                 grade;

    public :
        Bureaucrat(std::string const str, int val);
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
        std::string     getName( void );
        int             getGrade( void ) const;
        void            incr_grade( void );
        void            decr_grade( void );

        void signedForm(Form& f);

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
    };
    
std::ostream& operator<<(std::ostream& op, Bureaucrat& b);

#endif