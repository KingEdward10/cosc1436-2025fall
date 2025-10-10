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

/// <summary>
///  <summary> view details of a movie.
/// <remarks> 
/// </summary>
void ViewMovie()
{
    Movie movie;
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != " ")
        std::cout << movie.description << std::endl;
    std::cout << std::endl; 
}
int main()
{



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


        switch (choice)

        {
            case 'A':
            case 'a': std::cout << "Add not implemented" << std::endl; done = true; break;

            case 'V':
            case 'v': std::cout << "View not implemented" << std::endl; done = true; break;
            {
                ViewMovie()
                    done = true
                    break;
            
            }
            case 'D':
            case 'd': std::cout << "Delete not implemented" << std::endl; done = true; break;

            case 'E':
            case 'e': std::cout << "Edit not implemented" << std::endl; done = true; break;

            case 'Q':
            case 'q': return 0;
        }
    } while (!done);


        Movie movie = {0};

        std::cout << "Enter movie title: ";
        std::cin.ignore();
        std::getline(std::cin, movie.title);


        while (movie.title == "");
        {


            std::cout << "Title is required" << std::endl;
            std::getline(std::cin, movie.title);
        }

        std::cout << "Enter the run length (in minutes): ";




        std::cin >> movie.runLength;
        do
        {
            if (movie.runLength < 0)
            {

                std::cout << "error : run length must be more than 0: ";

                std::cin >> movie.runLength;
            }

        } while (movie.runLength < 0);

        std::cout << " Enter the release year : ";
        std::cin >> movie.releaseYear;

        while (movie.releaseYear < 1900 || movie.releaseYear > 2100);
        {

        }
        std::cout << "Enter the description : ";
        std::getline(std::cin, movie.description);
        std::cout << "Genres" << movie.genres << std::endl;
   
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


                    std::cout << "you must enter either Y or N";

                    std::cin >> input;

                }
            }
   

        
        ViewMovie();
    }




  











