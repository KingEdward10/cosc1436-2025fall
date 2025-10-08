// Chapter 4.
// COSC 1436
// EDWARD WATTS
//

#include <iostream>
#include<string> 
#include <iomanip>

 //Movie details
struct Movie
{
    std::string title;              //Required
    std::string description;        //Optional
    int runLength;                  //Required, 0
    int releaseYear;                //Optional, between 1900-2100
    /*double userRating; */             //Optional, 1.0-10.0
    std::string genres;                  // optional (comma seperated genres)
    bool isClassic;                 //Required, false
};

int main()
{




    /*std::cout << "Enter Value: ";
    int number;
    std::cin >> number;

    std::cout << "prefix (++x) = " << ++number << " , x = " << number << std::endl;
    std::cout << "prefix (--x) = " << --number << " , x = " << number << std::endl;
    std::cout << "postfix (x++) = " << number++ << " , x = " << number << std::endl;
    std::cout << "postfix (x--) = " << number-- << " , x = " << number << std::endl;*/
    bool done = false;
    do //while (!done)

    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "______________" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit movies" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;


        switch (choice)
            while (!done)
            {
            case 'A':
            case 'a': std::cout << "Add not implemented" << std::endl; done = true; break;

            case 'V':
            case 'v': std::cout << "View not implemented" << std::endl; done = true; break;

            case 'D':
            case 'd': std::cout << "Delete not implemented" << std::endl; done = true; break;

            case 'E':
            case 'e': std::cout << "Edit not implemented" << std::endl; done = true; break;

            case 'Q':
            case 'q': return 0;
            }


        Movie movie = {0};

        std::cout << "Enter movie title: ";
        std::cin.ignore();
        std::getline(std::cin, movie.title);

       /* bool isEmpty;
        isEmpty = false;*/
        while (movie.title == "");
        {


            std::cout << "Title is required" << std::endl;
            std::getline(std::cin, movie.title);
        }

        std::cout << "Enter the run length (in minutes): ";
        //runLength = -1;
        //while (runLength < 0)

        //{
        //    std::cin >> runLength;
        //    if (runLength < 0)

        //        std::cout << "ERROR: Run Length must be more than 0" << std::endl;

        //};
        std::cin >> movie.runLength;
        do
        {
            if (movie.runLength < 0)
            {

                std::cout << "error : run length must be more than 0: ";

                std::cin >> movie.runLength;
            }
            while (movie.runLength < 0);
        } 

                std::cout << " Enter the release year : ";
        std::cin >> movie.releaseYear;
        /*if (releaseYear < 1900);
        {
            std::cout << "Realease year must be at least 1900" << std::endl;
            releaseYear = 1900;
        } else if (releaseYear > 2100)
        {
            std::cout << "Release year must be between 1900 and 2100" << std::endl;
            releaseYear = 1900;

        }*/
        while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
        {

        }
        std::cout << "Enter the description : ";
        std::getline(std::cin, movie.description);
        std::cout << "Genres" << movie.genres << std::endl;
   /*
    std::cout << "Enter the movie rating (1.0-10.0) : ";
    std::cin >> userRating;
    if (userRating < 1.0 || userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;*/

     //else if (userRating > 10.0)

    //Genres
        done = false;
       // int index = 0;
        for (int index = 0; index < 5; ++index)
        {

            std::cout << "Enter the  genre (or leave blank): ";
            std::getline(std::cin, movie.genres);

            if (movie.genres == "")
                //index = 5;
                break;
            else if (movie.genres == " ")
                continue;

            movie.genres = movie.genres + ", " + movie.genres;

        //++count
        }
        {
            std::cout << "Is this a Classic (Y/N) : ";
            std::string input;
            std::cin >> input;

            // Infinite loop
           // while (true) {}
            //for(;;) {}


            while (!done)
            {
                if (_strcmpi(input.c_str(), "Y") == 0)
                {
                    movie.isClassic = true;
                    break;
                } else if (_strcmpi(input.c_str(), "N") == 0)
                {
                    movie.isClassic = false;
                    break;
                } else {


                    std::cout << "you must enter either Y or N";

                    std::cin >> input;

                }
            }
            //switch(E ^char and interagl
            //needs to be a constant which is why it is limited to char and int
            // 

            // Logical and ---> &&
            //Logical OR ----> ||
            // Logical Not ---> !
            // short-circuit eval **** important ****

                /*
                * switch-statnent   (needs a block)
                * declaring a variable (needs a block)
                *
                *
                *
                *
                *
                * x=x-1
                * x=x+1 used alot these two variable are <0>
                * prefix increment --- takes variable and increases it by one ++x
                * prefix decrement --- takes variable and decreases it by one --x
                * ___________________________________________________________________
                * postfix increment --- x++
                * postfix decrement --- x--
                *
                * cout << x++ << x;
                *         10     11
                * cout << ++x << x;
                *        12     12





                */






        }
    }
}


    // NOTES!!!!!!!!!! (useful for lab 2)
    /*
    * for ( int index=0; index; ++index)
    * cout << index++;
    * if ((index +1) %10)
    * cout << endl;
    * 
    * 
    * 
    * do
    *   "statement"
    *   while ( E);
    * 
    * DEMO NESTED LOOPS 10 x12
    *   1 2 3 4 5
    * 1 1 2 3 4 5
      2 1 2 3 4 5
      3 1 2 3 4 5

    * 
    
    
    
    
    
    */

    //for (int rows = 1; rows <= 12; ++rows)
    //{

    //    for (int cols = 0; cols < 10; ++cols)
    //    {
    //        if (cols != 0)
    //            std::cout << std::setw(4) << (rows * cols);
    //        else
    //            std::cout << cols;
    //    }

    //    std::cout << endl;

    //}










//
//void relationalDemo()
//
//{ 
//    std::cout << "Enter Two Values : ";
//
//    int left, right;
//
//    std::cin >> left >> right;
//
//    // relational operators : = > >= < <= == !=
//    // Warning 1 - Equals and Equality are similar and work in the sane situations
//    // Warning 2 - br vrtu vrtu careful of floating point comparison for equality, consdier using >= or <= unless comparing to an integer 
//    // Warning 3 - Strings compare by character value not by locale 
//    bool areEqual = left == right;
//    std::cout << "areEqual = " << std::endl;
//
//    areEqual = left == right;
//
//    std::cout << "areEqual =" << areEqual << std::endl;
//
//    //areEqual = 10 == left;
//
//    std::cout << " > " << (left > right) << std::endl;
//    std::cout << " < " << (left < right) << std::endl;
//    std::cout << " >= " << (left >= right) << std::endl;
//    std::cout << " != " << (left != right) << std::endl;
//    std::cout << " == " << (left == right) << std::endl;
//
//
//    float someValue = (10 / 3.0) * 3.0;
//    float someOtherValue = (10 * 3.0) / 3.0;
//
//    areEqual = someValue == someOtherValue;
//    std::cout << areEqual << std::endl;
//
//    // Example of Waring 3
//
//    std::string name1 = "Bob";
//    std::string name2 = "bob";
//    std::cout << (name1 == name2) << std::endl;
//    //case matters , Comparison works, but is case sensitive.
//    // to compare strings case sensitive use the strcmpi
//
//    areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;
//
//
//
//
    //
    //;
    