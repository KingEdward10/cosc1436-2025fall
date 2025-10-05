#include <iostream>
#include <string>
#include <cmath> 
#include <iomanip>
void main()
{
    std::cout << "Enter values for x and y : ";
    // get values for x and y
    double x, y;
    std::cin >> x >> y;

    //function name x y and results

   

    std::cout << std::setw(9) << "Function " << std::setw(7) <<  "x" << std::setw(7) << "y" << std::setw(12) << "result" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << std::setw(9) << "pow " << std::setw(7)  << x << y << pow(x, y) << std::endl;
    std::cout << std::setw(9) <<  "sqrt " << std::setw(7) << x << std::setw(7) << y << sqrt(x) << std::endl;

    std::cout << std::setw(9) << "ceil " << std::setw(7) << x << std::setw(7) << y << ceil(x) << std::endl;
    std::cout << std::setw(9) <<  "floor " << std::setw(7) << x << std::setw(7) << y << floor(x) << std::endl;

    std::cout << std::setw(9) << "round " << std::setw(7) << x << std::setw(7) << y << round(x) << std::endl;
    std::cout << std::setw(9) << "trunc " << std::setw(7)  << x << std::setw(7) << y << trunc(x) << std::endl;
    k



}

void expressiondemo()
{
    std::cout << "Enter Radius: ";

    int radius = 0;
    std::cin >> radius;

    const double Pi = 3.14159;
    //double * int * int ==>
    double area = Pi * radius * radius;
    std::cout << "Area = " << Pi << "*" << radius << "*" << radius << std::endl;
    std::cout << "Area = " << area << std::endl;

    std::cout << "Enter base and height of triangle: ";
   
    int base = 0, height = 0;
    std::cin >> base;
    std::cin >> height;
    //(int/int) * int *int 
    area = (1.0 / 2) * base * height;
    std::cout << "Area = " << area << std::endl;

    std::cout << "enter name: ";

    std::string name;
    std::cin.ignore();
    std::getline(std::cin,name);
    std::cout << name << std::endl;

    short smallValue = 32767;
    short largeValue = -32768;
    largeValue = largeValue - 1;

    smallValue = smallValue + 1;
    std::cout << smallValue <<" " << largeValue << std::endl;






    int left = 10;
    int right = 3;

    double intDivision = 10 / 3; //int
    // this is a c style cast (below)

    intDivision = (double)left / right; // int / int =>
    intDivision = left / (double)right;

    //intDivision = static_cast<int>("5");
    

    //Math Functions
    // pow(x, y) --> power X to the Y power
    //sqrt(x) --> square root of x
    //abs(x) --> absolute value of x... its how you convert a negative value to a positive value 
    //
    //ceil(x) --> smallest possible integral value > x
    //floor(x) --> Largest possible intergral value < x

    // round(x) --> rounds a float to an int with midpoint rounding
    // trunc(x) --> Truncates a float to an int
    
    //exp(x) --> exponential E raises to X power, E=2.17828 
    // log (x) --> logarithm, inverse of exp
    double result;

    result = pow(5, 3); //5 * 5 * 5 = 125
    result = pow(5, -3); //cube root of 125


    result = ceil(14.5);  // 15
    result = floor(3.1); // 3

    result = round(14.5); //15

    result = trunc(14.9); // 14






}