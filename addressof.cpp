//https://stackoverflow.com/questions/16195032/implementation-of-addressof
//already implemented in <memory>
#include <iostream>

class Test{
public:
    int a;
    char b;
//    Test* operator &(){return this;}
};
namespace custom{
    template <class T>
    T * addressof(T & v){
        return reinterpret_cast<T*>(& const_cast<char&>(reinterpret_cast<const volatile char &>(v)));
    }
}
/*
First you have __r which is of type _Tp& 

It is reinterpret_cast'ed to a char& in order to ensure being able to later take its address without fearing an overloaded operator& in the original type; 
Actually it is cast to const volatile char& because reinterpret_cast can always legally add const and volatile qualifiers even if they are not present, 
but it can't remove them if they are present (this ensures that whatever qualifiers _Tp had originally, they don't interfere with the cast).

This is const_cast'ed to just char&, removing the qualifiers (legally now! const_cast can do what reinterpret_cast couldn't with respect to the qualifiers).

The address is taken & (now we have a plain char*)
It is reinterpret_cast'ed back to _Tp* (which includes the original const and volatile qualifiers if any).
*/
int main(){
    Test t;
    Test *p = custom::addressof(t);
    std::cout << reinterpret_cast<unsigned long long>(p) << std::endl;
    std::cout << reinterpret_cast<unsigned long long>(&t) << std::endl;
    return 0;
}
