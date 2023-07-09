#include <iostream>
#include <cmath>

void trigonometry()
{
    int choice = 0;
    double functionArgument = 0;

    std::cout << "Please choose one of these function: \n";
    std::cout << "1. sin\n";
    std::cout << "2. cos\n";
    std::cout << "3. tan\n";
    std::cout << "4. csc\n";
    std::cout << "5. sec\n";
    std::cout << "6. cot\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    std::cout << '\n';

    std::cout << "Give the function an argument: ";
    std::cin >> functionArgument;
    std::cout << '\n';

    switch (choice)
    {
    case 1:
        std::cout << sin(functionArgument) << '\n';
        break;
    case 2:
        std::cout << cos(functionArgument) << '\n';
        break;
    case 3:
        std::cout << tan(functionArgument) << '\n';
        break;
    case 4:
        std::cout << 1/sin(functionArgument) << '\n';
        break;
    case 5:
        std::cout << 1/cos(functionArgument) << '\n';
        break;
    case 6:
        std::cout << 1/tan(functionArgument) << '\n';
        break;
    default:
        std::cout << "Unknown choice, aborting...\n";
        break;
    }
}
