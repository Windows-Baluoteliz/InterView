#include <iostream>
using namespace std;

class A1 {
    virtual void fun();
};

class A2{
    int m_nNum;
    char ch;
    double ff;
};

class A3 : public A1 {
    int m_nNum;
    static int m_nCount;
};
int A3::m_nCount = 0;

class A4 : virtual public A1 {

};

int main() {

    cout<<sizeof(A1)<<endl;
    cout<<sizeof(A2)<<endl;
    cout<<sizeof(A3)<<endl;
    cout<<sizeof(A4)<<endl;

    system("pause");
    return 0;
}
