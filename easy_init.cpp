/*easy init is a trick to continuously insert item into a object.
 *the idea is override a () operator to do any operation and return
 *reference of object itself. So once () has been used, the object will
 *wait for another () and can do infinite input without calling add()
 *anymore
 */
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class EasyInit{
private:
    vector<pair<string, string>> content;
    int counter;

public:
    EasyInit() : counter(0){}

    EasyInit& operator()(const string& first, const string& second){
        content.push_back(pair<string, string>(first, second));
        counter += 1;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const EasyInit& obj){
        for(int i = 0; i < obj.counter; i++){
            os << obj.content[i].first << ' ' << obj.content[i].second << endl;
        }
        return os;
    }
};


class AuxClass{
private:
    EasyInit obj;

public:
    AuxClass(){}

    EasyInit& input_items(){
        return obj;
    }

    EasyInit& get(){
        return obj;
    }
};

int main(int argc, char **argv){
    AuxClass aux;
    aux.input_items()
        ("ice", "cream")
        ("spring", "summer")
    ;
    cout << aux.get();
    return 0;
}
