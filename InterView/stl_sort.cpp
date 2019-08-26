#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

void fun_vec_sort() {
    std::vector<std::string> vecString;
    vecString.push_back("123");
    vecString.push_back("234");
    vecString.push_back("334");
    vecString.push_back("133");
    vecString.push_back("15");

    sort(vecString.begin(),vecString.end());
    
    for(const auto &u : vecString)
        cout<<u<<endl;
}


void fun_vec_customer_sort() {

    class student {

        public:
            student(){;}
            student(int num):a(num){;}
            
            bool operator<(const student& obj) {
                return a < obj.a;
            }

        public:
            int a;
    };

typedef std::vector<student> vecStudent;
    vecStudent vec_student;
    vec_student.push_back(10);
    vec_student.push_back(30);
    vec_student.push_back(20);

    std::sort(vec_student.begin(),vec_student.end());

    for(auto &u : vec_student)
        cout<<u.a<<endl;
}

void fun_list_sort() {
    std::list<std::string> listString;
    listString.push_back("sgd");
    listString.push_back("234");
    listString.push_back("334");
    listString.push_back("133");
    listString.push_back("15");

    listString.sort();

     for(const auto &u : listString)
        cout<<u<<endl;
}

void fun_list_customer_sort() {
        class student {

        public:
            student(){;}
            student(int num):a(num){;}
            
            bool operator<(const student& obj) {
                return a < obj.a;
            }

        public:
            int a;
    };

    typedef std::list<student> liststudent;
    liststudent list_student;
    list_student.push_back(10);
    list_student.push_back(5);
    list_student.push_back(20);
    list_student.sort();

    for(auto &i : list_student)
        cout<<i.a<<endl;
}

void fun_map_customer_sort() {
       
    struct student {
        student(int nNum) : m_nNum(nNum) {;}
        
        bool operator<(const student& obj) const {
            return m_nNum < obj.m_nNum;
        }

        int m_nNum;
    };

typedef std::map<student,int> mapstudent;
    mapstudent map_student;
    map_student.insert(std::pair<student,int>(10,1));
    map_student.insert(std::pair<student,int>(5,1));

    for(auto &i:map_student)
        cout<<(i.first.m_nNum)<<" "<<(i.second)<<endl;
}

int main() {
    fun_map_customer_sort();

    system("pause");
    return 0;
}
