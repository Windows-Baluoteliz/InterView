#include <iostream>
using namespace std;

class CBase {
public:

    CBase::CBase() {
        cout<<__FUNCTION__<<endl;
    }

    CBase::CBase(int nNum): m_nNum(nNum){
        cout<<__FUNCTION__<<"nNum"<<endl;
    }

    CBase::CBase(const CBase& baseObj) {
        cout<<__FUNCTION__<<"baseObj"<<endl;
        *this = baseObj;
    }

    CBase& operator=(const CBase &baseObj) {

        cout<<__FUNCTION__<<"baseObj"<<endl;

        return *this;
    }

private:
    int m_nNum;

};

class CDerived {
public:
    CDerived::CDerived(int nNum):m_nNum(nNum) {
        cout<<__FUNCTION__<<"nNum"<<endl;
    }

private:
    int m_nNum;
};

int main() {

    //CBase A;
    //CBase A1(10);
    //CBase A2 = 10;
    //CBase B = A;
    CDerived b(10);

    
    return 0;
}
