#include <iostream>
#include <iomanip>

// Constants
const double GRAVITY = 9.8;        // Acceleration due to gravity 
const double METERS_TO_FEET = 3.28084;  // Conversion factor from meters to feet

/// Function to calculate falling distance 
double fallingDistance(double time) {
    return 0.5 * GRAVITY * time * time;
}

/// Function to calculate velocity 
double velocity(double time) {
    return GRAVITY * time;
}

int main() {
    int seconds;
    char unit;

    std::cout << "Please enter the number of seconds? ";
    std::cin >> seconds;

    if (seconds <= 0) {
        std::cout << "Number of seconds must be positive!" << std::endl;
        return 1;
    }

    std::cout << "Do you want the results in meters or feet? (m/f): ";
    std::cin >> unit;

    bool inFeet = (unit == 'f' || unit == 'F');

    
    std::string distanceUnit = inFeet ? "ft" : "m";

    std::string velocityUnit = inFeet ? "ft/s" : "m/s";

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "\nSeconds      Distance      Velocity\n";
    std::cout << "=================================\n";

    for (int t = 1; t <= seconds; ++t) {
        double d = fallingDistance(t);
        double v = velocity(t);

        // Convert to feet if needed
        if (inFeet) {
            d *= METERS_TO_FEET;
            v *= METERS_TO_FEET;
        }

        std::cout << std::setw(3) << t

            << std::setw(15) << d << " " << distanceUnit
            << std::setw(10) << v << " " << velocityUnit
            << std::endl;
    }

    return 0;
}