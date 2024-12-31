#ifndef __SMS
#define __SMS
#include "Message.hpp"

class SMS : public Message
{

protected:
    friend class Reseau;
public:
    SMS(std::string, std::string, std::string);
    SMS(std::string, std::string, std::string, std::string);
    virtual ~SMS(){}
    virtual std::string afficher() const;
};

#endif