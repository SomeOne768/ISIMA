#include "Message.hpp"
#include <iostream>

int Message::cle = 0;
Message::Message(std::string exp, std::string dest, std::string date, std::string text) : expediteur(exp), destinataire(dest), date(date), text(text)
{
    id = cle;
    cle++;
}

Message::Message(std::string exp, std::string dest, std::string date) : Message(exp, dest, date, "") {}

void Message::setTexte(std::string t)
{
    text = t;
}

std::string Message::getTexte() const
{
    return text;
}

int Message::getCle()
{
    return cle;
}

int Message::getId() const
{
    return id;
}