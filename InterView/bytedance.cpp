#include <iostream>
using namespace std;
#include <string.h>

/*
* 指定l:数据其实位置,p:从l开始的数据长度,
* 然后左右对称重置这个段数据,插入到之前指定的数据段的尾部.
* 输出新的字符串.
*/
void fun1() {
    char szbufSrc[20] = {0};
    char szbufDest[1024] = {0};
    cin>>szbufSrc;
    strcpy(szbufDest,szbufSrc);
    int nStep = 0;
    cin>>nStep;

    for(int i = 0 ; i < nStep;i++) {
        char *pStrTemp = NULL;
        int l,p = 0;
        cin>>l>>p;
        int nTempLen = strlen(szbufDest) - l + 1;
        pStrTemp = new char[nTempLen];
        for(int n = 0 ; n < nTempLen - 1; n++) {
            if(n < p)
                pStrTemp[n] = szbufDest[l + p - 1 - n];
            else
                pStrTemp[n] = szbufDest[l + n];
        }
        pStrTemp[nTempLen -1] = '\0';
        char *pTemp = &(szbufDest[l + p]);
        strcpy(pTemp,pStrTemp);
        delete [] pStrTemp;
        cout<<szbufDest<<endl;
    }

    cout<<szbufDest<<endl;
}

void fun2() {
    int nStep = 0;
    cin>>nStep;
    std::string *pStrString = new std::string[nStep];
    for(int n = 0; n < nStep ; n++) {
        std::string strTemp;
    }
}

int main() {
    fun2();
    return 0;
}
