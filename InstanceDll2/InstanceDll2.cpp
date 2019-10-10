// InstanceDll2.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "Interface2.h"
#include "../InstanceLib/instance.h"
#pragma comment(lib,"../bind/InstanceLib.lib")

extern "C" {

	void setNum2(int nNum) {
		CInstance::getInstance()->setNum(nNum);
	}

	int getNum2() {
		return CInstance::getInstance()->getNum();
	}
}
