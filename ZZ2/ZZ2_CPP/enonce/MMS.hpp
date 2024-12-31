#ifndef MMS_HPP_AZ
#define MMS_HPP_AZ
#include "Media.hpp"
#include "SMS.hpp"
#include <vector>
#include <iostream>

class MMS : public SMS, public Media 
{
    std::vector<Media*> medias;
public:
    MMS(std::string exp, std::string dest, std::string date) : SMS(exp, dest, date), Media()
    {}

    void joindre(Media *m)
    {
        medias.push_back(m);
        text += m->afficher();
    }

    void setTexte(std::string s) override{
        text = s;
        for(Media* elt : medias)
        {
            text += elt->afficher();
        }
    }

    virtual std::string afficher()
    {
        return text;
    }
};

#endif