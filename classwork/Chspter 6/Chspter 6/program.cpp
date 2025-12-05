/*
 * Chapter 6 - 7
 * COSC 1436
 */
#include <iostream>
#include <string>
#include <iomanip>

//Movie details
struct Movie
{
    std::string title;          //Required
    std::string description;    //Optional
    int runLength;              //Required, 0
    int releaseYear;            //Optional, but between 1900-2100
    bool isClassic;             //Required, false
    std::string genres;         //Optional (comma separated list of genres)
};
// ARRAY- list ofvalues of same typle
// ELEMENT- singular value in an array
//DO NOT DO THIS!!!
//int g_thisIsAGlobalVariable = 100;

/// <summary>Defines possible foreground colors.</summary>
enum class ForegroundColor {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Cyan = 36,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightCyan = 96
};

//Function prototypes
//Forward declarations/referencing
void DisplayError(std::string);

void ResetTextColor()
{
    std::cout << "\033[0m";
}

void SetTextColor(ForegroundColor color)
{
    std::cout << "\033[" << (int)color << "m";
}

/// <summary>Display a confirmation message.</summary>
/// <param name="message">Message to show.</param>
/// <returns>Returns true or false depending on whether confirmed or not.</returns>
bool Confirm(std::string message)
{
    std::cout << message << " (Y/N) ";
    std::string input;
    std::cin >> input;

    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
            return true;
        else if (_strcmpi(input.c_str(), "N") == 0)
            return false;
        else {
            DisplayError("You must enter either Y or N");

            std::cin >> input;
        }
    }
}

/// <summary>Displays an error message.</summary>
/// <param name="message">Message to display.</param>
void DisplayError(std::string message)
{
    //std::cout << "\033[91m" 
    SetTextColor(ForegroundColor::BrightRed);
    std::cout << "ERROR: " << message << std::endl;
    ResetTextColor();
}

/// <summary>Displays a warning message.</summary>
/// <param name="message">Message to display.</param>
void DisplayWarning(std::string message)
{
    SetTextColor(ForegroundColor::BrightYellow);
    std::cout << message << std::endl;
    ResetTextColor();
}

int ReadInt(int minimumValue, int maximumValue)
{
    do
    {
        int value;
        std::cin >> value;

        if (value >= minimumValue && value <= maximumValue)
            return value;

        DisplayError("Value is outside range");
    } while (true);
}

int ReadInt(int minimumValue)
{
    return ReadInt(minimumValue, INT_MAX);
}

std::string ReadString(std::string message, bool isRequired)
{
    std::cout << message;

    std::string input;
    std::getline(std::cin, input);

    while (isRequired && input == "")
    {
        DisplayError("Value is required");

        std::getline(std::cin, input);
    }

    return input;
}

/// <summary>View details of a movie.</summary>
/// <remarks>
/// More details including paragraphs of data if you want.
/// </remarks>
void ViewMovie(Movie movie)
{
    if (movie.title == "")
    {
        DisplayWarning("No movies exist");
        return;
    }

    // View movie
    //    Title (Year)
    //    Run Length # min
    //    User Rating = ##
    //    Is Classic? 
    //    [Description]
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
}

/// <summary>Prompt user and add movie details.</summary>
Movie AddMovie()
{
    Movie movie;// = {0};

    //Get movie details
    movie.title = ReadString("Enter movie title: ", true);

    std::cout << "Enter the run length (in minutes): ";
    movie.runLength = ReadInt(0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;
    movie.releaseYear = ReadInt(1900, 2100);

    movie.description = ReadString("Enter the optional description: ", false);

    // Genres, up to 5
    for (int index = 0; index < 5; ++index)
    {
        std::string genre = ReadString("Enter the genre (or blank to continue): ", false);
        if (genre == "")
            break;
        else if (genre == " ")
            continue;

        movie.genres = movie.genres + ", " + genre;
    }

    movie.isClassic = Confirm("Is this a classic movie?");

    return movie;
}


void ViewMovies(Movie movies[], int size)
{
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "")
        // Replace this line in ViewMovies:
        if (movies[index].title == "")

        // With this corrected line:
        if (movies[index].title == "")
            return;

        ViewMovie(movies[index]);

    }
}

