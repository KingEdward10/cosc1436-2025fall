/*
    Lab 5
    Edward Watts
    Course: COSC
    Semester: Fall 2025

*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cmath>
#include <string>


struct Stop
{
    int x;
    int y;
};



void displayProgramInfo();

int  readIntInRange(const std::string& prompt, int minValue, int maxValue);
char readYesNo(const std::string& prompt);
char getMainMenuChoice();

void initializeTripArray(Stop* trip[], int tripSize);

int  getStopCount(Stop* trip[], int tripSize);
bool addStopToTrip(Stop* trip[], int tripSize, Stop* newStop);

void handleAddStopOption(Stop* trip[], int tripSize);
void handleViewTripOption(Stop* trip[], int tripSize, int speedMph);
void handleRemoveStopOption(Stop* trip[], int tripSize);
void handleClearTripOption(Stop* trip[], int tripSize);

Stop* getStopByNumber(Stop* trip[], int tripSize, int stopNumber);
void   removeStopAtIndex(Stop* trip[], int tripSize, int index);
void   clearTrip(Stop* trip[], int tripSize);

int    getUserSpeed();
double calculateDistance(const Stop& a, const Stop& b);
bool   confirmQuit();


void displayProgramInfo()
{
    
    std::cout << "           Lab 5 - Trip Planner\n";
   
}



int readIntInRange(const std::string& prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            if (value < minValue || value > maxValue)
            {
                std::cout << "Value must be between " << minValue
                    << " and " << maxValue << ".\n";
            } else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
        } else
        {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


char readYesNo(const std::string& prompt)
{
    char ch;

    while (true)
    {
        std::cout << prompt;
        std::cin >> ch;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));

        if (ch == 'Y' || ch == 'N')
        {
            return ch;
        }

        std::cout << "Invalid input. Please enter Y or N.\n";
    }
}


char getMainMenuChoice()
{
    char choice;

    while (true)
    {
        std::cout << "Main Menu\n";
        std::cout << "------------------------\n";
        std::cout << "A) Add a stop\n";
        std::cout << "V) View trip\n";
        std::cout << "R) Remove a stop\n";
        std::cout << "C) Clear trip\n";
        std::cout << "Q) Quit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        choice = static_cast<char>(std::toupper(static_cast<unsigned char>(choice)));

        if (choice == 'A' || choice == 'V' || choice == 'R' ||
            choice == 'C' || choice == 'Q')
        {
            std::cout << "\n";
            return choice;
        }

        std::cout << "Invalid option. Please try again.\n\n";
    }
}


void initializeTripArray(Stop* trip[], int tripSize)
{
    for (int i = 0; i < tripSize; ++i)
    {
        trip[i] = nullptr;
    }
}


int getStopCount(Stop* trip[], int tripSize)
{
    int count = 0;
    for (int i = 0; i < tripSize; ++i)
    {
        if (trip[i] != nullptr)
        {
            ++count;
        } else
        {
            break; 
        }
    }
    return count;
}


bool addStopToTrip(Stop* trip[], int tripSize, Stop* newStop)
{
    for (int i = 0; i < tripSize; ++i)
    {
        if (trip[i] == nullptr)
        {
            trip[i] = newStop;
            return true;
        }
    }
    return false; // no room
}


void handleAddStopOption(Stop* trip[], int tripSize)
{
    int currentCount = getStopCount(trip, tripSize);
    if (currentCount >= tripSize)
    {
        std::cout << "Trip is full. Cannot add more stops.\n\n";
        return;
    }

    int x = readIntInRange("Enter X coordinate (-100 to 100): ", -100, 100);
    int y = readIntInRange("Enter Y coordinate (-100 to 100): ", -100, 100);

    Stop* newStop = new Stop;
    newStop->x = x;
    newStop->y = y;

    if (!addStopToTrip(trip, tripSize, newStop))
    {
        std::cout << "Trip is full. Stop could not be added.\n\n";
        delete newStop; // avoid leak
    } else
    {
        std::cout << "Stop added to the trip.\n\n";
    }
}


double calculateDistance(const Stop& a, const Stop& b)
{
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    return std::sqrt(static_cast<double>(dx * dx + dy * dy));
}


void handleViewTripOption(Stop* trip[], int tripSize, int speedMph)
{
    int count = getStopCount(trip, tripSize);

    if (count == 0)
    {
        std::cout << "No stops in the trip.\n\n";
        return;
    }

    std::cout << "Stop   "
        << "Location       "
        << "Distance (miles)   "
        << "Time (minutes)\n";
    std::cout << "-----------------------------------------------------------\n";

    
    Stop previous;
    previous.x = 0;
    previous.y = 0;

    double totalDistance = 0.0;
    double totalMinutes = 0.0;

    for (int i = 0; i < count; ++i)
    {
        Stop* current = trip[i];
        double distance = calculateDistance(previous, *current);
        double timeHours = distance / static_cast<double>(speedMph);
        double timeMinutes = timeHours * 60.0;

        // Round UP to whole minutes
        double timeMinutesRounded = std::ceil(timeMinutes);

        totalDistance += distance;
        totalMinutes += timeMinutesRounded;

        std::cout << std::setw(4) << (i + 1) << "   ";
        std::cout << " (" << std::setw(3) << current->x << ","
            << std::setw(3) << current->y << ")      ";
        std::cout << std::fixed << std::setprecision(2)
            << std::setw(10) << distance << "           "
            << std::setw(8) << timeMinutesRounded << "\n";

        previous = *current;
    }

    std::cout << "-----------------------------------------------------------\n";
    std::cout << std::setw(4) << count << "   ";
    std::cout << "                 ";
    std::cout << std::fixed << std::setprecision(2)
        << std::setw(10) << totalDistance << "           "
        << std::setw(8) << totalMinutes << "\n\n";
}

Stop* getStopByNumber(Stop* trip[], int tripSize, int stopNumber)
{
    int index = stopNumber - 1;
    if (index < 0 || index >= tripSize)
    {
        return nullptr;
    }
    return trip[index];
}


void removeStopAtIndex(Stop* trip[], int tripSize, int index)
{
    if (index < 0 || index >= tripSize)
    {
        return;
    }
    if (trip[index] == nullptr)
    {
        return;
    }

   
    delete trip[index];

   
    for (int i = index; i < tripSize - 1; ++i)
    {
        trip[i] = trip[i + 1];
    }

    // Set last element to null
    trip[tripSize - 1] = nullptr;
}


void handleRemoveStopOption(Stop* trip[], int tripSize)
{
    int count = getStopCount(trip, tripSize);

    if (count == 0)
    {
        std::cout << "No stops to remove.\n\n";
        return;
    }

    int stopNumber = readIntInRange("Enter stop number to remove (1 - "
                                    + std::to_string(count) + "): ",
                                    1, count);

    int index = stopNumber - 1;
    if (trip[index] == nullptr)
    {
        std::cout << "Stop not found.\n\n";
        return;
    }

    removeStopAtIndex(trip, tripSize, index);
    std::cout << "Stop " << stopNumber << " removed from the trip.\n\n";
}


void clearTrip(Stop* trip[], int tripSize)
{
    for (int i = 0; i < tripSize; ++i)
    {
        if (trip[i] != nullptr)
        {
            delete trip[i];
            trip[i] = nullptr;
        }
    }
}


void handleClearTripOption(Stop* trip[], int tripSize)
{
    char response = readYesNo("Are you sure you want to clear the trip? (Y/N): ");
    if (response == 'Y')
    {
        clearTrip(trip, tripSize);
        std::cout << "Trip cleared.\n\n";
    } else
    {
        std::cout << "Trip not cleared.\n\n";
    }
}


int getUserSpeed()
{
    int speed = readIntInRange("Enter your travel speed (1-60 mph): ", 1, 60);
    std::cout << "\n";
    return speed;
}


bool confirmQuit()
{
    char response = readYesNo("Are you sure you want to quit? (Y/N): ");
    return (response == 'Y');
}


int main()
{
    const int MAX_STOPS = 100;
    Stop* trip[MAX_STOPS];

    displayProgramInfo();

    initializeTripArray(trip, MAX_STOPS);
    int speedMph = getUserSpeed();

    bool done = false;

    while (!done)
    {
        char choice = getMainMenuChoice();

        switch (choice)
        {
            case 'A':
                handleAddStopOption(trip, MAX_STOPS);
                break;

            case 'V':
                handleViewTripOption(trip, MAX_STOPS, speedMph);
                break;

            case 'R':
                handleRemoveStopOption(trip, MAX_STOPS);
                break;

            case 'C':
                handleClearTripOption(trip, MAX_STOPS);
                break;

            case 'Q':
                if (confirmQuit())
                {
                    done = true;
                    std::cout << "Exiting program. Goodbye!\n";
                } else
                {
                    std::cout << "Quit canceled.\n\n";
                }
                break;
        }
    }

    // Ensure memory is cleaned up before exit
    clearTrip(trip, MAX_STOPS);

    return 0;
}
