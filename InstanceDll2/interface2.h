
#ifdef DLL2
#define Export_DLL2 __declspec(dllexport)
#else
#define Export_DLL2 __declspec(dllimport)
#endif

extern "C" {
	Export_DLL2 void setNum2(int nNum);
	Export_DLL2 int getNum2();
}