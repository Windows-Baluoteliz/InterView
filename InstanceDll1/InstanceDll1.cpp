// InstanceDll1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Interface1.h"
#include "../InstanceLib/instance.h"
#pragma comment(lib,"../bind/InstanceLib.lib")

extern "C" {

	void setNum1(int nNum) {
		CInstance::getInstance()->setNum(nNum);
	}

	int getNum1() {
		return CInstance::getInstance()->getNum();
	}
}


