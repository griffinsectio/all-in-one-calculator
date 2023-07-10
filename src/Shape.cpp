#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "../headers/Shape.h"

bool userConfirmation();

void shapeCalculator()
{
    do {
        int choice;
        std::cout << "What shape you want to calculate? \n";
        std::cout << "1. Square\n";
        std::cout << "2. Rectangle\n";
        std::cout << "3. Parallelogram\n";
        std::cout << "4. Trapezoid\n";
        std::cout << "5. Triangle\n";
        std::cout << "6. Rhombus\n";
        std::cout << "7. Kite \n";
        std::cout << "Your choice (0 to back to main menu): ";
        std::cin >> choice;
        std::cout << '\n';
    
        switch(choice)
        {
            case 0:
            {
                system("clear");
                return;
            }
            case 1:
            {
                double length;
                std::cout << "Give the length of the square side: ";
                std::cin >> length;
                std::cout << "\n\n";
    
                Square sqre(length);
                sqre.getLength();
                sqre.calculateArea();
                sqre.getArea();
                std::cout << '\n';
        
                break;
            }
            case 2:
            {
                double length, width;
                std::cout << "Give the length of the rectangle: ";
                std::cin >> length;
                std::cout << '\n';
                std::cout << "Give the width of the rectangle: ";
                std::cin >> width;
                std::cout << "\n\n";
    
                Rectangle rect(length, width);
                rect.getLength();
                rect.getWidth();
                rect.calculateArea();
                rect.getArea();
                std::cout << '\n';
    
                break;
            }
            case 3:
            {
                double length, height;
                std::cout << "Give the length of the parallelogram: ";
                std::cin >> length;
                std::cout << '\n';
                std::cout << "Give the height of the parallelogram: ";
                std::cin >> height;
                std::cout << "\n\n";
    
                Parallelogram par(length, height);
                par.getLength();
                par.getHeight();
                par.calculateArea();
                par.getArea();
                std::cout << '\n';
    
                break;
            }
            case 4:
            {
                double length, width, height;
                std::cout << "Give the length of base of the trapezoid: ";
                std::cin >> length;
                std::cout << '\n';
                std::cout << "Give the length of top of the trapezoid: ";
                std::cin >> width;
                std::cout << '\n';
                std::cout << "Give the height of the trapezoid: ";
                std::cin >> height;
                std::cout << "\n\n";
    
                Trapezoid trap(length, width, height);
                trap.getLength();
                trap.getWidth();
                trap.getHeight();
                trap.calculateArea();
                trap.getArea();
                std::cout << '\n';
    
                break;
            }
            case 5:
            {
                double base, height;
                std::cout << "Give the length of base of the triangle: ";
                std::cin >> base;
                std::cout << '\n';
                std::cout << "Give the height of the triangle: ";
                std::cin >> height;
                std::cout << "\n\n";
    
                Triangle tri(base, height);
                tri.getBase();
                tri.getHeight();
                tri.calculateArea();
                tri.getArea();
                std::cout << '\n';
    
                break;
            }
            case 6:
            {
                double dig1, dig2;
                std::cout << "Give the length of the first diagonal of the rhombus: ";
                std::cin >> dig1;
                std::cout << '\n';
                std::cout << "Give the length of the second diagonal of the rhombus: ";
                std::cin >> dig2;
                std::cout << "\n\n";
    
                Rhombus rhom(dig1, dig2);
                rhom.getDiagonal1();
                rhom.getDiagonal2();
                rhom.calculateArea();
                rhom.getArea();
                std::cout << '\n';
    
                break;
            }
            case 7:
            {
                double dig1, dig2;
                std::cout << "Give the length of the first diagonal of the kite: ";
                std::cin >> dig1;
                std::cout << '\n';
                std::cout << "Give the length of the second diagonal of the kite: ";
                std::cin >> dig2;
                std::cout << "\n\n";
    
                Kite kite(dig1, dig2);
                kite.getDiagonal1();
                kite.getDiagonal2();
                kite.calculateArea();
                kite.getArea();
                std::cout << '\n';
    
                break;
            }
            default:
                std::cout << "Unknown choice!\n";
                std::cout << "Aborting...!\n";
                break;
        }
    }while (userConfirmation());
}

