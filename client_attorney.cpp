#include <iostream>

using namespace std;

class Client{
private:
    void A(){
        cout << "This is Client A Method" << endl;
    }
    
    void B(){
        cout << "This is Client B Method" << endl;
    }

    void C(){
        cout << "This is Client C Method" << endl;
    }
    friend class Attorney;
};

class Base{
private:
    virtual void func(int i) = 0;
    friend class Attorney;
public:
    virtual ~Base(){}
};

class Derive : public Base{
private:
    void func(int i){
        cout << "Derive class input is " << i << endl;
    }
public:
    ~Derive(){}
};

class Attorney{
private:
    static void client_callA(Client & cli){
        cli.A();
    }
    static void client_callB(Client & cli){
        cli.B();
    }
    static void derive_callfunc(Base & base, int i){
        base.func(i);
    }
    friend int main();
};



int main(){
    Client cli;
    Attorney::client_callA(cli);
    Derive der;
    Attorney::derive_callfunc(der, 5);
}
