#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle();

    Rectangle(float l, float w);

    ~Rectangle();

    void set_length(float l);

    void set_width(float w);

    float get_area();

private:
    float m_length;
    float m_width;
};

class Triangle
{
public:
    Triangle();

    Triangle(float b, float h);

    ~Triangle();

    void set_base(float b);

    void set_height(float h);

    float get_area();

private:
    float m_base;
    float m_height;
};

#endif