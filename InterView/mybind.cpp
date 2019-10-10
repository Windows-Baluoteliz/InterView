#include <iostream>
using namespace std;
#include <functional>
#include <memory>

void fun1(int a) {;}
void fun2() {;}

void fun3(int &n1,int &n2,const int &n3) {
    cout<<"In Function: "<<n1<<" "<<n2<<" "<<n3<<endl;
    n1++;
    n2++;
}

int main() {

    std::function<void(int)> pFun1 = fun1;
    std::function<void()> pFun2 = fun2;
    int n1 = 1;
    std::function<void()> bound_f = std::bind(fun1,n1);
    std::function<void()> bound_f1 = std::bind(fun2);
    bound_f();
    bound_f1();

    {
        int n1 = 1,n2=2,n3 = 3;
        std::function<void()> bound_f = std::bind(fun3,n1,std::ref(n2),std::cref(n3));
        n1 = 10;
        n2 = 11;
        n3 = 12;
        std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
        bound_f();
        std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    }
       
    return 0;
}
