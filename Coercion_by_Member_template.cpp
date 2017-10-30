#include <memory>
#include <iostream>

using namespace std;

class B{
public:
    int a;
    virtual void func() const {
        cout << "base!" << endl;
    }
};

class D : public B{
public:
    int b;
    virtual void func() const{
        cout << "derive!" << endl;
    }
};

template <typename T>
class Helper{
public:
    
    T * ptr;

    Helper(){
        ptr = nullptr;
    }

    Helper(T * p) : ptr(p){

    }

    Helper(const Helper & obj) : ptr(obj.ptr){
    
    }

    // Coercion by template, behavior is like a copy constructor but this is
    // not a copy constructor
    template <typename U>
    Helper(const Helper<U> & obj) : ptr(obj.ptr){

    }
    
    Helper & operator =(const Helper & obj){
        this->ptr = obj.ptr;
    }

    // Coercion by template, behavior is like a copy assignment constructor but
    // not a copy assignment constructor
    template <typename U>
    Helper & operator =(const Helper<U> & obj){
        this->ptr = obj.ptr;
    }

    void help(){
        ptr->func();
    }

};

int main(){
    shared_ptr<B> bptr;
    shared_ptr<D> dptr = make_shared<D>(D());

    bptr = dptr;
    B* braw = NULL;
    D* draw = new D;

    Helper<B> bhelp;
    Helper<D> dhelp(draw);

    bhelp = dhelp;

    bhelp.help();
    return 0;
}
