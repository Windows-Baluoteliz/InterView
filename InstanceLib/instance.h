#pragma once

class CInstance {
public:
	static CInstance* getInstance();
	static CInstance* m_pInstance;
	void setNum(int nNum);
	int getNum();

private:
	CInstance();
	~CInstance();

	int m_nNum;
};