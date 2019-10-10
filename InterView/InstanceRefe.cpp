#include "..\InstanceDll1\Interface1.h"
#include "..\InstanceDll2\interface2.h"
#pragma comment(lib,"..\\bind\\InstanceDll1.lib")
#pragma comment(lib,"..\\bind\\InstanceDll2.lib")

int main() {

	setNum1(10);
	setNum2(20);
	int nNum = getNum1();
	nNum = getNum2();

	return 0;
}