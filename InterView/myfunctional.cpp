#include <iostream>
#include <functional>
using namespace std;

typedef std::function<int(int)> Functional;

int fun1(int a) {
    return a;
}

auto lambda = [](int a) ->int {return a;};

class CTest {
public:
    int operator() (int a) {
        return a;
    }
};

class CTest1 {
public:
    int fun1( int a ) {
        return a;
    }

    static int fun2(int a) {
        return a;
    }
};

int main() {

    Functional obj = fun1;
    int nRes = obj(1);
    cout<<"normal function"<<nRes<<endl;

    obj = lambda;
    nRes = obj(2);
    cout<<"lambda funciton "<<nRes<<endl;

    CTest test;
    obj = test;
    nRes = obj(3);
    cout<<"functor"<<nRes<<endl;

    CTest1 test1;
    obj = std::bind(&CTest1::fun1,&test1,std::placeholders::_1);
    nRes = obj(4);
    cout<<"class member function"<<nRes<<endl;

    obj = CTest1::fun2;
    nRes = obj(5);
    cout<<"static function"<<nRes<<endl;
    
    return 0;
}
