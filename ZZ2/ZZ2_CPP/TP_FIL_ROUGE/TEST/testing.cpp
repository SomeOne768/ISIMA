#include <iostream>



int main()
{
    std::string s;
    printf("ffff\n");
    // std::cin >> s;
    // std::cout << "\nSaisie:" << s << "\n";

    // std::getline(std::cin, s);
    // std::cout << "\n" << s <<"\n";
    // std::string mode = s.substr(0, 5);

    // std::cout << mode << " pos " << s.find(" ", 6) << std::endl;
                // type = s.substr(6, )

    std::string mode,
                type,
                params;
    std::cin >> mode;
    std::cin >>type;
    std::getline(std::cin, params);

    printf("1:%s 2:%s 3:%s", mode.c_str(), type.c_str(), params.c_str());


    return 0;
}