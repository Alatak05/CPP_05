#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
        int             getGrade( void );
        void            incr_grade( void );
        void            decr_grade( void );
        
    };
    
std::ostream& operator<<(std::ostream& op, Bureaucrat& b);

#endif