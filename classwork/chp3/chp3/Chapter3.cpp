#include <iostream>
#include <string>

void main()
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
}