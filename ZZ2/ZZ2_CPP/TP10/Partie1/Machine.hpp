#ifndef MACHINE__HPP_AZ
#define MACHINE__HPP_AZ

class Machine
{
protected:
    std::string nom;
    int autonomie;
    int ifixit;

public:
    Machine(std::string, int, int);

    const std::string getType() const;
    int getAutonomie() const;
    int getIfixit() const;
};

#endif