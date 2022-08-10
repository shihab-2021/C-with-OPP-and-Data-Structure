#include<iostream>

namespace one
{
    void fun()
    {
        std::cout << "I am namespace one" << std::endl;
    }
}

namespace two
{
    void fun()
    {
        std::cout << "I am namespace two" << std::endl;
    }
}

using namespace two;

int main()
{
    one::fun();
    fun();

    return 0;
}