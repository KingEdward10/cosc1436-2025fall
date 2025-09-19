// Chapter 4.
// COSC 1436
// EDWARD WATTS
//

#include <iostream>
#include<string> 


int main()
{
    //Movie details
    std::string title;              //Required
    std::string description;        //Optional
    int runLength;                  //Required, 0
    int releaseYear;                //Optional, between 1900-2100
    double userRating;              //Optional, 1.0-10.0
    bool isClassic;                 //Required, false


    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    bool isEmpty = title == "";
    if (isEmpty)
     
        std::cout << "Title is required" << std::endl;

    std::cout << "Enter the run length (in minutes): ";
    std::cin >> runLength;
    if (runLength < 0)
    {
        std::cout << "Run Length must be more than 0" << std::endl;
        runLength = 0;
    };

    std::cout << " Enter the release year : ";
    std::cin >> releaseYear;
    if (releaseYear < 1900);
    {
        std::cout << "Realease year must be at least 1900" << std::endl;
        releaseYear = 1900;
    };


        std::cout << "Enter the description : ";
        std::getline(std::cin, description);

        std::cout << "Enter the movie rating (1.0-10.0) : ";
        std::cin >> userRating;

        std::cout << "Is this a Classic (Y/N) : ";
        std::string input;
        std::cin >> input;
        if (_strcmpi(input.c_str(), "Y") == 0)
            isClassic = true;
        if (strcmpi(input.c_str(), "N") == 0)
            isClassic = false;















}

void relationalDemo()

{ 
    std::cout << "Enter Two Values : ";

    int left, right;

    std::cin >> left >> right;

    // relational operators : = > >= < <= == !=
    // Warning 1 - Equals and Equality are similar and work in the sane situations
    // Warning 2 - br vrtu vrtu careful of floating point comparison for equality, consdier using >= or <= unless comparing to an integer 
    // Warning 3 - Strings compare by character value not by locale 
    bool areEqual = left == right;
    std::cout << "areEqual = " << std::endl;

    areEqual = left == right;

    std::cout << "areEqual =" << areEqual << std::endl;

    //areEqual = 10 == left;

    std::cout << " > " << (left > right) << std::endl;
    std::cout << " < " << (left < right) << std::endl;
    std::cout << " >= " << (left >= right) << std::endl;
    std::cout << " != " << (left != right) << std::endl;
    std::cout << " == " << (left == right) << std::endl;


    float someValue = (10 / 3.0) * 3.0;
    float someOtherValue = (10 * 3.0) / 3.0;

    areEqual = someValue == someOtherValue;
    std::cout << areEqual << std::endl;

    // Example of Waring 3

    std::string name1 = "Bob";
    std::string name2 = "bob";
    std::cout << (name1 == name2) << std::endl;
    //case matters , Comparison works, but is case sensitive.
    // to compare strings case sensitive use the strcmpi

    areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;





}