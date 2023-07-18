#include <iomanip>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include "../headers/exprtk.hpp"

template <typename T>
void calculateIntegral(std::string *expressionToIntegrate, double *startEndpoint, double *endPoint);
bool userConfirmation();

void integrate()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::string expression = "";
        double startEndpoint = 0;
        double endEndpoint = 0;

        std::cout << "Give the function you want to integrate (ex. x^2+1): ";
        std::getline(std::cin, expression);
        std::cout << '\n';
        
        std::cout << "Give the start endpoint: ";
        std::cin >> startEndpoint;
        std::cout << '\n';

        std::cout << "Give the end endpoint: ";
        std::cin >> endEndpoint;
        std::cout << '\n';

        calculateIntegral<double>(&expression, &startEndpoint, &endEndpoint); 
    }while (userConfirmation());
}


template <typename T>
void calculateIntegral(std::string *expressionToIntegrate, double *startEndpoint, double *endPoint)
{
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>   expression_t;
    typedef exprtk::parser<T>       parser_t;
    double length = *endPoint - *startEndpoint;
    double amountOfPartitions = length * 1000;
    double rectWidth = length / amountOfPartitions;

    T x;

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(*expressionToIntegrate, expression);

    if (!parser.compile(*expressionToIntegrate,expression))
    {
        std::cout << "Compilation error...\n";
        return;
    }
    else {
        double sum = 0;
        for (x = T(*startEndpoint); x <= T(*endPoint); x += length/amountOfPartitions)
        {
            T y = expression.value() * rectWidth;
            sum += y;
        }
        std::cout << "The integral is: " << std::setprecision(2) << sum << '\n';
    }
}
