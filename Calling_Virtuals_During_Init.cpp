#include <iostream>

using namespace std;

class Base{
public:
    // It doesn`t make any sence to make a static funtion as virtual
    // virtual function can be called depending on a particular instance
    // but static methods belong to class not a instance
    //virtual static void foo() = 0;
    //virtual static void bar() = 0;
};

template<class Derived>
class InitTimeCaller : public Base{
protected:
    InitTimeCaller(){
        Derived::foo();
        Derived::bar();
    }
};

class Derived : public InitTimeCaller<Derived>{
    public:
        Derived() : InitTimeCaller<Derived>(){
            cout << "Derived() constructing..." << endl;
        }
        static void foo(){
            cout << "Derive::foo called..." << endl;
        }
        static void bar(){
            cout << "Derive::bar called..." << endl;
        }
};

int main(){
    Derived a;
}
