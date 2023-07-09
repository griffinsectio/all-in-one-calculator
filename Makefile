.PHONY: all clean

CXX = g++
objects = main.o QuadraticEquation.o Trigonometry.o Shape.o Solid.o
Quadratic = QuadraticEquation.cpp 
Trigonometry = Trigonometry.cpp 
Shape = Shape.cpp Shape.h
Solid = Solid.cpp Solid.h

all: main

main: $(objects) 
	$(CXX) -o main $(objects)

main.o: main.cpp
	$(CXX) -c main.cpp

QuadraticEquation.o: $(Quadratic)
	$(CXX) -c QuadraticEquation.cpp

Trigonometry.o: $(Trigonometry)
	$(CXX) -c Trigonometry.cpp

Shape.o: $(Shape)
	$(CXX) -c Shape.cpp

Solid.o: $(Solid)
	$(CXX) -c Solid.cpp

clean:
	rm *.o main
