#ifndef RESEAU_HPP_AZ
#define RESEAU_HPP_AZ
#include <iostream>
#include <vector>
#include "Telephone.hpp"
#include "SMS.hpp"
#include "MMS.hpp"

class Reseau
{
    std::vector<std::string> liste;
    std::vector<Telephone> tels;

public:
    Reseau();
    ~Reseau();
    void ajouter(std::string);
    std::string lister() const;

    Telephone& trouveTel(std::string);
    void envoyerSMS(SMS &s);
    void envoyerMMS(MMS *s);
};


#endif
