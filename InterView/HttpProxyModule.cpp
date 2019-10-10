#ifndef __HTTPPROXYMODULE_CPP_
#define __HTTPPROXYMODULE_CPP_

/* About: mainly parse cpp platform http module.
* meanwhiles include proxypool logic.
* cpp platform http can user libcurl. https://curl.haxx.se/
* 1: mutil derived ,finally positoned to the last subclass.
* 2: can call base interface in the derived,it's also usefully.
* Author :  baluoteliz@gmail.com
*/

#include <iostream>
using namespace std;

#define Enable_Proxy

class CObjectBase {
public:
CObjectBase(){cout<<__FUNCTION__<<endl;}
virtual ~CObjectBase(){ cout<<__FUNCTION__<<endl;}

void start() {
    onProxyRetry();
}

public:

#ifdef Enable_Proxy
virtual void onProxyRetry() {
    cout<<__FUNCTION__<<endl;
}
#endif

virtual void onFailed(const char* pstrErrorInfo,int nErrorCode) {
    cout<<__FUNCTION__<<endl;
}

virtual void onSuccess(const char* pStrQuestTag) {
    cout<<__FUNCTION__<<endl;
}

};

class CObjectDerivedProxy: public CObjectBase
{
public:
CObjectDerivedProxy(){cout<<__FUNCTION__<<endl;}
~CObjectDerivedProxy(){cout<<__FUNCTION__<<endl;}

protected:

void onProxyRetry() {
    cout<<__FUNCTION__<<endl;
    onFailed("",0);
}

private:
};

class CObjectDerivedBusiness : public
#ifdef Enable_Proxy
CObjectDerivedProxy
#else
CObjectBase
#endif
{
public:
CObjectDerivedBusiness() {cout<<__FUNCTION__<<endl;}
~CObjectDerivedBusiness(){cout<<__FUNCTION__<<endl;}

void start() {
    CObjectBase::start();
}

protected:

void onFailed(const char* pstrErrorInfo,int nErrorCode) {
    cout<<__FUNCTION__<<endl;
}

void onSuccess(const char* pStrQuestTag) {
    cout<<__FUNCTION__<<endl;
}

private:

};

int main(int argc,char** argv) 
{
    cout<<"argc: "<<argc<<endl;
    for(int nIndex =0; nIndex  < argc; nIndex++) {
        cout<<"argc Index: "<<nIndex<<" argv: "<<argv[nIndex]<<endl;
    }

    CObjectDerivedBusiness object;
    object.start();

    getchar();

    return 0;
}

#endif
