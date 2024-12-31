#ifndef BAVARDE_HPP_AZ
#define BAVARDE_HPP_AZ


class Bavarde
{
private:
    int x;
public:
    Bavarde(/* args */);
    Bavarde(int);
    Bavarde& operator=(const Bavarde &b);//copie 
    ~Bavarde();
    int getX();
    void afficher();

} bizarre(1);

#endif