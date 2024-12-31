#include "SMS.hpp"
#include <iostream>

SMS::SMS(std::string exp, std::string dest, std::string date) : SMS (exp, dest, date, "")
{}

SMS::SMS(std::string exp, std::string dest, std::string date, std::string text) : Message(exp, dest, date, text)
{}


std::string SMS::afficher() const 
{
    return this->text;
}

