#include <iostream>

using namespace std;

class Shape{
public:
    virtual ~Shape(){}
    virtual void draw() const = 0;
};

class Rollable{
public:
    virtual ~Rollable(){}
    virtual void roll() = 0;
};

class Circle : public Shape, public Rollable{
private:
    double angle;
    double radius;
public:
    Circle(){
        angle = 0.0;
        radius = 1;
    }
    void draw() const {
        cout << "draw circle " << angle << " " << radius << endl;
    }
    void roll(){
        angle += 0.1;
    }
    ~Circle(){}
};

class Square : public Shape{
private:   
    double edge;
public:
    Square(){
        edge = 1.0;
    }
    void draw() const {
        cout << "draw square " << edge << endl;
    }
    ~Square(){}
};

int main(){
    Circle * c1 = new Circle();
    Square * s1 = new Square();
    if(Rollable * r1 = dynamic_cast<Rollable *>(c1)){
        c1->draw();
        r1->roll();
        c1->draw();
    }
    else{
        s1->draw();
        cout << "cannot roll!" << endl;
    }
    if(Rollable * r1 = dynamic_cast<Rollable *>(s1)){
        s1->draw();
        r1->roll();
        s1->draw();
    }
    else{
        s1->draw();
        cout << "cannot roll!" << endl;
    }

    return 0;
}
