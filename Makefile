.PHONY: all clean

CXX = g++
mainSource = ./src/main.cpp
objects = main.o QuadraticEquation.o Trigonometry.o Shape.o Solid.o Series.o
Quadratic = ./src/QuadraticEquation.cpp 
Trigonometry = ./src/Trigonometry.cpp 
Shape = ./src/Shape.cpp ./headers/Shape.h
Solid = ./src/Solid.cpp  ./headers/Solid.h
Series = ./src/Series.cpp ./headers/exprtk.hpp

all: main

main: $(objects) 
	$(CXX) -o main $(objects)

main.o: $(mainSource)
	$(CXX) -c ./src/main.cpp

QuadraticEquation.o: $(Quadratic)
	$(CXX) -c ./src/QuadraticEquation.cpp

Trigonometry.o: $(Trigonometry)
	$(CXX) -c ./src/Trigonometry.cpp

Shape.o: $(Shape)
	$(CXX) -c ./src/Shape.cpp

Solid.o: $(Solid)
	$(CXX) -c ./src/Solid.cpp

Series.o: $(Series)
	$(CXX) -c ./src/Series.cpp

clean:
	rm *.o main
