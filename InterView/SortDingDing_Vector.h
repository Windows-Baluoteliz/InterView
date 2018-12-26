#ifndef __SORTDINGDING_VECTOR_H__
#define __SORTDINGDING_VECTOR_H__

/*
* About: 钉钉:
* 一堆数据（Key,Value)，需要对这些数据分类，同时保证先进入的数据在前面.
* Author: Baluoteliz@gmail.com.
*/

namespace DingDing {

	namespace Function1 {

		typedef struct eTagWordsIndex {
			std::string strWords;
			int nIndex;
			int nCount;

			eTagWordsIndex(const std::string strWord, const int nIndex = 0, const int nCount1 = 1) :
				strWords(strWord),
				nIndex(nIndex),
				nCount(nCount1){
				;
			}

			eTagWordsIndex operator=(const std::string strWord) {

				strWords = strWord;
				return *this;
			}

			bool operator==(const eTagWordsIndex &Obj) const {
				return strWords == Obj.strWords;
			}

			bool operator < (const eTagWordsIndex &Obj) const {
				return strWords < Obj.strWords;
			}

			eTagWordsIndex() :
				nIndex(-1) {
				;
			}
		}BAL_WORD, *PBAL_WORD, *LPBAL_WORD;

		void SortByVector() {
			std::vector<eTagWordsIndex> m_vecWordsDest;
			std::vector < std::string > m_vecWordSrc;

			m_vecWordSrc.push_back("21");
			m_vecWordSrc.push_back("13");
			m_vecWordSrc.push_back("12");
			m_vecWordSrc.push_back("11");

			m_vecWordSrc.push_back("11");
			m_vecWordSrc.push_back("12");
			m_vecWordSrc.push_back("14");

			int nIndex = 0;
			auto itt = m_vecWordsDest.begin();
			for (auto it = m_vecWordSrc.begin(); m_vecWordSrc.end() != it; it++) {
				if (m_vecWordsDest.end() != (itt = find(m_vecWordsDest.begin(), m_vecWordsDest.end(), *it))){
					itt->nCount++;
				}
				else {
					nIndex++;
					m_vecWordsDest.push_back(eTagWordsIndex(*it, nIndex, 1));
				}
			}

			sort(m_vecWordsDest.begin(), m_vecWordsDest.end());
			for (auto it = m_vecWordsDest.cbegin(); m_vecWordsDest.end() != it; it++)
				cout << "[" << it->nIndex << "] " << it->strWords << " " << it->nCount << endl;
		}
	}// nammespace Function1

} //namespace DingDing

#endif