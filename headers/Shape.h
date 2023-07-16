#pragma once
#include <cmath>
#include <iostream>

class Shape
{
    protected:
        std::string name;
        double area = 0;
        double perimeter = 0;
    public:
        void getArea()
        {
            std::cout << "Area of the " << this->name << " is: " << this->area << '\n';
        }
        void getPerimeter()
        {
            std::cout << "Perimter of the " << this->name << " is: " << this->perimeter << '\n';
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
        void calculatePerimeter()
        {
            this->perimeter = 4*sideLength;
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
        void calculatePerimeter()
        {
            this->perimeter = 2 * (sideLength + sideWidth);
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
        void calculatePerimeter()
        {
            double extraSide = 1;
            std::cout << "Give the length of the another parallel side: ";
            std::cin >> extraSide;

            this->perimeter = 2 * (sideLength + extraSide);
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
        void calculatePerimeter()
        {
            double a = 1;
            double b = 1;
            std::cout << "     ----------" << '\n';
            std::cout << "    /          \\ '\n'";
            std::cout << "a /             \\ b '\n'";
            std::cout << "/----------------\\ '\n'";
            std::cout << '\n';

            std::cout << "Give the length of the side a: ";
            std::cin >> a;
            std::cout << '\n';

            std::cout << "Give the length of the side b: ";
            std::cin >> b;
            std::cout << '\n';

            this->perimeter = sideLength + sideWidth + a + b;
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
        void calculatePerimeter()
        {
            double a = base;
            double b = 1;
            double c = 1;

            std::cout << "All triangle sides is required in order to calculate it perimeter.\n"
                << "And each side is labeled as a, b, and c.\n\n";

            std::cout << "Give the length of side a: ";
            std::cin >> a;
            std::cout << '\n';

            std::cout << "Give the length of side b: ";
            std::cin >> b;
            std::cout << '\n';

            std::cout << "Give the length of side c: ";
            std::cin >> c;
            std::cout << "\n\n";

            this->perimeter = a + b + c;
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
        void calculatePerimeter()
        {
            double hypotenuse = std::sqrt(std::pow(std::pow(diagonal1, 2), std::pow(diagonal2, 2)));
            this->perimeter = 4 * hypotenuse;
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
        void calculatePerimeter()
        {
            double a = 1;
            double b = 1;
            std::cout << "        .      " << '\n';
            std::cout << "      . | .    " << '\n' ;
            std::cout << "  a .   |   . a" << '\n';
            std::cout << "  .-----|-----. " << '\n';
            std::cout << "   .    |    .  " << '\n';
            std::cout << "    .   |   .   " << '\n' ;
            std::cout << "  b  .  |  . b  " << '\n';
            std::cout << "      . | .     " << '\n';
            std::cout << "       .|.      " << '\n';
            std::cout << "        .       " << '\n';

            std::cout << "Give the length of side a: ";
            std::cin >> a;
            std::cout << '\n';

            std::cout << "Give the length of side b: ";
            std::cin >> b;
            std::cout << '\n';

            this->perimeter = 2 * (a + b);
        }
    public:
        Kite(double diagonal1, double diagonal2) : Rhombus(diagonal1, diagonal2)
        {
            this->name = "Kite";
        }
};

