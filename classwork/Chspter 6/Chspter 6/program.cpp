// Chapter 4.
// COSC 1436
// EDWARD WATTS
//

#include <iostream>
#include<string> 
#include <iomanip>
#include "program.h"

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
/// <summary>
/// Defines possible foreground text colors.
/// </summary>
enum class ForeGroundColor
{
    Default = 39,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    LightGray = 37,
    DarkGray = 90,
    LightRed = 91,
    LightGreen = 92,
    LightYellow = 93,
    LightBlue = 94,
    LightMagenta = 95,
    LightCyan = 96,
    White = 97
};
void ResetTextColor()
{
    std::cout << "\033[0m";
}

void SetTextColor(int color)
{
    std::cout << "\033[" << color << "m";
}


/// <summary>
/// Displays an error message to the standard output.
/// </summary>
/// <param name="message">The error message to display.</param>
void DisplayError( std::string message)
{
    SetTextColor(91);
           std::cout   << "ERROR: "
            
              << message
              << std::endl;
              ResetTextColor();
}
void DisplayWarning(std::string message)
{
    SetTextColor(93);
          std::cout    << "WARNING: "
             
              << message
              << std::endl;
          ResetTextColor();
}

/// <summary>
///  <summary> view details of a movie.
/// <remarks> 
/// </summary>
void ViewMovie(Movie movie)
{
    //Movie movie;
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != " ")
        std::cout << movie.description << std::endl;
    std::cout << std::endl; 
}
/// <summary>
/// prompt user and add movie details
/// </summary>
/// <param name="done"></param>
void AddMovie()

{
    Movie movie; //= {0};

    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);


    while (movie.title == "");
    {

        DisplayError("Title is required");
        std::getline(std::cin, movie.title);
    }

    std::cout << "Enter the run length (in minutes): ";




    std::cin >> movie.runLength;
    do
    {
        if (movie.runLength < 0)
        {
            DisplayError("Run length must be more than 0");
            

            std::cin >> movie.runLength;
        }

    } while (movie.runLength < 0);

    std::cout << " Enter the release year : ";
    std::cin >> movie.releaseYear;

    while (movie.releaseYear < 1900 || movie.releaseYear > 2100);
    {
        DisplayError("Release year must be between 1900 and 2100");

        std::cin >> movie.releaseYear;
    }
    std::cout << "Enter the description : ";
    std::getline(std::cin, movie.description);
    std::cout << "Genres" << movie.genres << std::endl;

    //Genres
    bool done = false;
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

    std::cout << "Is this a Classic (Y/N) : ";
    std::string input;
    std::cin >> input;



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


            DisplayError( "you must enter either Y or N");

            std::cin >> input;

        }
    }
}
int main()
{


    // Display main menu
    bool done = false;
    do

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

        Movie movie;

        switch (choice)

        {
            case 'A':
            case 'a': AddMovie();  break;

            case 'V':
            case 'v': ViewMovie(movie); break;
            
            case 'D':
            case 'd': DisplayWarning("Delete not implemented"); done = true; break;

            case 'E':
            case 'e': DisplayWarning("Edit not implemented"); done = true; break;

            case 'Q':
            case 'q': done = true;
                DisplayError("Invalid choice");
        }
    } while (!done);


    //AddMovie(done);
   

        
      //  ViewMovie();
    }


// parameter KIND (varibale used insed the function)
// 1.) input / Pass by value
// 2.) output / Pass by reference

  











