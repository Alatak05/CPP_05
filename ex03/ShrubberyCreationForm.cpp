#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : 
    AForm("ShrubberyCreationForm", 145, 137) , _target(name) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : 
    AForm(other) , _target(other._target)
{}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    check_to_exe(executor);
    std::string name;
    name = _target + "_shrubbery";
    std::ofstream file(name.c_str());

    if (!file)
        return ;
file << "                                           .\n"
        "                                              .         ;  \n"
        "                 .              .              ;%     ;;   \n"
        "                   ,           ,                :;%  %;   \n"
        "                    :         ;                   :;%;'     .,   \n"
        "           ,.        %;     %;            ;        %;'    ,;\n"
        "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
        "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
        "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
        "                `%;.     ;%;     %;'         `;%%;.%;'\n"
        "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
        "                    `:%;.  :;bd%;          %;@%;'\n"
        "                      `@%:.  :;%.         ;@@%;'   \n"
        "                        `@%.  `;@%.      ;@@%;         \n"
        "                          `@%%. `@%%    ;@@%;        \n"
        "                            ;@%. :@%%  %@@%;       \n"
        "                              %@bd%%%bd%%:;     \n"
        "                                #@%%%%%:;;\n"
        "                                %@@%%%::;\n"
        "                                %@@@%(o);  . '         \n"
        "                                %@@@o%;:(.,'         \n"
        "                            `.. %@@@o%::;         \n"
        "                               `)@@@o%::;         \n"
        "                                %@@(o)::;        \n"
        "                               .%@@@@%::;         \n"
        "                               ;%@@@@%::;.          \n"
        "                              ;%@@@@%%:;;;. \n"
        "                          ...;%@@@@@%%:;;;;,.. \n";      
}
