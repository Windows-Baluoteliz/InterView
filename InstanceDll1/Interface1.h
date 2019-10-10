
#ifdef DLL1
#define Export_DLL1 __declspec(dllexport)
#else
#define Export_DLL1 __declspec(dllimport)
#endif

extern "C" {
	Export_DLL1 void setNum1(int nNum);
	Export_DLL1 int getNum1();
}