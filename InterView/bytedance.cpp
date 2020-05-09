#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <functional>
#include <stack>
#include <unordered_map>
#include <map>
#include <list>
#include <unordered_set>
using namespace std;

/*
* 指定l:数据其实位置,p:从l开始的数据长度,
* 然后左右对称重置这个段数据,插入到之前指定的数据段的尾部.
* 输出新的字符串.
*/
void fun1() {
    char szbufSrc[20] = {0};
    char szbufDest[1024] = {0};
    cin>>szbufSrc;
    strcpy(szbufDest,szbufSrc);
    int nStep = 0;
    cin>>nStep;

    for(int i = 0 ; i < nStep;i++) {
        char *pStrTemp = NULL;
        int l,p = 0;
        cin>>l>>p;
        int nTempLen = strlen(szbufDest) - l + 1;
        pStrTemp = new char[nTempLen];
        for(int n = 0 ; n < nTempLen - 1; n++) {
            if(n < p)
                pStrTemp[n] = szbufDest[l + p - 1 - n];
            else
                pStrTemp[n] = szbufDest[l + n];
        }
        pStrTemp[nTempLen -1] = '\0';
        char *pTemp = &(szbufDest[l + p]);
        strcpy(pTemp,pStrTemp);
        delete [] pStrTemp;
        cout<<szbufDest<<endl;
    }

    cout<<szbufDest<<endl;
}

void fun2() {
    int nStep = 0;
    cin>>nStep;
    std::string *pStrString = new std::string[nStep];
    for(int n = 0; n < nStep ; n++) {
        std::string strTemp;
    }
}

/*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度*/
int lengthOfLongestSubstring(std::string s) {
    if(s.empty())
        return 0;

    std::string key1,key2;
    int nIndex = 0;
    while('\0' != s[nIndex]) {
        if(key1.empty()) {
            key1 += s[nIndex];
        } else {
            if(key2.empty()) {
                if(string::npos == key1.find(s[nIndex]))
                    key1+= s[nIndex];
                else
                    key2+= s[nIndex];
            } else {
                if(string::npos == key2.find(s[nIndex]))
                    key2 += s[nIndex];
                else {
                    key1 = key1.length() > key2.length() ? key1:key2;
                    key2 = s[nIndex];
                }
            }
        }

        nIndex++;
    }

    std::cout<<"key1: "<<key1.data()<<" key2: "<<key2.data()<<std::endl;
    return std::max(key1.length(),key2.length());
} 


string longestCommonPrefix(vector<string>& strs) {
    std::string prefix = strs.size() ? strs[0] : "";
    for_each(strs.begin(),strs.end(),[&prefix](const std::string& str){
        prefix = (prefix.length() <= str.length() ? prefix : str);
    });

    int nPrefixLen = prefix.length();
    while(nPrefixLen) {
        auto f = [&](const string& source,int nSubStrLen)->std::vector<string> {
            std::vector<string> vecSub;
            if(source.empty() || nSubStrLen == 0 || source.length() < nSubStrLen)
                return vecSub;
            
            int nFirst = 0;
            while(nFirst + nSubStrLen <= source.length()) {
                std::string value = source.substr(nFirst,nSubStrLen);
                vecSub.push_back(value);
                nFirst++;
            }

            return vecSub;
        };
        std::vector<string> vecSubString = f(prefix,nPrefixLen);

        if(vecSubString.empty())
            break;

        for(auto &subPrefix:vecSubString) {
            bool bFind = true;
            for_each(strs.begin(),strs.end(),[&bFind,&subPrefix](const string& source)->bool{
                if(string::npos == source.find(subPrefix)) {
                    bFind = false;
                    return false;
                }
                return true;
            });
            std::cout<<"prefixlen: "<<nPrefixLen<<" subPrefix: "<<subPrefix.c_str()<<" bFind: "<<bFind<<std::endl;
            if(bFind)
                return subPrefix;
        }
        nPrefixLen--;
    }

    return "";
}

bool checkInclusion(string s1, string s2) {
    auto f = [&](const string& source)->string {
        string backstr;
        for_each(source.begin(),source.end(),[&backstr](const char &ch) {
            backstr = ch + backstr;
        });
        return backstr;
    };
    string backstr = f(s1);

    return string::npos != s2.find(backstr);
}

string multiply(string num1, string num2) {
    int nNum1 = atoi(num1.data());
    int nNum2 = atoi(num2.c_str());
    int nNum_multi = nNum1 * nNum2;
    char szbuf[24] = {0};
    return _itoa(nNum_multi,szbuf,10);
}

