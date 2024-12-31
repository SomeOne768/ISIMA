#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <experimental/random>
#include <numeric>
#include <iterator>
// Uca.pereda.fr/cpp
class ZZ
{
    std::string nom, prenom;
    double note;

public:
    ZZ(std::string nom, std::string prenom): nom(nom), prenom(prenom) {}
    // l'operator<() pour comparer des éléments (ordre);
    // bool operator<(const ZZ z) const
    // {
    //     return note > z.note;
    // }
    bool operator<(const ZZ z) const
    {
        int out =  strcmp(nom.c_str(), z.nom.c_str());
        if(out == 0)
            out = strcmp(prenom.c_str(), z.prenom.c_str());
        return out > 0;
    }

    const std::string getName() const
    {
        return nom;
    }

    const std::string getFirstname() const
    {
        return prenom;
    }
};

std::ostream &operator<<(std::ostream &oss,const ZZ &z)
{
    oss << z.getFirstname() << " " << z.getName() ;
    return oss;   
}

class Rand_0_100 
{
    int a = 0,
        b = 100;
public:
  Rand_0_100(){}
  Rand_0_100(int min, int max){
    a = min;
    b = max;
  }

  int rand(){
    return std::experimental::randint(a, b);
  }

  int operator()()
  {
    return rand();
  }
};

class Fibo 
{
    long int un_1 = 1, un = 0;
public:
    Fibo() {}

    int operator()()
    {
        long int out = un;
        un_1 += un;
        un = un_1 - un;
        return out;
    }

};

class SpecialStringSort 
{
public: 
    SpecialStringSort() {}

    int operator()(const std::string s1, const std::string s2) const 
    {
        std::string subs1 = s1.substr(1);
        std::string subs2 = s2.substr(1);
        return subs1 < subs2;
    }
};


int main()
{
//     using vzz = std::vector<ZZ> ;

//     vzz zz;

//    zz.push_back(ZZ( "zoghlami", "jalil" ));
//    zz.push_back(ZZ( "zoghlami", "abdeljalil" ));
//    zz.push_back(ZZ( "0zoghlami", "jalil" ));
//    zz.push_back(ZZ( "zoghlami", "9jalil" ));
//    zz.push_back(ZZ( "zoghlami", "4jalil" ));

    // std::priority_queue<ZZ> tri;

    // for (vzz::iterator it = zz.begin();
    //      it != zz.end(); ++it)
    //     tri.push(*it);

    // while (!tri.empty())
    // {
    //     std::cout << tri.top() << " ";
    //     tri.pop();
    // }


    /******* 2 Exemples simples  ********/
    // 2.1 Rand 0 a 100
    Rand_0_100 r{};
    std::cout << "alea: " << r.rand() << "\n";

    // std::vector<int> v(50);
    // std::generate(v.begin(), v.end(), r);
    // for(auto it = v.begin(); it!=v.end(); ++it)
    // {
    //     std::cout << " " << *it;
    // }

    // std::vector<int> v(50);
    // std::generate_n(v.begin(), 50, r);
    // for(auto it = v.begin(); it!=v.end(); ++it)
    // {
    //     std::cout << " " << *it;
    // }


    // Back inserter à finir

    //std::accumulate
    // std::vector<int> v(50);
    // std::generate_n(v.begin(), 50, r);
    // int moyenne = std::accumulate(v.begin(), v.end(), 0)/50;
    // std::cout << "moyenne: " << moyenne << "\n";

    // auto min = std::min_element(v.begin(), v.end());
    // auto max = std::max_element(v.begin(), v.end());

    // std::cout << "min: " << *min << "\n max: " << *max << "\n";

    // std::generate_n(v.begin(), 50, Rand_0_100(0, 230));
    
    // min = std::min_element(v.begin(), v.end());
    // max = std::max_element(v.begin(), v.end());
    // std::cout << "min: " << *min << "\n max: " << *max << "\n";

    // Fibo f{};

    // int n = 50;
    // std::vector<int> v(n);
    // std::generate_n(v.begin(), n, f);

    // for(auto it=v.begin(); it!=v.end(); ++it)
    // {
    //     std::cout << " " << *it;
    // }

    // std::back_insert_iterator<std::vector<int> > dest (v);
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));


    // Partie 3
    //tri avec notre propre predicat
    std::vector<std::string> v(2);
    v.push_back("Machaine1");
    v.push_back("Machaine0");

    std::sort(v.begin(), v.end(), SpecialStringSort{});


    return 0;
}