#include "deleter.h"

int main(){
//    Object *p = new Object();
    GoodObj *p = new GoodObj();
    delete_obj(p);
    return 0;
}
