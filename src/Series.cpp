#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include "../headers/exprtk.hpp"

template <typename T>
void getNthValue(std::string pattern, int indexOfValue);
bool userConfirmation();

void series()
{
    do {
        int choice;
        std::string pattern;
        std::cout << "Give the pattern (using n variable, like 2n+1): \n";
        std::cin >> pattern;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');

        std::cout << "What do you wanted to do? \n";
        std::cout << "1. Find the n-th value.\n";
        std::cout << "2. Sum until n-th value.\n";
        std::cout << "Your choice (0 to back to main menu): ";
        std::cin >> choice;
        std::cout << "\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');

        switch(choice)
        {
            case 0:
                {
                    system("clear");
                    return;
                }
            case 1:
                {
                    int indexOfValue;
                    std::cout << "Give the index of the value you want to know: ";
                    std::cin >> indexOfValue;
                    getNthValue<double>(pattern, indexOfValue);
                    break;
                }
            case 2:
                {
                    std::cout << "Soon!\n";
                    break;
                }
        }
    }while (userConfirmation());
}

template <typename T>
void getNthValue(std::string pattern, int indexOfValue)
{
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>   expression_t;
    typedef exprtk::parser<T>       parser_t;

    T n;

    symbol_table_t symbol_table;
    symbol_table.add_variable("n",n);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(pattern, expression);

    if (!parser.compile(pattern,expression))
    {
        std::cout << "Compilation error...\n";
        return;
    }
    else {
        n = T(indexOfValue);
        T y = expression.value();
        std::cout << "The " << indexOfValue << "-th value is: " << y << "\n\n";
    }
}

