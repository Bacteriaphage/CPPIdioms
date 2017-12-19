/*
 * throw exception from initial list when construct some other classes 
 * if other class take at least one parameter, it ok to directly use double
 * parantheses to construct with changing tracing type, however, if other classes
 * take no parameter, we must use adapter to create a parameter.
*/
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

struct B{
    B() {
        throw runtime_error("B Error");
    }
};
struct Adapter{
    B _b;
    Adapter(int)
    try
        :_b()
    {
        
    }
    catch (exception const & e){
        throw;
    }
};
struct C{
    C(char const *) {
        throw runtime_error("C Error");
    }
};

class A{
    Adapter _b;
    C _c;
    enum TrackerType {NONE, ONE, TWO};
public:
    A(TrackerType tracker = NONE)
    try
        : _b((tracker = ONE, 0))
        , _c((tracker = TWO, "World"))
    {
        assert(tracker == TWO);
    }
    catch(exception const & e){
        if(tracker == ONE){
            cout << "B threw:" << e.what() << std::endl;
        }
        if(tracker == TWO){
            cout << "C threw:" << e.what() << std::endl;
        }
        throw;
    }
};

int main(){
    try{
        int num1, num2;
        //B b((num1=0, num2 = 1));
        A a;
    }
    catch (exception const & e){
        cout << "Caught:" << e.what() << endl;
    }
    return 0;
}
