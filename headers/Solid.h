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
            setSurfaceArea(6*length*length);
        }
        void calculateVolume()
        {
            setVolume(length*length*length);
        }
        Cube(double length)
        {
            this->name = "cube";
            this->length = length;
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
        Cuboid(double length, double width, double height) : Cube(length)
        {
            this->name = "cuboid";
            this->width = width;
            this->height = height;
        }
};

class Pyramid : public Cuboid
{
    public:
        void calculateSurfaceArea()
        {
            setSurfaceArea((length*width) +
                    (length*std::sqrt(pow(width/2, 2) + height*height)) +
                    (width*std::sqrt(pow(length/2, 2) + height*height)));
        }
        void calculateVolume()
        {
            setVolume((length*width*height)/3);
        }
        Pyramid(double length, double width, double height) : Cuboid(length, width, height)
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
            setSurfaceArea(4*pi*std::pow(radius, 2));
        }
        void calculateVolume()
        {
            setVolume((4*pi*std::pow(radius, 3))/3);
        }
        Sphere(double radius)
        {
            this->name = "sphere";
            this->radius = radius;
        }
};

class Cone : public Sphere
{
    protected:
        double height;

    public:
        void calculateSurfaceArea()
        {
            setSurfaceArea(pi*radius*(radius+std::sqrt(std::pow(height, 2)+std::pow(radius, 2))));
        }
        void calculateVolume()
        {
            setVolume((pi*std::pow(radius, 2)*height)/3);
        }
	    Cone(double radius, double height) : Sphere(radius)
	    {
            this->name = "cone";
	        this->height = height;
	    }
};

class Cylinder : public Sphere
{
    protected:
        double height;

    public:
        void calculateSurfaceArea()
        {
            setSurfaceArea(2*pi*radius*(height+radius));
        }
        void calculateVolume()
        {
            setVolume(pi*std::pow(radius, 2)*height);
        }
	   Cylinder(double radius, double height) : Sphere(radius)
	   {
            this->name = "cylinder";
	       this->height = height;
	   }
};
