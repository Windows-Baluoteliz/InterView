#include <iostream>
using namespace std;

int parition(int a[],int l,int h) {
    if(l < h) {
        int i = l;
        int nTag = a[h];
        for(int j = l; j < h; j++) {
            if(a[j] < nTag) {
                std::swap(a[j],a[i]);
                i++;
            }
        }
        std::swap(a[i],a[h]);
        return i;
    }
}

void quick_sort(int a[],int low,int high) {
    if(low < high) {
        int nParition = parition(a,low,high);
        quick_sort(a,low,nParition - 1);
        quick_sort(a,nParition + 1,high);
    }
}

int main() {
    int a[] = {2,3,2,5,19,2,3,8,1};
    quick_sort(a,0,8);

    return 0;
}