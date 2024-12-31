#ifndef MESSAGE_HPP_AZ
#define MESSAGE_HPP_AZ
#include <iostream>


class Message
{
static int cle;
protected: 
    int id;
    static int compteur;
    std::string expediteur,
                destinataire,
                date,
                text;
    friend class Telephone;
    friend class Reseau;
public:
    Message(std::string, std::string, std::string, std::string);
    Message(std::string, std::string, std::string);
    virtual ~Message() {};
    virtual void setTexte(std::string);
    std::string getTexte() const;
    virtual std::string afficher() const = 0;
    static int getCle();
    std::string getDe() const
    {
        return expediteur;
    }
    std::string getA() const{
        return destinataire;
    }

    int getId() const;
};

#endif
