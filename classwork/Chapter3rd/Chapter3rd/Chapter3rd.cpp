#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void main()
{
    //Get values for X and Y
    std::cout << "Enter values for X and Y: ";

    double x, y;
    std::cin >> x >> y;

    //Function X Y Result
    // ----------------------------------
    
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(9) << std::left << "Function " << std::setw(7) << " X " << std::setw(7) << " Y " 
              << std::setw(12) << "Result" << std::endl;
    std::cout << std::setw(35) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    std::cout << std::setw(9) << std::left << "pow " << std::setw(7) << x << std::setw(7) << y
              << std::setw(12) << pow(x, y) << std::endl;
    std::cout << std::setw(9) << std::left  << "sqrt " << std::setw(7) << x << std::setw(7) << y
              << std::setw(12) << sqrt(x) << std::endl;

    std::cout << std::setw(9) << std::left <<  "ceil " << std::setw(7) << x << std::setw(7) << y
              << std::setw(12) << ceil(x) << std::endl;
    std::cout << std::setw(9) << std::left << "floor " << std::setw(7) << x << std::setw(7) << y
              << std::setw(12) << floor(x) << std::endl;

    std::cout << std::setw(9) << std::left << "round " << std::setw(7) << x << std::setw(7) << y
              << std::setw(12) << round(x) << std::endl;
    std::cout << std::setw(9) << std::left << "trunc " << std::setw(7) << x << std::setw(7) << y
              << std::setw(12) << trunc(x) << std::endl;
}

void ExpressionDemo()
{
    // promp user for radius of circle
    std::cout << "Enter Radius ";

    // cin is used to get input from user
    // use the input stream operator >> before the variable names
    int radius = 0;
    std::cin >> radius;

    const double Pi = 3.14159;
    

    // Area = Pi * R^2
    // double * int * int => double
    double area = Pi * radius * radius;
    std::cout << "Area = " << Pi << " * " << radius << " * " << radius << std::endl;
    std::cout << "Area = " << area << std::endl;

    //Triangle
    
    std::cout << "Enter base and height of triangle ";

    int base = 0, height = 0;
   /* std::cin >> base;
    std::cin >> height; this is the same as this next line
    */

    std::cin >> base >> height;

    // Area = 1/2 * base * height
    // (double/int) * int * int
    area = (1/2) * base * height;
    std::cout << "Area = " << area << std::endl;

    // int someValue = (1.0 / 2);

    std::cout << "Enter name ";

    std::string name;
    // instead of using std::cin >> name;
    std::cin.ignore();
    std::getline(std::cin, name); //getline is used to read strings with spaces in them
    std::cout << name << std::endl;

    // Overflow and underflow
    short smallValue = 32767;
    smallValue = smallValue + 1;

    short largeValue = -32768;
    largeValue = largeValue - 1;

    std::cout << smallValue << " " << largeValue << std::endl;

    //type coercion - compiler implicitly convers an expression's type to a larger type
    // Type casting - You explicitly convert an expression's type to another type
    // C-Style (T) expression

    int left = 10;
    int right = 3;

    double intDivision = 10 / 3; // int
    intDivision = 10.0 / 3; // double / int --> double
    intDivision = 10 / 3.0; // int / double --> double

    intDivision = left / right; // int/int--> int 
    
    intDivision = (double)left / right; // double / int --> double
    intDivision = left / (double)right; // double / int --> double

    intDivision = (double)(left / right); // int / int = int => (double)int MAKES NO SENSE TO USE.

    intDivision = static_cast<double>(left) / right; // double / int => double
    intDivision = left / static_cast<double>(right); // int / double => double

    //This is wrong and will not produce 5
    intDivision = (int)"Hello";
    // intDivision = static_cast <int>("5"); //Compiler error

    //Math functions
    // pow(x, y) => power X to the Y power = X^Y
    double result;
    result = pow(5, 3); // 5 * 5 * 5 = 125 = 5^3
    result = pow(125.0, -3.0); // cube root of 125 = 125^-3

    //sqrt(x) => square root of x

    result = sqrt(100); // 10
    result = sqrt(pow(5, 2)); // 5

    // abs(x) => absolute value of x

    result = abs(-10); // 10
    result = abs(10); //10

    // ceil(x) => Smallest possible integral value >= X
    // floor => Largest posssible integral value <= X

    result = ceil(14.5); // 15
    result = floor(3.1); // 3

    // round(x) => Rounds a float to an int using midpoint rounding
    // trunc => Truncates a float o an int

    result = round(14.5); // 15
    result = round(3.1); // 3

    result = trunc(14.5); // 14
    result = trunc(3.1); // 3
    result = int(14.5); // 14. Typcasting just truncates.

    // exp(x) => exponential E raises to X power, E = 2.17828
    // log(x) => logarithm, inverse of exponential

    result = exp(4); 
    result = log(exp(4)); // 4

    // Formatted output.

}