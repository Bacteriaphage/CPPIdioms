#ifndef __DELETER__H_
#define __DELETER__H_
class Object;

class GoodObj{
public:
    int a;
    GoodObj();
    ~GoodObj();
};

template <typename T>
void delete_obj(T* p){
    typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
    (void) sizeof(type_must_be_complete);
    delete p;
}
#endif