string reverseWords(string s) {
    std::vector<string> vecWord;
    int nIndex = 0;
    string sword;
    while('\0' != s[nIndex]) {
        if(!sword.empty()) {
            if(' ' == s[nIndex]) {
                vecWord.push_back(sword);
                sword.clear();
            } else
                sword += s[nIndex];
        } else {
            if(' ' != s[nIndex])
                sword += s[nIndex];
        }
        nIndex++;
    }

    string reverseword;
    for_each(vecWord.begin(),vecWord.end(),[&reverseword](const string& word) {
        reverseword = word + " " + reverseword;
    });

    reverseword[reverseword.length() - 1] = '\0';

    return reverseword;
}

namespace simplifypath{
    void path_erase_dot(string& source) {
        if(source.empty() || "./" == source)
            return;
        if(source.length() == 1)
            return;
        char lch,mch,rch = '\0';
        auto mit = source.begin() + 1;
        bool bFind = false;
        while(source.end() != mit && source.end() != (mit-1) && source.end() != (mit + 1)) {
            lch = *(mit-1);
            mch = *mit;
            rch = *(mit+1);
            if( ('/' == lch && '.' == mch && '/' == rch) || 
                ('.' == lch && '.' == mch && '.' == rch) ) {
                    mit = source.erase(mit,mit+1);
                    bFind = true;
            } else 
                mit++;
        }
        if(bFind)

            path_erase_dot(source);
        else
            return;
    }

    void path_erase_double_slash(string& source) {
        if(source.empty() || source.length() == 1)
            return;
        
        char first_ch,next_ch = '\0';
        auto it = source.begin();
        bool bFind = false;
        while(source.end() != it && source.end() != it+1) {
            first_ch = *it;
            next_ch = *(it+1);
            if('/' == first_ch && '/' == next_ch) {
                it = source.erase(it);
                bFind = true;
            } else 
                it++;
        }
        if(bFind)
            path_erase_double_slash(source);
        else 
            return;
    }

    void path_erase_rollback_dir(string& source) {
        if(source.empty()) 
            return;
        auto it = source.begin();
        auto first_slash_iterator = source.end();
        auto next_slash_iterator = source.end();
        auto next_next_slash_iterator = source.end();
        string slash_str,next_slash_str;
        while(source.end() != it) {
            if('/' == *it && source.end() == first_slash_iterator)
                first_slash_iterator = it;
            else if('/' == *it && source.end() == next_slash_iterator) {
                next_slash_iterator = it;
                slash_str = source.substr(first_slash_iterator - source.begin() + 1,next_slash_iterator-first_slash_iterator - 1);
            } else if('/' == *it && source.end() == next_next_slash_iterator) {
                next_next_slash_iterator = it;
                next_slash_str = source.substr(next_slash_iterator - source.begin() + 1,next_next_slash_iterator-next_slash_iterator -1);
            } else {
                it++;
                continue;
            }

            if(!slash_str.empty() && !next_slash_str.empty()) {
                if(slash_str != ".." && ".." == next_slash_str) {
                    it = source.erase(first_slash_iterator,next_next_slash_iterator);
                    first_slash_iterator = next_next_slash_iterator = next_slash_iterator = source.end();
                    slash_str = next_slash_str = "";
                    continue;
                } else {
                    first_slash_iterator = next_slash_iterator;
                    next_slash_iterator = next_next_slash_iterator;
                    slash_str = next_slash_str;
                    next_next_slash_iterator = source.end();
                    next_slash_str = "";
                }
            } 
            it++;
        }

        return;
    }

    string simplifyPath(string path) {
        std::cout<<"path: "<<path.c_str()<<std::endl;
        if(path.empty())
            return "";

        if('/' != path[path.length() - 1])
            path += '/';
        path_erase_dot(path);
        cout<<"path_erase_dot: "<<path.c_str()<<std::endl;;
        path_erase_double_slash(path);
        cout<<"path_erase_double_slash: "<<path.c_str()<<std::endl;;
        path_erase_rollback_dir(path);
        cout<<"path_erase_rollback_dir: "<<path.c_str()<<std::endl;
        
        if('/' == path[path.length() - 1])
            path[path.length() - 1] = '\0';
        if('/'!= path[0])
            path = '/' + path;

        cout<<"f_erase: "<<path.c_str()<<std::endl;
        
        return "";
    }

} // namespace simplifypath

