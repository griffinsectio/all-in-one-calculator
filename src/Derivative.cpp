#include <iostream>
#include <unistd.h>
#include <cmath>

void powerRule();
void trigonometricExpression();
double toDoubleCoefficient(char coefficientArray[], int coefficientArraySize);
double toDoublePower(char powerArray[], int powerArraySize);
bool userConfirmation();

void derivation()
{
    do {
        int userChoice = 0;

        std::cout << "What do kind of expression you want to differentiate? \n";
        std::cout << "1. Regular expression \n";
        std::cout << "2. Trigonometric expression \n";
        std::cout << "Your choice (0 to exit): ";
        std::cin >> userChoice;
        std::cout << '\n';

        switch (userChoice) {
            case 0:
            {
                system("clear");
                return;
            }
            case 1:
            {
                std::cout << "Be aware that this feature only able to differentiate single term expression\n";
                std::cout << "and only able to take an integer power.\n\n";

                powerRule();

                break;
            }
            case 2:
            {
                trigonometricExpression();

                break;
            }
        }

    }while (userConfirmation());
}

void powerRule()
{
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
}

void trigonometricExpression()
{
    int userChoice = 0;
    std::cout << "What trigonometric function you want to differentiate? \n";
    std::cout << "1. sin(x) \n";
    std::cout << "2. cos(x) \n";
    std::cout << "3. tan(x) \n";
    std::cout << "4. csc(x) \n";
    std::cout << "5. sec(x) \n";
    std::cout << "6. cot(x) \n";
    std::cout << "Your choice (0 to exit): ";

    std::cin >> userChoice;
    std::cout << '\n';

    switch (userChoice) {
        case 1:
        {
            std::cout << "d/dx sin(x) = cos(x)\n\n";
            break;
        }
        case 2:
        {
            std::cout << "d/dx cos(x) = -sin(x)\n\n";
            break;
        }
        case 3:
        {
            std::cout << "d/dx tan(x) = sec^2(x)\n\n";
            break;
        }
        case 4:
        {
            std::cout << "d/dx csc(x) = -csc(x)cot(x)\n\n";
            break;
        }
        case 5:
        {
            std::cout << "d/dx sec(x) = sec(x)tan(x)\n\n";
            break;
        }
        case 6:
        {
            std::cout << "d/dx cot(x) = -csc^2(x)\n\n";
            break;
        }
    }
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
