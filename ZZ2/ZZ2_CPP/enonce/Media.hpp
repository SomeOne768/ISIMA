#ifndef MEDIA_HPP_AZ
#define MEDIA_HPP_AZ
#include "SMS.hpp"

class Media
{
public:
    virtual std::string afficher() = 0;
    virtual ~Media(){};
};

class Son : public Media
{

public:
    virtual ~Son(){};
    virtual std::string afficher()
    {
        return "[[son]]";
    }
};

class Video : public Media
{
public:
    virtual ~Video(){};
    virtual std::string afficher()
    {
        return "[[video]]";
    }
};

class Image : public Media
{
public:
    virtual ~Image(){};
    virtual std::string afficher()
    {
        return "[[image]]";
    }
};

#endif