#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unistd.h>

void quadraticEquation();
void cubicEquation();
void trigonometry();
void shapeCalculator();
void solidCalculator();
void series();
bool userConfirmation();

int main()
{
    bool exit = false;
    system("clear");
    do
    {
        int featureChoice;
        std::cout << "Available features: \n";
        std::cout << "1. Geometric figure calculator.\n";
        std::cout << "2. Solid figure calculator.\n";
        std::cout << "3. Quadratic equation solver.\n";
        std::cout << "4. Cubic equation solver (coming soon!).\n";
        std::cout << "5. Trigonometry.\n";
        std::cout << "6. Series and Sum.\n";
        std::cout << "Your choice (0 to exit): ";
        std::cin >> featureChoice;
        std::cout << '\n';
        system("clear");

        switch(featureChoice)
        {
            case 1:
                shapeCalculator();
                system("clear");
                break;
            case 2:
                solidCalculator();
                system("clear");
                break;
            case 3:
                quadraticEquation();
                system("clear");
                break;
            case 4:
                std::cout << "Coming Soon!\n";
                system("clear");
                break;
            case 5:
                trigonometry();
                system("clear");
                break;
            case 6:
                series();
                system("clear");
                break;
            case 0:
                exit = true;
                break;
            default:
                std::cout << "Unknown choice!\n";
                std::cout << "Aborting...!\n";
                sleep(3);
                system("clear");
        }
    } while (!exit);

    return 0;
}

void cubicEquation()
{
    double a, b, c, d, part1, part2, part3, solution;
    std::cout << "Cubic equation is in the form: \n";
    std::cout << "ax^3 + bx^2 + cx + d\n";

    // std::cout << "Give the value for a: ";
    // std::cin >> a;
    // std::cout << '\n';

    // std::cout << "Give the value for b: ";
    // std::cin >> b;
    // std::cout << '\n';

    // std::cout << "Give the value for c: ";
    // std::cin >> c;
    // std::cout << '\n';

    // std::cout << "Give the value for d: ";
    // std::cin >> d;
    // std::cout << '\n';

    // a = 1;
    // b = 2;
    // c = -9;
    // d = -18;

    // a = 1;
    // b = 0;
    // c = 0;
    // d = -8;

//    a = 1;
//    b = -5;
//    c = -3;
//    d = 15;
//
//    double commonPart1 = -(b*b*b)/27*a*a*a + (b*c)/6*a*a - d/2*a;
//    double commonPart2 = (c/3*a)-((b*b)/9*a*a);
//
//    double radicand = pow(commonPart1, 2) + pow(commonPart2, 3);
//    if (radicand >= 0)
//    {
//
//    }
//    double rootResult = 0;
//
//    std::complex<double> innerSqrt = sqrt(radicand);
//    if (real(innerSqrt)) rootResult += real(innerSqrt);
//    else if (imag(innerSqrt)) rootResult += imag(innerSqrt);
//
//    part1 = cbrt(commonPart1 + rootResult);
//    part2 = cbrt(commonPart1 - rootResult);
//    part3 = b/3*a;
//
//    solution = part1 + part2 - part3;
//
//    std::cout << "The solution is: " << solution << '\n';
}

bool userConfirmation()
{
    char confirmation = 'y';
    std::cout << "Go back to main menu? (y/n) ";
    std::cin >> confirmation;

    if (confirmation == 'y')
    {
        system("clear");
        return false;    
    }
    else if (confirmation == 'n')
    {
        system("clear");
        return true;
    }
    else 
    {
        std::cout << "Unknown option, returning to main menu...";
        sleep(3);
        system("clear");
        return false;
    }

}
