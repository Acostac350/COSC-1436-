/*
Lab 3
Ivan Acosta Carrasco 1869290
COSC-1436
Fall 2025
*/

#include <iostream>
#include <string>
#include <iomanip>
struct PhysicsValue
{
    const double gravity = 9.8; // constant gravity in m/s squared
    
    const double meterToFeet = 3.28084; // convert meters to feet

    const double terminalVelocity = 90; // const for terminal velocity in m/s

};

/// <summary>Display Program Information</summary>
void DisplayInfo()
{
    std::cout << "Lab 3 "
              << std::endl
              << "Falling Distance"
              << std::endl
              << "Ivan Acosta Carrasco"
              << std::endl
              << "COSC-1436"
              << std::endl
              << "Fall 2025"
              << std::endl
              << std::endl;

}

/// <summary>Displays an error message and adds a blank line. </summary>
/// <param name="message">Details about the error.</param>
void DisplayError(std::string message)
{
    std::cout << "ERROR: Invalid entry. " << message << std::endl << std::endl;
}

/// <summary>Reads an integer input and validates against range.
/// Keeps prompting until a valid integer is within min or max value.
/// Also Handles non-numeric input by clearing error.</summary>
/// <param name="minimumValue">Minimum value allowed(integer)</param>
/// <param name="maximumValue">Maximum value allowed (integer)</param>
/// <returns>Validated integer value.</returns>
int ReadInt(int minimumValue, int maximumValue)
{
    while (true)
    {

        int value;

        if (std::cin >> value)
        {
            if (value >= minimumValue && value <= maximumValue)
                return value;

            DisplayError("Value must be within range.");
        } else
        {
            std::cin.clear(); // clear fail state. Couldn't sleep so went ahead to chapter 10 on the book
            std::cin.ignore(10000, '\n'); // ignores bad input.

            DisplayError("Please enter digits only. (No letters nor symbols.)");
        }

        std::cout << "Try again (" << minimumValue << " - " << maximumValue << "): " << std::endl;
    }
}

/// <summary>Gets the falling time in seconds, within range 1-60.
/// Uses ReadInt for input validation</summary>
/// <returns>The validated number of seconds</returns>
int GetFallingTime() 
{
    
    std::cout << "Please enter the number of seconds (1 to 60): ";
    int seconds = ReadInt(1, 60);
    std::cout << std::endl;

    return seconds;

  /*  while (seconds < 1 || seconds > 60)
    {
        DisplayError("Please enter a number between 1 and 60.");

        std::cout << "Please enter the number of seconds (1 – 60): ";
        std::cin >> seconds;
        std::cout << std::endl;
    }

    return seconds;*/
}

/// <summary> Calculates Falling Distance (meters) after seconds using d = (1/2)gt^2  </summary>
/// <param name="time">Time in seconds</param>
/// <param name="constants">Physics constants(gravity, conversions)</param>
/// <returns>Distance in meters.</returns>
double CalculateDistance(int time, PhysicsValue& constants)
{
    if (time < 0) return 0.0;
    return 0.5 * constants.gravity * time * time;
}
// ________________________  STORY 5 ____________________________

/// <summary>Gets units with a switch validation (M/m or F/f)</summary>
/// <returns>'m' or 'M' for Meters, 'f' or 'F' for Feet.</returns>
char GetUnits()
{
    char choice;
    
    while (true)
    {
        std::cout << "Do you wish to get the results in Meters or Feet? (m/f): ";
        if (std::cin >> choice)
        { 
            switch (choice)
            {
                case 'm':
                case 'M':
                case 'f':
                case 'F':
                    std::cout << std::endl;
                    return choice;

                default: DisplayError("Please enter 'm' for meters or 'f' for feet.");
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            DisplayError("Please enter 'm' for meters or 'f' for feet. (Letters only). ");
        }
    }

}
// ________________________  STORY 6 ____________________________

/// <summary>Converts meters to feet.</summary>
/// <param name="meters">Distance in meters.</param>
/// <param name="constants">Physics constants (meter to feet).</param>
/// <returns>Distance in feet.</returns>
double ConvertToFeet(double meters, PhysicsValue& constants)
{
    return meters * constants.meterToFeet;
}

/// <summary>Calculates falling velocity (m/s) as v = gt, maxed at Terminal Velocity.</summary>
/// <param name="time">Time passed in seconds (assumed >=0)</param>
/// <param name="constants">Physics constants (g and terminal velocity)</param>
/// <returns>Velocity in meters/seconds</returns>
double CalculateVelocity(int time, PhysicsValue& constants)
{
    if (time < 0) return 0;

    double velocity = constants.gravity * time;
    if (velocity > constants.terminalVelocity)
        velocity = constants.terminalVelocity;

    return velocity;
}

/// <summary>Displays a table of seconds, distance and velocity for t = 1... seconds,
/// using either meters/m/s or feet/ft/s depending on user choice.</summary>
/// <param name="seconds">max time (1 through 60)</param>
/// <param name="choice">M/m or F/f</param>
/// <param name="constants">Physics constants.</param>
void DisplayTable(int seconds, char choice, PhysicsValue& constants)
{
    std::cout << std::left
        << std::setw(14) << "Seconds"
        << std::setw(16) << "Distance"
        << std::setw(14) << "Velocity" << std::endl;
    std::cout << "==============================================" << std::endl;

    for (int time = 1; time <= seconds; time++)
    {
        double distance = CalculateDistance(time, constants);
        double velocity = CalculateVelocity(time, constants);

        if (choice == 'f' || choice == 'F')
        {
            distance = ConvertToFeet(distance, constants);
            velocity = ConvertToFeet(velocity, constants);

            std::cout << std::right
                << std::setw(4) << time
                << std::setw(14) << std::fixed << std::setprecision(2) << distance << " ft"
                << std::setw(12) << std::fixed << std::setprecision(1) << velocity << " ft/s"
                << std::endl;
        } 
        else 
        {
            std::cout << std::right
                << std::setw(4) << time
                << std::setw(14) << std::fixed << std::setprecision(2) << distance << " m"
                << std::setw(12) << std::fixed << std::setprecision(1) << velocity << " m/s"
                << std::endl;
        }
    }

    std::cout << std::endl; 
}

int main()
{
    PhysicsValue constants;
  
    DisplayInfo();
    int seconds = GetFallingTime();
    char choice = GetUnits();

    DisplayTable(seconds, choice, constants);

    return 0;

}
