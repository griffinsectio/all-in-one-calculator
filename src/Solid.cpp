#include <iostream>
#include <cmath>
#include "../headers/Solid.h"

template <typename T>
void surfaceOrVolume(T solid);
bool userConfirmation();

void solidCalculator()
{
    do {
        int choice;
        std::cout << "What shape you want to calculate? \n";
        std::cout << "1. Cube\n";
        std::cout << "2. Cuboid\n";
        std::cout << "3. Pyramid\n";
        std::cout << "4. Sphere\n";
        std::cout << "5. Cone\n";
        std::cout << "6. Cylinder\n";
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
                Cube cube;
                surfaceOrVolume(cube);

                std::cout << '\n';
 
                break;
            }
            case 2:
            {
                Cuboid cuboid;
                surfaceOrVolume(cuboid);

                std::cout << '\n';
    
                break;
            }
            case 3:
            {
                Pyramid pyramid;
                surfaceOrVolume(pyramid);

                std::cout << '\n';
    
                break;
            }
            case 4:
            {
                Sphere sphere;
                surfaceOrVolume(sphere);

                std::cout << '\n';
    
                break;
            }
            case 5:
            {
                Cone cone;
                surfaceOrVolume(cone);

                std::cout << '\n';
    
                break;
            }
            case 6:
            {
                Cylinder cylinder;
                surfaceOrVolume(cylinder);

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
void surfaceOrVolume(T solid)
{
    int choice = 0;
    std::cout << "What do you want to calculate? \n";
    std::cout << "1. Surface area.\n";
    std::cout << "2. Volume.\n";
    std::cout << "Your choice (0 to exit): ";
    std::cin >> choice;
    std::cout << '\n';

    if (choice == 1)
    {
        solid.calculateSurfaceArea();
        solid.getSurfaceArea();
    } else if (choice == 2)
    {
        solid.calculateVolume();
        solid.getVolume();
    }
    return;
}
