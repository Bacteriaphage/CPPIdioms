#include <iostream>
#include <string>

using namespace std;

class grandparent{
public:
    virtual void present(){}
};

class father : public grandparent{
    string info = "child`s dad";
public:
    void present(){
        cout << info << endl;
    }
};

class mother : public grandparent{
    string info = "child`s mom";
public:
    void present(){
        cout << info << endl;
    } 
};

class child{
private:
    grandparent* interface;
    bool male;
public:
    child(){
        male = true;
        interface = nullptr;
    }
    void reverse(){
        if(interface != nullptr){
            delete interface;
        }
        if(male){
            interface = new father;
        }
        else{
            interface = new mother;
        }
        male = !male;
    }
    grandparent* operator->(){
        return interface;
    }
};

int main(){
    child c1;
    c1.reverse();
    c1->present();
    c1.reverse();
    c1->present();
    return 0;
}
