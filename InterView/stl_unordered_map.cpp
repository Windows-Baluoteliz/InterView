#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    typedef std::unordered_map<std::string,int> unmap;
    unmap umap;
    std::string str = "geeks for geeks geeks quiz practice qa for";

    stringstream ss(str);
    std::string strword;
    while(ss>>strword)
        umap[strword]++;

    for(const auto &i : umap)
        cout<<i.first<<" "<<i.second<<endl;
    
    return 0;
}