/** 素组和排序部分
 * 
*/
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vecThreeSum;

    std::sort(nums.begin(),nums.end());
    if(nums.size() < 3 || nums.front() >=0 || nums.back() <=0)
        return vecThreeSum;
    int l_Index = 0,r_Index = 0;
    int m_Index = 1;
    while(m_Index < nums.size() -1) {
        auto it = nums.begin() + m_Index;
        std::vector<int> vecLeft,vecRight;
        m_Index > 1 ? (vecLeft.assign(nums.begin(),it)) : (vecLeft.push_back(nums[0]));
        vecRight.assign(it + 1,it + (nums.size() -m_Index));
        int mNum = nums[m_Index];
        for_each(vecLeft.begin(),vecLeft.end(),[&](int num) {
            int rNum = -num - mNum;
            if(vecRight.end() != std::find(vecRight.begin(),vecRight.end(),rNum)) {
                std::vector<int> vecItem({num,mNum,rNum});
                if(vecThreeSum.end() == find(vecThreeSum.begin(),vecThreeSum.end(),vecItem))
                    vecThreeSum.push_back(vecItem);
            }
        });
        m_Index++;
    }

    for_each(vecThreeSum.begin(),vecThreeSum.end(),[&](const vector<int>& vecItem) {
        std::cout<<"["<<vecItem[0]<<","<<vecItem[1]<<","<<vecItem[2]<<"],"<<std::endl;
    });
    return vecThreeSum;
}

//岛屿的最大面积 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
namespace maxAreaOfIsland {

    int maxAreaOfPoint(vector<vector<int>>& grid,int row,int column) {
        int maxrow = grid.size();
        int maxcolumn = grid[0].size();
        if(row<0 || row >= maxrow || column <0 || column >= maxcolumn)
            return 0;
        
        int this_point = grid[row][column];
        if(this_point == 0)
            return 0;
        else {
            grid[row][column] = 0;//此处是最关键的一步.
            int up_point = 0;
            int left_point = 0;
            int right_point = 0;
            int down_point = 0;
            if(column - 1 >= 0)
                left_point = maxAreaOfPoint(grid,row,column-1);
            if(column + 1 <= maxcolumn)
                right_point = maxAreaOfPoint(grid,row,column + 1);
            if(row - 1 >= 0)
                up_point = maxAreaOfPoint(grid,row - 1,column);
            if(row + 1 <= maxrow)
                down_point = maxAreaOfPoint(grid,row + 1,column);
            
            return this_point + left_point + right_point + down_point + up_point;
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        int row = grid.size();
        int column = grid[0].size();
        int sum = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column ;j++) {
                if(grid[i][j]) {
                    int sum_temp =  maxAreaOfPoint(grid,i,j);
                    sum = std::max(sum,sum_temp);
                }
            }
        }

        return sum;
    }
} //namespace maxAreaOfIsland

//搜索旋转排序数组
int search(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;
    int l = 0;
    int r = nums.size() - 1;
    while(l < r) {
        int m = (l + r) >> 2;
        if(nums[m] == target)
            return m;
        if(nums[0] < nums[m]) {
            if(target >= nums[0] && target < nums[m])
                r = m -1 ;
            else 
                l = m + 1;
        } else {
            if(target > nums[m] && target <= nums[r])
                l = m + 1;
            else 
                r = m - 1;
        }
    }

    return -1;
}

//最长连续递增序列
int findLengthOfLCIS(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int begin = 0;
    int current = 1;
    int sum = 1;
    while(current <= nums.size() - 1) {
        if(nums[current] > nums[current - 1]) {
            current++;
        } else {
            int sum1 = current - begin;
            sum = max(sum1,sum);
            begin = current++;
        }
    }

    return sum;
}

//数组中的第K个最大元素
int findKthLargest(vector<int>& nums, int k) {
    if(nums.empty() || k <= 0 || k > nums.size())
        return -1;
    
    std::sort(nums.begin(),nums.end(),std::greater<int>());
    return nums[k-1];
}

//K-th order
string getPermutation(int n, int k) {
    auto f = [&](int n)->int {
        int sum = n>=1 ? 1 : 0;
        while(n) {
            sum*=n--;
        }
        return sum;
    };
    std::vector<int> vecNum;
    int nNum = n;
    while(nNum--) {
        vecNum.push_back(n - nNum);
    }
    int permutationcount = f(n);
    k--;
    if(k <= permutationcount && k) {
        int nX,nY,nIndex = 0;
        do {
            int nWeight = f(n - 1 - nIndex);
            nX = k/nWeight;
            nY = k%nWeight;
            int num = vecNum[nX+nIndex];
            vecNum.erase(vecNum.begin() + nX + nIndex);
            vecNum.insert(vecNum.begin() + nIndex,num);

            nIndex++;
            k = nY;
        }while(k);
    }

    string result;
    for(int &num : vecNum) {
        
        result.append(string().assign(1,num +'0'));
    }

    return result;
}

