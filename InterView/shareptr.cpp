#include <iostream>
using namespace std;
#include <memory>

class A {
 public:
    std::shared_ptr<A> pre;
    std::shared_ptr<A> next;

    ~A() {
        cout<<__FUNCTION__<<endl;
    }

};

int main() {
    /* mainly introduce the use of share-ptr 
    * initialization of share-ptr instance.
    * direct call constructor explict
    * make-shared pass by a value.
    * reset pass by a value.
    */
    std::shared_ptr<int> spnum(new int(1));
    cout<<"spnum:"<<spnum.get()<<" "<<spnum.use_count()<<endl;
    std::shared_ptr<int> spnum1 = make_shared<int>(2);
    cout<<"spnum1:"<<spnum1.get()<<" "<<spnum1.use_count()<<endl;
    spnum.reset(new int(3));
    cout<<"spnum:"<<spnum1.get()<<" "<<spnum.use_count()<<endl;
    std::shared_ptr<int> spnum2 = spnum;    
    cout<<"spnum:"<<spnum.get()<<" "<<spnum.use_count()<<endl;
    cout<<"spnum2:"<<spnum2.get()<<" "<<spnum2.use_count()<<endl;
    spnum.reset();
    spnum2.reset();
    cout<<"spnum:"<<spnum.get()<<" "<<spnum.use_count()<<endl;
    cout<<"spnum2:"<<spnum2.get()<<" "<<spnum2.use_count()<<endl;

    //loop reference use shared_ptr.
    std::shared_ptr<A> sp_a1(new A);
    std::shared_ptr<A> sp_a2(new A);
    cout<<"sp_a1 use_count: "<<sp_a1.use_count()<<" sp_a2 use_count: "<<sp_a2.use_count()<<endl;
    sp_a1.get()->next = sp_a2;
    cout<<"sp_a1 use_count: "<<sp_a1.use_count()<<" sp_a2 use_count: "<<sp_a2.use_count()<<endl;
    sp_a2.get()->pre = sp_a1;
    cout<<"sp_a1 use_count: "<<sp_a1.use_count()<<" sp_a2 use_count: "<<sp_a2.use_count()<<endl;
    
    return 0;
}
