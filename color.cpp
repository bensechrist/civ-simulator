#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
    std::string default_console = "\033[0m";
    for (int i = 30; i <= 57; i++)
    {
        std::cout<<"\033[0;"<<i<<"m"<<"test "<<i<<std::endl;

        std::cout<<"\033[1"<<i<<"m"<<"test "<<i<<" bold"<<std::endl;
        std::cout<<default_console<<std::endl;

    }

    std::cout << "Done" << std::endl;

    return 0;
}
