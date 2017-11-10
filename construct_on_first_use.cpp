#include <iostream>

using namespace std;

class Bar{
public:
    Bar(){
        cout << "Bar::Bar()" << endl;
    }

    void f(){
        cout << "Bar::f()" << endl;
    }
};

class Foo{
public:
    Foo(){
        bar().f();
    }
    Bar & bar(){
        //static Bar * _bar = new Bar();
        //cout << "inner bar address: "<< reinterpret_cast<unsigned long long>(_bar) << endl;
        //return *_bar;
        static Bar _bar;
        cout << "inner bar address: " << reinterpret_cast<unsigned long long>(&_bar) << endl;
        return _bar;
    }
};

int main(){
    Foo f1;
    Foo f2;
    return 0;
}
