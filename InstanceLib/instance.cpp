#include "stdafx.h"
#include <stdio.h>
#include "instance.h"
#include <mutex>

std::mutex gMutex;
CInstance* CInstance::m_pInstance = NULL;

CInstance* CInstance::getInstance()
{
	std::lock_guard<std::mutex> autoLock(gMutex);
	if (nullptr == m_pInstance)
		m_pInstance = new CInstance;

	return m_pInstance;
}

CInstance::CInstance():
m_nNum(0)
{

}

CInstance::~CInstance()
{

}

void CInstance::setNum(int nNum) {
	
	if (m_pInstance)
		m_nNum = nNum;
}

int CInstance::getNum() {
	return m_nNum;
}
