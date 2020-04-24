#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <chrono>
#include <stdexcept>

/** @brief input many name string and 
 * statistics repeat count .then output the ordered statistics result by input order.
*/

bool compare_name(const std::string& lsh, const std::string& rsh) {
    return lsh > rsh;
}

void sortStrings_unordered_map() {
    std::unordered_map<std::string,int> uom_name;
    std::string inputString;
    while(std::cin>>inputString) {
        if("exit" == inputString)
            break;
        uom_name[inputString]++;
    }

    std::cout<<"statistics result ordered : "<<std::endl;
     std::for_each(uom_name.begin(),uom_name.end(),[](std::unordered_map<std::string,int>::value_type namepair) {
        std::cout<<namepair.first<<" "<<namepair.second<<std::endl;
     });
}

void sortStrings_set() {
    std::set<std::string> set_name{"ae","ff","ea","bb","ae"};
    std::for_each(set_name.begin(),set_name.end(),[](const std::string& value){
        std::cout<<"set element: "<<value<<std::endl;
    });
}

void sortString_unordered_set() {
    std::unordered_set<std::string> uos_name{"ae","ff","ea","bb","ae"};
    std::for_each(uos_name.begin(),uos_name.end(),[](const std::string& value){
        std::cout<<"unordered set element: "<<value<<std::endl;
    });
}


void sortString_unordered_multiset() {
    std::unordered_multiset<std::string> ums_name{"ae","ff","ea","bb","ae"};
    std::for_each(ums_name.begin(),ums_name.end(),[ums_name](const std::string& value){
        std::cout<<"unordered multiset element: "<<value<<" "<<ums_name.hash_function()(value)<<std::endl;
    });
}

void sortString_multi_map() {
    using mm_type = std::multimap<std::string,int>;
    mm_type mm_name = {
        {"ee",1},{"ff",2},{"ee",1},{"ee",2}
    };

    using mm_pair = mm_type::value_type;
    std::for_each(mm_name.begin(),mm_name.end(),[](mm_pair namepair){
        std::cout<<"multimap name: "<<namepair.first<<" "<<namepair.second<<std::endl;
    });
}

template<typename ty>
void sort_string_appearance() {
    
    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    
    using map_type = ty;

    map_type map_name;
    std::vector<map_type::iterator> vec_iter_name;
    std::string name;
    std::vector<std::string> arrayname{"ff","ab","cc","ff","bb","aa"};
    for(auto &name : arrayname) {
        auto it = map_name.insert({name,1});
        if(!it.second)
            it.first->second++;
        else
            vec_iter_name.push_back({it.first});
    }

    std::for_each(vec_iter_name.begin(),vec_iter_name.end(),[](const map_type::iterator iter) {
        std::cout<<"name: "<<iter->first<<" count:"<<iter->second<<std::endl;
    });

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout<<"map duration : "<<duration.count()<<std::endl;
}

template<typename ty,bool flage>
void sort_string_map_name() {
    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    
    using map_type = ty;

    map_type map_name;
    std::vector<map_type::iterator> vec_iter_name;
    std::string name;
    std::vector<std::string> arrayname{"ff","ab","ca","ff","bb","aa","ca",
    "we","sg","absd","wege","awe","sdg23","2gds","232gsd","2323","23sdg2323","2gsdg23"};
    for(auto &name : arrayname) {
        auto it = map_name.insert({name,1});
        if(!it.second)
            it.first->second++;
        else
            vec_iter_name.push_back({it.first});
    }
    if(flage) {
    std::sort(vec_iter_name.begin(),vec_iter_name.end(),[](const map_type::iterator lit,const map_type::iterator rit){
        if(lit->second == rit->second)
            return lit->first < rit->first;
        return lit->second < rit->second;
    });
    }

    std::for_each(vec_iter_name.begin(),vec_iter_name.end(),[](const map_type::iterator iter) {
        std::cout<<"name: "<<iter->first<<" count:"<<iter->second<<std::endl;
    });

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout<<"map duration : "<<duration.count()<<std::endl;
}

int main() {

    sort_string_map_name<std::map<std::string,int>,false>();
    sort_string_map_name<std::unordered_map<std::string,int>,false>();

    sort_string_map_name<std::map<std::string,int>,true>();
    sort_string_map_name<std::unordered_map<std::string,int>,true>();

    return 0;
}

