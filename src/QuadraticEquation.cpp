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
	       double sqrtResult = sqrt(b*b - (discriminant));
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
    
           double realPart1 = std::real(complexSolution1);
           double imaginaryPart1 = std::imag(complexSolution1);
    
           double realPart2 = std::real(complexSolution2);
           double imaginaryPart2 = std::imag(complexSolution2);
    
           std::cout << "No real solution! \n";
           if (imaginaryPart1 > 0)
           {
                std::cout << "Solution #1: " << realPart1 << " + " << imaginaryPart1 << 'i' << '\n';
           }
           else {
                 std::cout << "Solution #1: " << realPart1 << " - " << -imaginaryPart1 << 'i' << '\n';
           }
    
           if (imaginaryPart2 > 0)
           {
                std::cout << "Solution #2: " << realPart1 << " + " << imaginaryPart2 << 'i' << '\n';
           }
           else {
                 std::cout << "Solution #2: " << realPart1 << " - " << -imaginaryPart2 << 'i' << '\n';
           }
	   }
    }while (userConfirmation());

}