void DeleteMovie()
{
    Movie movie;

    if (!Confirm("Are you sure you want to delete " + movie.title + "?"))
        return;

    //TODO: Delete movie
    //DisplayWarning("Not implemented yet");
    movie.title = "";
}

void EditMovie()
{
    DisplayWarning("Not implemented yet");
}

int AddToMovieArray(Movie movies[], int size, Movie movie)
{
    for (int index = 0; index < size; ++index)
    {
        if (movies [index]. title == "")
        {
            movies[index] = movie;
            return index;
        }

        DisplayError("Movie array is full");
        return -1;


    }
}

//Test function overloading
void Display(int value)
{
    std::cout << "int" << std::endl;
}

void Display(double value)
{
    std::cout << "double" << std::endl;
}

void Display(float value)
{
    std::cout << "float" << std::endl;
}

void Display(int value1, double value2)
{
    std::cout << "int, double" << std::endl;
}
void Display(short, int)
{
    std::cout << "short, int" << std::endl;
}
//
//void TestFunctionOverloading()
//{
//    Display(10);
//    Display(4.56);
//    Display((short)34);
//    Display(10, 4.56F);
//    Display(10000L, 4.56);
//
//    Display('c', 4.56f);
//
//    Display((short)5, (short)10);
//
//   // Display("hello", 4.56);
//}
void ArrayDemo()
{
    const int MaxNumbers = 100;

    //Init array using { 0 }
    int numbers[MaxNumbers] = {0};
    //int numbers[100];        

    //# of days in each month
    //int daysInMonth[12] = { 0 };
    //Approach 1 - correct but not readable
    /*daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7]
                   = daysInMonth[9] = daysInMonth[11] = 31;
    daysInMonth[1] = 28;
    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;*/

    //Approach 2 - init expression
    // Zero init - each element is set to 0// { 0 }
    // Full init - each element is assigned a value
    // Partial init - each element is assigned a value and remaining elements are 0 initialized    
    //int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Implicit array sizing
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Set each element to its element number (element 1 = 1, element 2 = 2, etc)
    //Approach 1 for small arrays only
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;

    //Approach 2 for any array
    int rangeIndex = 0;
    for (int& number: numbers)
        number = ++rangeIndex;
       

    for (int number:numbers)
        std::cout << number << std::endl;

    //Prefix/postfix and arrays
    // ++x := x = x + 1; ret x
    // x++ := temp = x; x = x + 1; ret temp
    int outIndex = 0;
    std::cout << ++numbers[outIndex] << std::endl; //Modifies  element print 2
    std::cout << numbers[++outIndex] << std::endl;// element prints 2
    std::cout << numbers[outIndex++] << std::endl;// index prints 2
    std::cout << numbers[outIndex]++ << std::endl;// Modifies index 2



    //int numbers2[MaxNumbers] = numbers;
    int nuumbers3[MaxNumbers] = {0};
    // cant use comparisons with arrays
    // for loop is the only way to see if arrays are equal
    // cant cout an array or cin

}
#pragma endregion

int main()
{


    // sixe is required at declaration for arrays and the size must be greater than 0 and it must be a constant integer expression must be a constant
    //Leaving this here to not break anything in the code
    //Display main menu
    const int MaximumMovies = 100;
   // Movie movie;
    Movie movies[MaximumMovies]; //array of movies (array can be of any type )

    bool done = false;
    do
    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;

        switch (choice)
        {
            case 'A':
            case 'a': AddToMovieArray(movies, MaximumMovies, AddMovie()); break;

            case 'V':
            case 'v': ViewMovies(movies, MaximumMovies); break;

            case 'D':
            case 'd': DeleteMovie(); break;

            case 'E':
            case 'e': EditMovie(); break;

            case 'Q':
            case 'q': done = true;

            default: DisplayError("Invalid choice"); break;
        };
    } while (!done);

    //std::cin.ignore();
    // Function call ::= func () 
    //ViewMovie();    
}
























