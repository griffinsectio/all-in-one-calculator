#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "../headers/Shape.h"

template <typename T>
void areaOrParameter(T shape);
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
                Square sqre;

                areaOrParameter<Square>(sqre);

                std::cout << '\n';
        
                break;
            }
            case 2:
            {
                Rectangle rect;

                areaOrParameter<Rectangle>(rect);

                std::cout << '\n';
    
                break;
            }
            case 3:
            {
                Parallelogram par;
                areaOrParameter<Parallelogram>(par);

                std::cout << '\n';
    
                break;
            }
            case 4:
            {
                Trapezoid trap;
                areaOrParameter<Trapezoid>(trap);

                std::cout << '\n';
    
                break;
            }
            case 5:
            {
                Triangle tri;
                areaOrParameter<Triangle>(tri);

                std::cout << '\n';
    
                break;
            }
            case 6:
            {
                Rhombus rhom;
                areaOrParameter<Rhombus>(rhom);
                std::cout << '\n';
    
                break;
            }
    
            case 7:
            {
                Kite kite;
                areaOrParameter<Kite>(kite);
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


template <typename T>
void areaOrParameter(T shape)
{
    int choice = 0;
    std::cout << "What do you want to calculate? \n";
    std::cout << "1. Area.\n";
    std::cout << "2. Parameter.\n";
    std::cout << "Your choice (0 to exit): ";
    std::cin >> choice;
    std::cout << '\n';

    if (choice == 1)
    {
        shape.calculateArea();
        shape.getArea();
    } else if (choice == 2)
    {
        shape.calculatePerimeter();
        shape.getPerimeter();
    }
    return;
}
