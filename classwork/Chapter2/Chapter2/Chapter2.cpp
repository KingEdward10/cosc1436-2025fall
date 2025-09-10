// Chapter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
* Edward Watts
* lab #
* COSC 1436 Fall 2025
*/

#include <iostream>
#include <string>
int main()
{
    //std::cout << "Hello World\n" << " " << "Your Name" << std::endl;

    std::cout << "you are " << 20 << " years old" << std::endl;
    std::string name;
    name = "Your Name";
    std::cout << "Hello World\n" << " " << "Your Name" << name;
    
    int age;
    age = 20;
    std::cout << "you are " << age << " years old";

        int length, width;


    length = 10;
        width = 20;

        int area;
        area = length * width;

        std::cout << "Area of rectangle is" << area << std::endl;

        double pi;
        pi = 3.14159;

            char letterGrade;
        letterGrade = 'A';

        bool isPassing;
        isPassing = true;
        area = length * width;
        length = width = 100;
        length = length + 10;
        width = width - 20;
        int radius = 15;
        double result = 10 / 3;
        double remainder = 10 % 3;

        int negativeLength = -length;

        {
            int newVariable1 = 10;
            double newVariable2 = 45.7;
        };

        {
            char newVariable = 'A';
        }

        std::string studentName;
        studentName = "Bob";
        studentName = studentName + " Wilson";

        const double pi = 3.14159;

        double areaCircle = pi * ( radius * radius);

        const int numberOfLabGrades = 5;
        const int numberOfLabGrades = 4;
        
        
}
