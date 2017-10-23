#ifndef __DELETER__H_
#define __DELETER__H_
class Object;

class GoodObj{
public:
    int a;
    GoodObj();
    ~GoodObj();
};
// non-specialized template must be defined in header file or another header
// file to wrap this implementation. It cannot be decleared in header file and
// implemented in cpp file. Itmust be visible to a translation unit that uses it.
//
// The compiler must be able to see the implementation in order to generate
// code for all specializations
template <typename T>
void delete_obj(T* p){
    typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
    (void) sizeof(type_must_be_complete);
    delete p;
}
#endif
