#include <iostream>
#include <cmath>
#include "../headers/Solid.h"

    
int main()
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
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cout << '\n';

        switch(choice)
        {
            case 1:
            {
                double length;
                std::cout << "Give the length of the cube side: ";
                std::cin >> length;
                std::cout << "\n\n";

                Cube cube(length);
                cube.getLength();
                cube.calculateSurfaceArea();
                cube.calculateVolume();
                cube.getSurfaceArea();
                cube.getVolume();

                break;
            }
            case 2:
            {
                double length, width, height;
                std::cout << "Give the length of the cuboid: ";
                std::cin >> length;
                std::cout << '\n';
                std::cout << "Give the width of the cuboid: ";
                std::cin >> width;
                std::cout << "Give the height of the cuboid: ";
                std::cin >> height;
                std::cout << "\n\n";

                Cuboid cuboid(length, width, height);
                cuboid.getLength();
                cuboid.getWidth();
                cuboid.getHeight();
                cuboid.calculateSurfaceArea();
                cuboid.calculateVolume();
                cuboid.getSurfaceArea();
                cuboid.getVolume();

                break;
            }
            case 3:
            {
                double length, width, height;
                std::cout << "Give the length of the pyramid: ";
                std::cin >> length;
                std::cout << '\n';
                std::cout << "Give the width of the pyramid: ";
                std::cin >> width;
                std::cout << "Give the height of the pyramid: ";
                std::cin >> height;
                std::cout << "\n\n";

                Pyramid pyramid(length, width, height);
                pyramid.getLength();
                pyramid.getWidth();
                pyramid.getHeight();
                pyramid.calculateSurfaceArea();
                pyramid.calculateVolume();
                pyramid.getSurfaceArea();
                pyramid.getVolume();

                break;
            }
            case 4:
            {
                double radius;
                std::cout << "Give the radius of the sphere: ";
                std::cin >> radius;
                std::cout << "\n\n";

                Sphere sphere(radius);
                sphere.getRadius();
                sphere.calculateSurfaceArea();
                sphere.calculateVolume();
                sphere.getSurfaceArea();
                sphere.getVolume();

                break;
            }
            case 5:
            {
                double radius, height;
                std::cout << "Give the radius of the cone: ";
                std::cin >> radius;
                std::cout << '\n';
                std::cout << "Give the height of the cone: ";
                std::cin >> height;
                std::cout << "\n\n";

                Cone cone(radius, height);
                cone.getRadius();
                cone.getHeight();
                cone.calculateSurfaceArea();
                cone.calculateVolume();
                cone.getSurfaceArea();
                cone.getVolume();

                break;
            }
            case 6:
            {
                double radius, height;
                std::cout << "Give the radius of the cylinder: ";
                std::cin >> radius;
                std::cout << '\n';
                std::cout << "Give the height of the cylinder: ";
                std::cin >> height;
                std::cout << "\n\n";

                Cylinder cylinder(radius, height);
                cylinder.getRadius();
                cylinder.getHeight();
                cylinder.calculateSurfaceArea();
                cylinder.calculateVolume();
                cylinder.getSurfaceArea();
                cylinder.getVolume();

                break;
            }
            default:
                std::cout << "Unknown choice!\n";
                std::cout << "Aborting...!\n";
                break;
    }
    }while (true);
    return 0;
}
