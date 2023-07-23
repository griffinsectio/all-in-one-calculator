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
            std::cout << "Perimeter of the " << this->name << " is: " << this->perimeter << '\n';
        }
};

class Square : public Shape
{
    protected:
        double sideLength;
    public:
        void calculateArea()
        {
            getLength();

            this->area = sideLength*sideLength;
        }
        void calculatePerimeter()
        {
            getLength();

            this->perimeter = 4*sideLength;
        }
        void getLength()
        {
            std::cout << "...............\n";
            std::cout << ".             .\n";
            std::cout << ".             .\n";
            std::cout << ".             .\n";
            std::cout << ".             .\n";
            std::cout << ".             .\n";
            std::cout << ".             .\n";
            std::cout << "...............\n";
            std::cout << "     length  \n\n";

            std::cout << "Give the length of the square's side: \n";
            std::cin >> this->sideLength;
        }
        
    Square()
    {

        this->name = "Square";
    }
};

class Rectangle : public Square
{
    protected:
        double sideWidth;
    public:
        void calculateArea()
        {
            getLengthAndWidthUser();

            this->area = sideLength*sideWidth;
        }
        void calculatePerimeter()
        {
            getLengthAndWidthUser();

            this->perimeter = 2 * (sideLength + sideWidth);
        }
        void getLengthAndWidthUser()
        {
            std::cout << "...............\n";
            std::cout << ".             .\n";
            std::cout << ".             . width\n";
            std::cout << ".             .\n";
            std::cout << "...............\n";
            std::cout << "      length    \n\n";

            std::cout << "Give the length of the rectangle: ";
            std::cin >> this->sideLength;
            std::cout << '\n';
            std::cout << "Give the width of the rectangle: ";
            std::cin >> this->sideWidth;
            std::cout << "\n";
        }
        void getWidth()
        {
            std::cout << "The " << this->name << "'s width is: " << this->sideWidth << '\n';
        }
        Rectangle() : Square()
        {
            this->name = "Rectangle";
        }
};

class Parallelogram : public Square
{
    protected:
        double height;
    public:
        void calculateArea()
        {
            std::cout << "       length      \n";
            std::cout << "    ...............\n";
            std::cout << "   .|            .\n ";
            std::cout << "  . |height     .\n  ";
            std::cout << " .  |          .\n   ";
            std::cout << "...............\n    ";
            std::cout << "      length  \n     ";
            std::cout << '\n';

            std::cout << "Give the length of the parallelogram: ";
            std::cin >> this->sideLength;
            std::cout << '\n';
            std::cout << "Give the height of the parallelogram: ";
            std::cin >> this->height;
            std::cout << "\n";

            this->area = sideLength*height;
        }
        void calculatePerimeter()
        {
            double firstParallel = 1;
            double secondParallel = 1;

            std::cout << "              first\n";
            std::cout << "           ...............\n";
            std::cout << "          .             .\n";
            std::cout << "second   .             .  second\n";
            std::cout << "        .             .\n";
            std::cout << "       ...............\n";
            std::cout << "              first\n";
            std::cout << '\n';

            std::cout << "Give the length of the first pair parallel side: ";
            std::cin >> firstParallel;
            std::cout << '\n';
            std::cout << "Give the length of the another pair parallel side: ";
            std::cin >> secondParallel;

            this->perimeter = 2 * (firstParallel + secondParallel);
        }
        void getHeight()
        {
            std::cout << "The " << this->name << "'s height is: " << this->height << '\n';
        }
        Parallelogram() : Square()
        {
            this->name = "Parallelogram";
        }
};

class Trapezoid : public Rectangle
{
    private:
        double base = 1;
        double top = 1;
        double height = 1;
    public:
        void calculateArea()
        {
            std::cout << "        top         " << '\n';
            std::cout << "     ----------     " << '\n';
            std::cout << "    /  |       \\   " << '\n';
            std::cout << "   /   | height \\  " << '\n';
            std::cout << "  /    |         \\ " << '\n';
            std::cout << " ------------------ " << '\n';
            std::cout << "        base        " << '\n';

            std::cout << "Give the length of base of the trapezoid: ";
            std::cin >> this->base;
            std::cout << '\n';
            std::cout << "Give the length of top of the trapezoid: ";
            std::cin >> this->top;
            std::cout << '\n';
            std::cout << "Give the height of the trapezoid: ";
            std::cin >> this->height;
            std::cout << "\n";

            this->area = ((base+top)/2)*height;
        }
        void calculatePerimeter()
        {
            double a = 1;
            double b = 1;
            std::cout << "        top         " << '\n';
            std::cout << "     ----------     " << '\n';
            std::cout << "    /          \\   " << '\n';
            std::cout << " a /            \\ b" << '\n';
            std::cout << "  /              \\ " << '\n';
            std::cout << " ------------------ " << '\n';
            std::cout << "        base        " << '\n';
            std::cout << '\n';

            std::cout << "Give the length of the base: ";
            std::cin >> this->base;
            std::cout << '\n';

            std::cout << "Give the length of the top: ";
            std::cin >> this->top;
            std::cout << '\n';

            std::cout << "Give the length of the side a: ";
            std::cin >> a;
            std::cout << '\n';

            std::cout << "Give the length of the side b: ";
            std::cin >> b;
            std::cout << '\n';

            this->perimeter = this->base + this->top + a + b;
        }
        void getHeight()
        {
            std::cout << "The " << this->name << "'s height is: " << this->height << '\n';
        }

