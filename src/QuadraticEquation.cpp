#include <iostream>
#include <unistd.h>
#include <cmath>
#include <complex>

bool userConfirmation();

void quadraticEquation()
{
    do {
        double a, b, c, solution1, solution2;
        std::cout << "Quadratic equation is in the form: \n";
        std::cout << "ax^2 + bx + c \n";

        std::cout << "Give the value for a: ";
        std::cin >> a;
        std::cout << '\n';

        std::cout << "Give the value for b: ";
        std::cin >> b;
        std::cout << '\n';

        std::cout << "Give the value for c: ";
        std::cin >> c;
        std::cout << '\n';

        // Calculate the solution
        // (-b+-sqrt(b^2-4ac)/2a)

        // Calculate discriminant
        double discriminant = b*b - 4*a*c;

        // If discriminant is greater than or equal to 0, that mean
        // the equation has real solution
        if (discriminant >= 0)
        {
           double sqrtResult = sqrt(discriminant);
           solution1 = (-b + sqrtResult )/2*a;
           solution2 = (-b - sqrtResult )/2*a;
           std::cout << "Solution #1: " << solution1 << '\n';
           std::cout << "Solution #2: " << solution2 << '\n';
        }
        else 
        {
            std::complex<double> complexSolution1;
            std::complex<double> complexSolution2;
            std::complex<double> divider = 2*a;
            std::complex<double> sqrtResult = std::sqrt(std::complex<double>(discriminant));

            complexSolution1 = (-b + sqrtResult)/divider;
            complexSolution2 = (-b - sqrtResult)/divider;

            double realPart = std::real(complexSolution1);
            double imaginaryPart = std::imag(complexSolution1);

            std::cout << "No real solution! \n";
            std::cout << "Solution #1: " << realPart << " + " << imaginaryPart << 'i' << '\n';
            std::cout << "Solution #2: " << realPart << " - " << imaginaryPart << 'i' << '\n';
        }
}while (userConfirmation());

}

