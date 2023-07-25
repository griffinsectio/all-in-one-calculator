#include <cmath>
#include <iostream>
#include <math.h>

class Solid
{
    private:
        double surfaceArea;
        double volume;
    protected:
       std::string name;
	   void setSurfaceArea(double surfaceArea)
	       {
	           this->surfaceArea = surfaceArea;
	       }
	       void setVolume(double volume)
	       {
	           this->volume = volume;
	       }
    public:
        void getSurfaceArea()
        {
            std::cout << "The " << this->name << "'s surface area is: " << surfaceArea << '\n';
        }
        void getVolume()
        {
            std::cout << "The " << this->name << "'s volume is: " << this->volume << '\n';
        }
};

class Cube : public Solid
{
    protected:
        double length;
    public:
        void calculateSurfaceArea()
        {
            getLength();

            setSurfaceArea(6*length*length);
        }
        void calculateVolume()
        {
            getLength();

            setVolume(length*length*length);
        }
        void getLength()
        {
            std::cout << "Give the length of the cube side: ";
            std::cin >> length;
            std::cout << '\n';
        }
        Cube()
        {
            this->name = "cube";
        }
};

class Cuboid : public Cube
{
    protected:
        double width;
        double height;
    public:
        void calculateSurfaceArea()
        {
            setSurfaceArea(2*((length*width) + (length*height) + (width*height)));
        }
        void calculateVolume()
        {
            setVolume(length*width*height);
        }
        void getAllLength()
        {
           std::cout << "Give the length of the " << this->name  << ": ";
           std::cin >> length;
           std::cout << '\n';
           std::cout << "Give the width of the " << this->name << ": ";
           std::cin >> width;
           std::cout << '\n';
           std::cout << "Give the height of the " << this->name << ": ";
           std::cin >> height;
           std::cout << '\n';
        }
        Cuboid()
        {
            this->name = "cuboid";
        }
};

class Pyramid : public Cuboid
{
    public:
        void calculateSurfaceArea()
        {
            Cuboid::getAllLength();

            setSurfaceArea((length*width) +
                    (length*std::sqrt(pow(width/2, 2) + height*height)) +
                    (width*std::sqrt(pow(length/2, 2) + height*height)));
        }
        void calculateVolume()
        {
            Cuboid::getAllLength();

            setVolume((length*width*height)/3);
        }
        Pyramid()
        {
            this->name = "pyramid";
        }
};

class Sphere : public Solid
{
    protected:
        double radius;
        const double pi = 3.14159265358979323846;

    public:
        void calculateSurfaceArea()
        {
            getRadius();

            setSurfaceArea(4*pi*std::pow(radius, 2));
        }
        void calculateVolume()
        {
            getRadius();

            setVolume((4*pi*std::pow(radius, 3))/3);
        }
        void getRadius()
        {
            std::cout << "Give the radius of the sphere: ";
            std::cin >> this->radius;
            std::cout << '\n';
        }
        Sphere()
        {
            this->name = "sphere";
        }
};

class Cylinder : public Sphere
{
    protected:
        double height;

    public:
        void calculateSurfaceArea()
        {
            getAllLength();
            
            setSurfaceArea(2*pi*radius*(height+radius));
        }
        void calculateVolume()
        {
            getAllLength();

            setVolume(pi*std::pow(radius, 2)*height);
        }
        void getAllLength()
        {
            std::cout << "Give the radius of the " << this->name << ": ";
            std::cin >> this->radius;
            std::cout << '\n';
            std::cout << "Give the height of the " << this->name << ": ";
            std::cin >> this->height;
            std::cout << '\n';
        }
	   Cylinder() : Sphere()
	   {
           this->name = "cylinder";
	   }
};

class Cone : public Cylinder
{
    protected:
        double height;

    public:
        void calculateSurfaceArea()
        {
            getAllLength();

            setSurfaceArea(pi*radius*(radius+std::sqrt(std::pow(height, 2)+std::pow(radius, 2))));
        }
        void calculateVolume()
        {
            getAllLength();

            setVolume((pi*std::pow(radius, 2)*height)/3);
        }
	    Cone(): Cylinder()
	    {
            this->name = "cone";
	    }
};

