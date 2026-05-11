#include <iostream>

class Shape{
    public:
    Shape(){};

    Shape(double w, double l){
        width = w;
        length = l;
    };

    ~Shape(){};

    void set_width(double w){
        width = w;
    }

    void set_length(double l){
        length = l;
    }

    protected:
    double width;
    double length;
};

class Rectangle : public Shape{
    public:
    Rectangle(){};

    Rectangle(double w, double l){
        width = w;
        length = l;
    }

    ~Rectangle(){};

    double get_area(){
        return width * length;
    }

    private:
    double width;
    double length;
};

class Triangle{
    public:
    Triangle(){};

    Triangle(double b, double h){
        base = b;
        height = h;
    }

    ~Triangle(){};

    double get_area(){
        return base * height/2.0;
    }

    private:
    double base;
    double height;
};