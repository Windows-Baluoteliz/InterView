#include <iostream>
#include <typeinfo>

/*
* Typeid can be object ,or typename.
*/
int main() {

    typedef std::conditional<true,int,double>::type Type1;
    typedef std::conditional<false,int,double>::type Type2;
    typedef std::conditional<sizeof(int) >= sizeof(double),int,double>::type Type3;

    double dd= 1.0;
    int nLen = 1;
    typedef int dd1;

    std::cout<<typeid(Type1).name()<<std::endl;
    std::cout<<typeid(Type2).name()<<std::endl;
    std::cout<<typeid(Type3).name()<<std::endl;
    std::cout<<typeid(dd).name()<<std::endl;
    std::cout<<typeid(dd1).name()<<std::endl;


    return 0;
}