        Trapezoid()
        {
            this->name = "Trapezoid";
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
            std::cout << "        .        " << '\n';
            std::cout << "      . | .      " << '\n';
            std::cout << "    .   |   .    " << '\n';
            std::cout << "  .  hei|ght  .  " << '\n';
            std::cout << ". . . . . . . . ." << '\n';
            std::cout << "       base      " << "\n\n";

            std::cout << "Give the length of base of the triangle: ";
            std::cin >> this->base;
            std::cout << '\n';
            std::cout << "Give the height of the triangle: ";
            std::cin >> this->height;
            std::cout << "\n";

            this->area = (base*height)/2;
        }
        void calculatePerimeter()
        {
            double a = base;
            double b = 1;
            double c = 1;

            std::cout << "All triangle sides is required in order to calculate it perimeter.\n"
                << "And each side is labeled as a, b, and c.\n\n";

            std::cout << "        .        " << '\n';
            std::cout << "      .   .      " << '\n';
            std::cout << "  a .       . b  " << '\n';
            std::cout << "  .           .  " << '\n';
            std::cout << ". . . . . . . . ." << '\n';
            std::cout << "        b        " << "\n\n";

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

    Triangle()
    {
        this->name = "Triangle";
    }
};

class Rhombus : public Shape
{
    protected:
        double diagonal1;
        double diagonal2;
    public:
        void calculateArea()
        {
            getDiagonals();

            this->area = (diagonal1*diagonal2)/2;
        }
        void calculatePerimeter()
        {
            double hypotenuse = std::sqrt(std::pow(std::pow(diagonal1, 2), std::pow(diagonal2, 2)));
            this->perimeter = 4 * hypotenuse;
        }
        void getDiagonals()
        {
            if (this->name == "Rhombus")
            {
                std::cout << "                  _  \n";
                std::cout << "        .          | \n";
                std::cout << "      . | .        | \n";
                std::cout << "    .   |   .      | \n";
                std::cout << "  .     |     .    | \n";
                std::cout << ".---------------.  | diagonal 2\n";
                std::cout << "  .     |     .    | \n";
                std::cout << "    .   |   .      | \n";
                std::cout << "      . | .        | \n";
                std::cout << "        .         _| \n";
                std::cout << "|________________|   \n";
                std::cout << "    diagonal 1     \n\n";
            } else if (this->name == "Kite")
            {
                std::cout << "                _  \n";
                std::cout << "        .        |" << '\n';
                std::cout << "      . | .      |" << '\n' ;
                std::cout << "    .   |   .    |" << '\n';
                std::cout << "  .-----|-----.  |" << '\n';
                std::cout << "   .    |    .   | diagonal 2" << '\n';
                std::cout << "    .   |   .    |" << '\n' ;
                std::cout << "     .  |  .     |" << '\n';
                std::cout << "      . | .      |" << '\n';
                std::cout << "       .|.       |" << '\n';
                std::cout << "        .       _|" << "\n";
                std::cout << " |____________|   \n";
                std::cout << "   diagonal 1   \n\n";
            }

            std::cout << "Give the length of the first diagonal of the " << this->name << ": ";
            std::cin >> this->diagonal1;
            std::cout << '\n';
            std::cout << "Give the length of the second diagonal of the " << this->name << ": ";
            std::cin >> this->diagonal2;
            std::cout << "\n";
        }

    Rhombus()
    {
        this->name = "Rhombus";
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
            std::cout << "        .       " << "\n\n";

            std::cout << "Give the length of side a: ";
            std::cin >> a;
            std::cout << '\n';

            std::cout << "Give the length of side b: ";
            std::cin >> b;
            std::cout << '\n';

            this->perimeter = 2 * (a + b);
        }
    public:
        Kite() : Rhombus()
        {
            this->name = "Kite";
        }
};

