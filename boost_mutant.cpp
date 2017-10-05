#include <utility>
#include <iostream>
using namespace std;

template <class pair>
struct Reverse{
    typedef typename pair::first_type second_type;
    typedef typename pair::second_type first_type;
    second_type second;
    first_type first;
};

template<class pair>
Reverse<pair> & mutate(pair & p){
    return reinterpret_cast<Reverse<pair> &>(p);
}

int main(){
    pair<double, int> p(1.34, 5);
    cout << mutate(p).first << "," << mutate(p).second << endl;
}
