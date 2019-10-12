#include "SingletonTemplate.h"
#include <iostream>
using namespace std;

class C1 :public CSingleton<C1> {

};

C1* C1::CSingleton::pInstance_ = nullptr;
LPCRITICAL_SECTION C1::CSingleton::pCritical_Section = nullptr;
std::unique_ptr<C1::CSingleton::CGrabo> C1::CSingleton::pGrabo(new C1::CSingleton::CGrabo);

class C2 : public CSingleton<C2> {

};

C2* C2::CSingleton::pInstance_ = nullptr;
LPCRITICAL_SECTION C2::CSingleton::pCritical_Section = nullptr;
std::unique_ptr<C2::CSingleton::CGrabo> C2::CSingleton::pGrabo(new C2::CSingleton::CGrabo);

int main() {

    C1::getInstance();
    C2::getInstance();

    C1::getInstance();
    C2::getInstance();

    return 0;
}