//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nMin = std::min(nMin,x);
        stack_pair_v.push(make_pair(nMin,x));
    }
    
    void pop() {
        if(!stack_pair_v.empty()) {
            stack_pair_v.pop();
            if(!stack_pair_v.empty())
                nMin = stack_pair_v.top().first;
            else 
                nMin = INT_MAX;
        }
    }
    
    int top() {
        if(!stack_pair_v.empty())
            return stack_pair_v.top().second;
        return -1;
    }
    
    int getMin() {
        return nMin;
    }
    
    private:
    int nMin = INT_MAX;
    std::stack<std::pair<int,int> > stack_pair_v;
};

//LRU缓存机制
class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {
    }
    
    int get(int key) {
        if(uo_map_value.end() != uo_map_value.find(key)) {
            map_count[key] +=1;
            return uo_map_value[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(uo_map_value.size() == capacity) {
            std::vector<std::pair<int,int>> vec_pair_count;
            for_each(map_count.begin(),map_count.end(),[&](const std::pair<int,int>& element) {
                vec_pair_count.push_back(element);
            });
            sort(vec_pair_count.begin(),vec_pair_count.end(),[&](std::pair<int,int>& lhs,std::pair<int,int>& rhs){
                return lhs.second < rhs.second;
            });
            int k = vec_pair_count[0].first;
            uo_map_value.erase(uo_map_value.find(k));
            map_count.erase(map_count.find(k));
        }
        
        uo_map_value[key] = value;
        map_count[key] +=1;
    }

    private:
        int capacity;
        std::unordered_map<int,int> uo_map_value;
        std::map<int ,int> map_count;
};

//全 O(1) 的数据结构
class AllOne {
public:
    /** Initialize your data structure here. */

    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(uo_map_container.count(key)) {
            auto ite_cur = uo_map_container[key];
            auto ite_next = next(ite_cur,1);
            ite_next = listNode.insert(ite_next,Node(ite_cur->value + 1));
            ite_next->container.insert(key);
            ite_cur->container.erase(key);
            if(ite_cur->container.empty())
                listNode.erase(ite_cur);
            uo_map_container[key] = ite_next;  
        } else {
            auto ite_next = listNode.begin();
            if(listNode.end() != ite_next &&
            ite_next->value == 1) {
                ite_next->container.insert(key);
            } else {
                ite_next = listNode.insert(ite_next,Node(1));
                ite_next->container.insert(key);
            }
            uo_map_container[key] = ite_next;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(uo_map_container.count(key)) {
            auto ite_cur = uo_map_container[key];
            if(ite_cur->value == 1) {
                ite_cur->container.erase(key);
                if(ite_cur->container.empty())
                    listNode.erase(ite_cur);
                uo_map_container.erase(key);
            } else {
                auto ite_pre = prev(ite_cur,1);  
                if(ite_pre == listNode.end() ||
                ite_cur->value > ite_pre->value + 1) {
                    ite_cur->container.erase(key);
                    ite_pre = listNode.insert(ite_cur,Node(ite_cur->value - 1));
                    uo_map_container[key] = ite_pre;
                    if(ite_cur->container.empty())
                        listNode.erase(ite_cur);
                } else {
                    ite_pre->container.insert(key);
                    ite_cur->container.erase(key);
                    if(ite_cur->container.empty())
                        listNode.erase(ite_cur);
                    uo_map_container[key] = ite_pre;
                }
            } 
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(listNode.empty())
            return "";
        else
            return *(listNode.rbegin()->container.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(listNode.empty())
            return "";
        else 
            return *(listNode.begin()->container.begin());
    }

    private:
        struct Node {
            int value;
            std::unordered_set<string> container;
            Node(int nNum):value(nNum){;}
        };
    std::unordered_map<string,std::list<Node>::iterator> uo_map_container;
    std::list<Node> listNode;
};

int main() {

    //Your AllOne object will be instantiated and called as such:
    AllOne* obj = new AllOne();
    obj->inc("1");
    obj->inc("2");
    obj->inc("3");
    obj->inc("1");
    obj->dec("2");

    string param_3 = obj->getMaxKey();
    cout<<"maxKey: "<<param_3.c_str()<<endl;
    string param_4 = obj->getMinKey();
    cout<<"minKey: "<<param_4.c_str()<<endl;    

    return 0;
}
