/*
    Lab 4
    Edward Watts
    Semester: Fall 2025

  
*/

#include <iostream>
#include <iomanip>  
#include <limits>
#include <cctype>
#include <string>


void displayProgramInfo()
{
    std::cout << "=============================================\n";
    std::cout << "           Lab 4 - Array Statistics\n";
    std::cout << "           Edward Watts \n";
    std::cout << "           COSC1436 \n";
    std::cout << "           Semester: Fall 2025\n";
    std::cout << "=============================================\n\n";
}


int getValidatedInt(const std::string& prompt)
{
    int value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}


int readInitialValues(int numbers[], int maxSize)
{
    int count = 0;

    std::cout << "Enter non-negative integer values (0 to stop):\n";

    while (count < maxSize)
    {
        int value = getValidatedInt("Enter a value: ");

        if (value == 0)
        {
            break;
        } else if (value < 0)
        {
            std::cout << "You must enter a value >= 0.\n";
        } else
        {
            numbers[count] = value;
            count++;
        }
    }

    if (count == maxSize)
    {
        std::cout << "Array is full (" << maxSize << " values).\n";
    }

    std::cout << "\n";
    return count;
}


char displayMainMenuAndGetChoice()
{
    char choice;

    while (true)
    {
        std::cout << "Main Menu\n";
        std::cout << "------------------------\n";
        std::cout << "L) Largest value\n";
        std::cout << "S) Smallest value\n";
        std::cout << "U) Sum of values\n";
        std::cout << "M) Mean (average)\n";
        std::cout << "V) View values\n";
        std::cout << "I) Insert additional values\n";
        std::cout << "Q) Quit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        choice = static_cast<char>(std::toupper(static_cast<unsigned char>(choice)));

        if (choice == 'L' || choice == 'S' || choice == 'U' ||
            choice == 'M' || choice == 'V' || choice == 'I' || choice == 'Q')
        {
            std::cout << "\n";
            return choice;
        } else
        {
            std::cout << "Invalid option. Try again.\n\n";
        }
    }
}


int findLargest(const int numbers[], int count)
{
    int largest = numbers[0];

    for (int i = 1; i < count; ++i)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }
    return largest;
}


int findSmallest(const int numbers[], int count)
{
    int smallest = numbers[0];

    for (int i = 1; i < count; ++i)
    {
        if (numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
    }
    return smallest;
}

int sumValues(const int numbers[], int count)
{
    int sum = 0;

    for (int i = 0; i < count; ++i)
    {
        sum += numbers[i];
    }

    return sum;
}


double meanValues(const int numbers[], int count)
{
    int sum = sumValues(numbers, count);
    return static_cast<double>(sum) / static_cast<double>(count);
}


void displayValues(const int numbers[], int count)
{
    if (count == 0)
    {
        std::cout << "No values entered.\n\n";
        return;
    }

    std::cout << "Array values:\n";

    for (int i = 0; i < count; ++i)
    {
        std::cout << std::setw(6) << numbers[i];
        if ((i + 1) % 10 == 0)
        {
            std::cout << "\n";
        }
    }

    std::cout << "\n\n";
}



int insertValues(int numbers[], int count, int maxSize)
{
    if (count >= maxSize)
    {
        std::cout << "Array is full. Cannot insert.\n\n";
        return count;
    }

    std::cout << "Insert non-negative values (0 to stop):\n";

    while (count < maxSize)
    {
        int value = getValidatedInt("Enter a value: ");

        if (value == 0)
        {
            break;
        } else if (value < 0)
        {
            std::cout << "Value must be >= 0.\n";
        } else
        {
            numbers[count] = value;
            count++;
        }
    }

    std::cout << "\n";
    return count;
}


int main()
{
    const int MAX_VALUES = 100;
    int numbers[MAX_VALUES];
    int count = 0;

    displayProgramInfo();


    count = readInitialValues(numbers, MAX_VALUES);

    bool done = false;

    while (!done)
    {
        char choice = displayMainMenuAndGetChoice();

        switch (choice)
        {
            case 'L':
                if (count == 0)
                    std::cout << "Array is empty.\n\n";
                else
                    std::cout << "Largest = " << findLargest(numbers, count) << "\n\n";
                break;

            case 'S':
                if (count == 0)
                    std::cout << "Array is empty.\n\n";
                else
                    std::cout << "Smallest = " << findSmallest(numbers, count) << "\n\n";
                break;

            case 'U':
                if (count == 0)
                    std::cout << "Array is empty.\n\n";
                else
                    std::cout << "Sum = " << sumValues(numbers, count) << "\n\n";
                break;

            case 'M':
                if (count == 0)
                {
                    std::cout << "Array is empty.\n\n";
                } else
                {
                    std::cout << std::fixed << std::setprecision(4);
                    std::cout << "Mean = " << meanValues(numbers, count) << "\n\n";
                    std::cout.unsetf(std::ios::fixed);
                    std::cout << std::setprecision(6);
                }
                break;

            case 'V':
                displayValues(numbers, count);
                break;

            case 'I':
                count = insertValues(numbers, count, MAX_VALUES);
                break;

            case 'Q':
                done = true;
                std::cout << "Exiting program. Goodbye!\n";
                break;
        }
    }

    return 0;
}
