#ifndef __SINGLETONTEMPLATE_H__
#define __SINGLETONTEMPLATE_H__

#include <windows.h>
#include <Memory>
template<typename T> class CSingleton
{
public:
	static T* getInstance(void* param = NULL);

	struct CGrabo
	{
		CGrabo()
		{
			if (nullptr == pCritical_Section)
			{
				pCritical_Section = new CRITICAL_SECTION;
			}

			if (pCritical_Section)
			{
				InitializeCriticalSection(pCritical_Section);
			}
			printf("%s %x\n", __FUNCTION__, (unsigned int)pCritical_Section);
		}

		virtual ~CGrabo()
		{
			EnterCriticalSection(pCritical_Section);

			if (pInstance_)
			{
				delete pInstance_;
				pInstance_ = nullptr;
			}

			LeaveCriticalSection(pCritical_Section);
			DeleteCriticalSection(pCritical_Section);

			delete pCritical_Section;
			pCritical_Section = nullptr;
			printf("%s\n", __FUNCTION__);
		}
	};

protected:
	virtual void onSetParam(void* param){ ; }
	CSingleton();
	virtual ~CSingleton();

private:
	static T* pInstance_;
	static LPCRITICAL_SECTION pCritical_Section;
	static std::unique_ptr<CGrabo> pGrabo;
};

template<typename T> LPCRITICAL_SECTION CSingleton<T>::pCritical_Section = nullptr;
template<typename T> T* CSingleton<T>::pInstance_ = nullptr;
template<typename T> std::unique_ptr<typename CSingleton<T>::CGrabo> CSingleton<T>::pGrabo = nullptr;

template<typename T> CSingleton<T>::CSingleton()
{
	printf("%s\n", __FUNCTION__);
}

template<typename T> CSingleton<T>::~CSingleton()
{
	printf("%s\n", __FUNCTION__);
}

template<typename T> T* CSingleton<T>::getInstance(void* param /*= NULL*/)
{
	if (nullptr == pCritical_Section)
	{
		pCritical_Section = new CRITICAL_SECTION;
	}
	if (nullptr == CSingleton<T>::pInstance_)
	{
		EnterCriticalSection(pCritical_Section);
		CSingleton<T>::pInstance_ = new T;
		CSingleton<T>::pInstance_->onSetParam(param);
		LeaveCriticalSection(pCritical_Section);
	}

	return pInstance_;
}

#endif