#include <iostream>
#include <istream>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;

int fun1() {//get the last string length.
    
    std::string sTemp;
    getline(std::cin,sTemp);
    int nIndex = sTemp.rfind(" ");
    return nIndex >= 0 ? (sTemp.length() - nIndex - 1) : (sTemp.length());
}

int fun2() {//get the count for same charecters no matter upper/lower case.
    std::string sTemp;
    getline(std::cin,sTemp);
    char ch;
    ch = getchar();
    int nResult = 0;
    int nIndex = 0; 
    for(;nIndex < sTemp.length(); nIndex++) {
        char chTemp = sTemp[nIndex];
        int nGap = 'a' - 'A';
        if( (ch == chTemp) || (ch == chTemp + nGap) || (ch == chTemp - nGap) )
            nResult++;
    }

    return nResult;
}

int  partition(int *pNum,int l,int h) {
    
        int k = l;
        for(int nIndex = l; nIndex < h; nIndex++) {
            if(pNum[nIndex] < pNum[h]) {
                std::swap(pNum[k++],pNum[nIndex]);
            }
        }

        std::swap(pNum[k],pNum[h]);
        return k;
}

void quick_sort(int *pNum,int l,int h) {

    if(l < h) {
        int k = partition(pNum,l,h);
        quick_sort(pNum,l,k - 1);
        quick_sort(pNum,k+1,h);
    }
}

void fun3() {//quick_sort.
    int nCount;
    std::cin>>nCount;
    int *pNum = new int[nCount];

    for(int nIndex = 0; nIndex < nCount;nIndex++) {
        std::cin>>pNum[nIndex];
    }

    quick_sort(pNum,0,nCount - 1);

    for(int nIndex= 0; nIndex < nCount; nIndex++) {
        cout<<pNum[nIndex]<<endl;
    }
}

void fun4() {//array for sort.
    int nNum;
    int a[1024] = {0};
    if(cin>>nNum) {
        for(int nIndex = 0; nIndex < nNum; nIndex++) {
            int nTemp = 0;
            cin>>nTemp;
            a[nTemp] +=1;
        }
    }

    for(int nIndex = 0; nIndex < 1024;nIndex++) {
        while(a[nIndex]) {
            cout<<nIndex<<endl;
            a[nIndex]--;
        }
    }
}

void fun5() {//map for sort 
    int n = 0;
    std::map<int,int> mapValue;
    if(cin>>n) {
        for(int nIndex= 0; nIndex < n;nIndex++) {
            int nTemp = 0;
            cin>>nTemp;
            if(mapValue.find(nTemp) == mapValue.end())
                mapValue[nTemp] = 1;
            else 
                mapValue[nTemp] += 1;
        } 
    }
    
     for(std::map<int,int>::iterator it = mapValue.begin(); mapValue.end() != it; it++) {
         int nIndex = it->first;
         int nValue = it->second;
         while(nValue--){
             cout<<nIndex<<endl;
         }
     }
}

int main() {

    return 0;
}
