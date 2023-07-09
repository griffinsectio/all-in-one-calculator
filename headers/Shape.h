#pragma once
#include <iostream>

class Shape
{
    protected:
        std::string name;
        double area;
    public:
        void getArea()
        {
            std::cout << "Area of the " << this->name << " is: " << this->area << '\n';
        }
};

class Square : public Shape
{
    protected:
        double sideLength;
    public:
        void calculateArea()
        {
            this->area = sideLength*sideLength;
        }
        void getLength()
        {
            std::cout << "The " << this->name << "'s length is: " << this->sideLength << '\n';
        }

    Square(double sideLength)
    {
        this->name = "Square";
        this->sideLength = sideLength;
    }
};

class Rectangle : public Square
{
    protected:
        double sideWidth;
    public:
        void calculateArea()
        {
            this->area = sideLength*sideWidth;
        }
        void getWidth()
        {
            std::cout << "The " << this->name << "'s width is: " << this->sideWidth << '\n';
        }
        Rectangle(double sideLength, double sideWidth) : Square(sideLength)
        {
            this->name = "Rectangle";
            this->sideWidth = sideWidth;
        }
};

class Parallelogram : public Square
{
    protected:
        double height;
    public:
        void calculateArea()
        {
            this->area = sideLength*height;
        }
        void getHeight()
        {
            std::cout << "The " << this->name << "'s height is: " << this->height << '\n';
        }
        Parallelogram(double sideLength, double height) : Square(sideLength)
        {
            this->name = "Parallelogram";
            this->height =  height;
        }
};

class Trapezoid : public Rectangle
{
    private:
        double height;
    public:
        void calculateArea()
        {
            this->area = ((sideLength+sideWidth)/2)*height;
        }
        void getHeight()
        {
            std::cout << "The " << this->name << "'s height is: " << this->height << '\n';
        }

        Trapezoid(double sideLength, double sideWidth, double height) : Rectangle(sideLength, sideWidth)
        {
            this->height = height;
            this->Rectangle::name = "Trapezoid";
        }
};

class Triangle : public Shape
{
    private:
        double base;
        double height;
    public:
        void calculateArea()
        {
            this->area = (base*height)/2;
        }
        void getBase()
        {
            std::cout << "The " << this->name << "'s base is: " << this->base << '\n';
        }
        void getHeight()
        {
            std::cout << "The " << this->name << "'s height is: " << this->height << '\n';
        }

    Triangle(double base, double height)
    {
        this->name = "Triangle";
        this->base = base;
        this->height = height;
    }
};

class Rhombus : public Shape
{
    private:
        double diagonal1;
        double diagonal2;
    public:
        void calculateArea()
        {
            this->area = (diagonal1*diagonal2)/2;
        }
        void getDiagonal1()
        {
            std::cout << this->name << "'s first diagonal has the length of " << this->diagonal1 << '\n';
        }
        void getDiagonal2()
        {
            std::cout << this->name << "'s second diagonal has the length of " << this->diagonal2 << '\n';
        }

    Rhombus(double diagonal1, double diagonal2)
    {
        this->name = "Rhombus";
        this->diagonal1 = diagonal1;
        this->diagonal2 = diagonal2;
    }
};

class Kite : public Rhombus
{
    public:
        Kite(double diagonal1, double diagonal2) : Rhombus(diagonal1, diagonal2)
        {
            this->name = "Kite";
        }
};