//// Chapter 4.
//// COSC 1436
//// EDWARD WATTS
////
//
//#include <iostream>
//#include<string> 
//#include <iomanip>
//#include "program.h"
//// Paramter kinds:
//// 1.) Input / Pass by value
//// 2.) Output / Pass by reference
//// 3.) Input/Output / Pass by reference
//
// //Movie details
//struct Movie
//{
//    std::string title;              //Required
//    std::string description;        //Optional
//    int runLength {};                  //Required, 0
//    int releaseYear {};                //Optional, between 1900-2100
//    /*double userRating; */             //Optional, 1.0-10.0
//    std::string genres;                  // optional (comma seperated genres)
//    bool isClassic {};                 //Required, false
//};
///// <summary>
///// Defines possible foreground text colors.
///// </summary>
//enum class ForeGroundColor
//{
//    Default = 39,
//    Black = 30,
//    Red = 31,
//    Green = 32,
//    Yellow = 33,
//    Blue = 34,
//    Magenta = 35,
//    Cyan = 36,
//    LightGray = 37,
//    DarkGray = 90,
//    LightRed = 91,
//    LightGreen = 92,
//    LightYellow = 93,
//    LightBlue = 94,
//    LightMagenta = 95,
//    LightCyan = 96,
//    White = 97
//};
//void ResetTextColor()
//{
//    std::cout << "\033[0m";
//}
//
//void SetTextColor(int color)
//{
//    std::cout << "\033[" << color << "m";
//}
//
//
///// <summary>
///// Displays an error message to the standard output.
///// </summary>
///// <param name="message">The error message to display.</param>
//void DisplayError( std::string message)
//{
//    SetTextColor(91);
//           std::cout   << "ERROR: "
//            
//              << message
//              << std::endl;
//              ResetTextColor();
//}
//void DisplayWarning(std::string message)
//{
//    SetTextColor(93);
//          std::cout    << "WARNING: "
//             
//              << message
//              << std::endl;
//          ResetTextColor();
//}
//bool Confirm (std::string message)
//{
//    std::cout << message << " (Y/N): ";
//    std::string input;
//    std::cin >> input;
//    while (true)
//    {
//        if (_strcmpi(input.c_str(), "Y") == 0)
//        {
//            return true;
//        }
//        else if (_strcmpi(input.c_str(), "N") == 0)
//        {
//            return false;
//        }
//        else
//        {
//            DisplayError("You must enter either Y or N");
//            std::cin >> input;
//        }
//    }
//}
//
//int ReadInt(int minimumValue, int maximumValue)
//{
//    do {
//        int value;
//        std::cin >> value;
//        if (value >= minimumValue && value <= maximumValue)
//            return value;
//            
//        DisplayError(" Value is out of range");
//    } while (true);
//    //
//}
//
//int ReadInt(int minimumValue)
//{
//    return ReadInt(minimumValue, INT_MAX);
//}
///// <summary>
/////  <summary> view details of a movie.
///// <remarks> 
///// </summary>
//void ViewMovie(Movie movie)
//{
//    if (movie.title == "")
//    {
//        DisplayWarning("No movie exist");
//        return;
//    }
//    //Movie movie;
//    std::cout << std::fixed << std::setprecision(1) << std::endl;
//    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
//    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
//    std::cout << "Genres " << movie.genres << std::endl;
//    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
//    if (movie.description != " ")
//        std::cout << movie.description << std::endl;
//    std::cout << std::endl; 
//}
//
//std::string ReadString(std::string message, bool isRequired)
//{
//    std::cout << message;
//
//    std::string input;
//    std::getline(std::cin, input);
//
//    while (isRequired && input == "")
//    {
//        DisplayError("Value is required");
//
//        std::getline(std::cin, input);
//    }
//
//    return input;
//}
///// <summary>
///// prompt user and add movie details
///// </summary>
///// <param name="done"></param>
//Movie AddMovie()
//
//{
//    Movie movie;// = {0};
//
//    //Get movie details
//    movie.title = ReadString("Enter movie title: ", true);
//    movie.releaseYear = ReadInt(1900, 2100);
//    std::cout << "Enter the run length (in minutes): ";
//    movie.runLength = ReadInt(0);
//
//   
//
//    std::cout << "Enter the run length (in minutes): ";
//
//
//
//
//    
//    do
//    {
//        std::cin >> movie.runLength;
//        if (movie.runLength < 0)
//            DisplayError("Run length must be more than 0");
//            
//
//            
//        
//
//    } while (movie.runLength < 0);
//
//    std::cout << " Enter the release year : ";
//    std::cin >> movie.releaseYear;
//
//    while (movie.releaseYear < 1900 || movie.releaseYear > 2100);
//    {
//        DisplayError("Release year must be between 1900 and 2100");
//
//        std::cin >> movie.releaseYear;
//    }
//    movie.description = ReadString("Enter the optional description: ", false);
//
//    //Genres
//   // bool done = false;
//    // int index = 0;
//    for (int index = 0; index < 5; ++index)
//    {
//        std::string genre;
//
//        std::cout << "Enter the  genre (or leave blank): ";
//        std::getline(std::cin, movie.genres);
//
//        if (movie.genres == "")
//            //index = 5;
//            break;
//        else if (movie.genres == " ")
//            continue;
//
//        movie.genres = movie.genres + ", " + movie.genres;
//
//        //++count
//    }
//
//
//    movie.isClassic = Confirm("Is this a Classic? : ");
//
//    return movie;
//}
//
//void DeleteMovie(Movie& movie)
//{
//    if (!Confirm("Are you sure you want to delete " + movie.title + "?"))
//        return;
//
//    //TODO: Delete movie
//    //DisplayWarning("Not implemented yet");
//    movie.title = "";
//}
//
//void EditMovie(Movie& movie)
//{}
//
////test function overloading 
//
//void Display(double value)
//{
//std::cout << "double" << std::endl;
//}
//
//void Display(int value)
//{
//    std::cout << "int" << std::endl;
//}
//
//void Display(float value)
//{
//    std::cout << "float" << std::endl;
//
//
//
//}
//void Display(int value1, double value2)
//{
//    std::cout << "int, double" << std::endl;
//
//}
//
//void TestFunctionOverloading()
//{
//    Display(10);
//   
//}
//int main()
//{
//
//
//    // Display main menu
//
//
//
//    Movie movie;
//
//    bool done = false;
//    do
//
//    {
//        std::cout << "Movie Library" << std::endl;
//        std::cout << "______________" << std::endl;
//        std::cout << "A)dd Movie" << std::endl;
//        std::cout << "V)iew Movies" << std::endl;
//        std::cout << "E)dit movies" << std::endl;
//        std::cout << "D)elete Movie" << std::endl;
//        std::cout << "Q)uit" << std::endl;
//
//        char choice;
//        std::cin >> choice;
//
//       
//
//        switch (choice)
//
//        {
//            case 'A':
//            case 'a': AddMovie();  break;
//
//            case 'V':
//            case 'v': ViewMovie(movie); break;
//
//            case 'D':
//            case 'd': DisplayWarning("Delete not implemented"); done = true; break;
//
//            case 'E':
//            case 'e': DisplayWarning("Edit not implemented"); done = true; break;
//
//            case 'Q':
//            case 'q': done = true;
//
//            default:  DisplayError("Invalid choice");
//        };
//    } while (!done);
//
//
//    //AddMovie(done);
//   
//
//        
//      //  ViewMovie();
//    }
//
//
//// parameter KIND (varibale used insed the function)
//// 1.) input / Pass by value
//// 2.) output / Pass by reference
//// call stack very important
//  
//
//
//
//
//
//






