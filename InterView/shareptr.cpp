#include <iostream>
using namespace std;
#include <memory>

int main() {

    std::shared_ptr<int> spnum(new int(1));
    cout<<"spnum:"<<spnum.get()<<" "<<spnum.use_count()<<endl;
    std::shared_ptr<int> spnum1 = make_shared<int>(2);
    cout<<"spnum1"<<spnum1.get()<<" "<<spnum1.use_count()<<endl;
    spnum.reset(new int(3));
    cout<<"spnum"<<spnum1.get()<<" "<<spnum.use_count()<<endl;
    std::shared_ptr<int> spnum2 = spnum;    
    cout<<"spnum"<<spnum.get()<<" "<<spnum.use_count()<<endl;
    cout<<"spnum2"<<spnum2.get()<<" "<<spnum2.use_count()<<endl;

    spnum.reset();
    spnum2.reset();

    cout<<"spnum"<<spnum.get()<<" "<<spnum.use_count()<<endl;
    cout<<"spnum2"<<spnum2.get()<<" "<<spnum2.use_count()<<endl;
    
    return 0;
}
