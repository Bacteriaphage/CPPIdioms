#include "deleter.h"
/* this idiom is used to delete object porperly
 * if one object is partially defined, then throw an error
 * otherwise delete that object
 * */
int main(){
//    Object *p = new Object();
    GoodObj *p = new GoodObj();
    delete_obj(p);
    return 0;
}
