#include <iostream>
#include <unistd.h>
#include <cmath>

double toDoubleCoefficient(char coefficientArray[], int coefficientArraySize);
double toDoublePower(char powerArray[], int powerArraySize);
bool userConfirmation();

void derivation()
{
    do {
        std::string expression = "";
        int indexOfVariable = 0;
        int power = 0;

        std::cout << "Give the expression (example: 1x^2): ";
        std::cin >> expression;

        // I have to add 1 extra size for the null-character
        int sizeForArray = expression.size() + 1;
        char expressionArray[sizeForArray];

        // Break down each character of the expression string
        // to an array of characters
        for (int i = 0; i < sizeForArray; i++)
        {
            expressionArray[i] = expression[i];
        }

        // Find the index of the variable
        for (int j = 0; j < sizeForArray; j++)
        {
            if (expressionArray[j] == 'x')
            {
                indexOfVariable = j;
                break;
            }
        }

        // Add the coefficient to it's own array
        int coefficientArraySize = indexOfVariable;
        char coefficientArray[coefficientArraySize];
        for (int k = 0; k < indexOfVariable; k++) 
        {
            coefficientArray[k] = expressionArray[k];    
        }

        // Add the power to it's own array
        int powerArraySize = sizeForArray - (indexOfVariable + 2);
        char powerArray[powerArraySize + 1];
        int indexOfPowerDigit = indexOfVariable + 2;

       if(expressionArray[indexOfVariable + 1] == '^')
       {
           for (int l = 0; l <= powerArraySize; l++)
           {
               powerArray[l] = expressionArray[indexOfPowerDigit + l];
           }
       }

       // Get the coefficient and power that have been translated to type of double
        double coefficient = toDoubleCoefficient(coefficientArray, coefficientArraySize);
        power = toDoubleCoefficient(powerArray, powerArraySize);

        // start calculating the derivative
        double finalCoefficient = coefficient * power;
        double finalPower = power - 1;

        if (finalPower == 1)
        {
            std::cout << "The derivative is: " << finalCoefficient << 'x';
        }
        else if (finalPower == 0)
        {
            std::cout << "The derivative is: " << finalCoefficient; 
        }
        else if (finalCoefficient == 0)
        {
            std::cout << "The derivative is: 0";
        }
        else {
            std::cout << "The derivative is: " << finalCoefficient << "x^" << finalPower;
        }
        std::cout << "\n\n"; 
    }while (userConfirmation());
}

double toDoubleCoefficient(char coefficientArray[], int coefficientArraySize)
{
    std::string stringOfCoefficient = "";

    for (int i = 0; i < coefficientArraySize; i++)
    {
        // Append the char to string
        stringOfCoefficient.push_back(coefficientArray[i]);
    }

    double coefficient = std::stoi(stringOfCoefficient);
    return coefficient;
}

double toDoublePower(char powerArray[], int powerArraySize)
{
    std::string stringOfPower = "";

    for (int j = 0; j < powerArraySize; j++)
    {
        // Append the char to string
        stringOfPower.push_back(powerArray[j]);
    } 
    
    double power = std::stoi(stringOfPower);
    return power;
}
