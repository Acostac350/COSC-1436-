/*
Lab 5 - Trip Planner
Ivan Acosta Carrasco
COSC-1436
Fall 2025
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>

struct Stop
{
    int xCoordinate;
    int yCoordinate;
};

/// <summary>Displays general error message with provided details.</summary>
/// <param name="message">Details about the error.</param>
void DisplayError(const std::string& message)
{
    std::cout << "ERROR: " << message << std::endl << std::endl;
}

/// <summary>Displays program information.</summary>
void DisplayInfo()
{
    std::cout << "Lab 5" << std::endl;
    std::cout << "Trip Planner" << std::endl;
    std::cout << "Ivan Acosta Carrasco" << std::endl;
    std::cout << "COSC-1436 - Fall 2025" << std::endl << std::endl;
}

/// <summary>Reads an integer from the user and validates input.</summary>
/// <param name="message">Message to display.</param>
/// <returns>Validated integer value.</returns>
int ReadInt(const std::string& message)
{
    int value;

    while (true)
    {
        std::cout << message;

        if (std::cin >> value)
        {
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        DisplayError("Please enter a valid whole number.");
    }
}

/// <summary>Reads an integer within a specified range.</summary>
/// <param name="message">message to display.</param>
/// <param name="minValue">Minimum allowed value.</param>
/// <param name="maxValue">Maximum allowed value.</param>
/// <returns>Validated integer in range.</returns>
int ReadIntInRange(const std::string& message, int minValue, int maxValue)
{
    int value = ReadInt(message);

    while (value < minValue || value > maxValue)
    {
        DisplayError("Value must be between " + std::to_string(minValue) +
                     " and " + std::to_string(maxValue) + ".");
        value = ReadInt(message);
    }

    return value;
}

/// <summary>Reads a single character from the user.</summary>
/// <param name="message">Message to display.</param>
/// <returns>Character entered by the user.</returns>
char ReadChar(const std::string& message)
{
    char value;

    while (true)
    {
        std::cout << message;

        if (std::cin >> value)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        DisplayError("Please enter a single character.");
    }
}

/// <summary>Reads a Yes/No answer from the user (Y/N). Case insensitive. </summary>
/// <param name="message">Message to display.</param>
/// <returns>True if user enters Y, false if user enters N.</returns>
bool ReadYesNo(const std::string& message)
{
    while (true)
    {
        char answer = ReadChar(message);
        answer = static_cast<char>(std::toupper(static_cast<unsigned char>(answer)));

        if (answer == 'Y')
        {
            return true;
        } else if (answer == 'N')
        {
            return false;
        }

        DisplayError("Please enter Y or N.");
    }
}

/// <summary>Initializes the trip array to nullptr.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
void InitializeTrip(Stop* trip[], int maxStops)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    for (int index = 0; index < maxStops; ++index)
    {
        trip[index] = nullptr;
    }
}

/// <summary>Counts the number of stops currently in the trip.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
/// <returns>Number of non null stops.</returns>
int CountStops(Stop* trip[], int maxStops)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return 0;
    }

    int count = 0;

    for (int index = 0; index < maxStops; ++index)
    {
        if (trip[index] != nullptr)
        {
            ++count;
        }
    }

    return count;
}

/// <summary>Adds a stop as the last stop in the trip.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
/// <param name="stopToAdd">Stop pointer to add.</param>
/// <returns>True if added, false if trip is full or parameters invalid.</returns>
bool AppendStop(Stop* trip[], int maxStops, Stop* stopToAdd)
{
    if (trip == nullptr || maxStops <= 0 || stopToAdd == nullptr)
    {
        return false;
    }

    for (int index = 0; index < maxStops; ++index)
    {
        if (trip[index] == nullptr)
        {
            trip[index] = stopToAdd;
            return true;
        }
    }

    return false;
}

/// <summary>Returns the stop pointer given a one-based stop number.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
/// <param name="stopNumber">Stop number (1-based).</param>
/// <returns>Pointer to Stop, or nullptr if not found.</returns>
Stop* GetStopByNumber(Stop* trip[], int maxStops, int stopNumber)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return nullptr;
    }

    if (stopNumber < 1 || stopNumber > maxStops)
    {
        return nullptr;
    }

    int index = stopNumber - 1;

    return trip[index];
}

/// <summary>Removes a stop from the trip and compacts the array.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
/// <param name="stopToRemove">Stop pointer to remove.</param>
/// <returns>True if removed, false if not found or parameters invalid.</returns>
bool RemoveStop(Stop* trip[], int maxStops, Stop* stopToRemove)
{
    if (trip == nullptr || maxStops <= 0 || stopToRemove == nullptr)
    {
        return false;
    }

    int removeIndex = -1;

    for (int index = 0; index < maxStops; ++index)
    {
        if (trip[index] == stopToRemove)
        {
            removeIndex = index;
            break;
        }
    }

    if (removeIndex == -1)
    {
        return false;
    }

    delete trip[removeIndex];

    //move elements down
    for (int index = removeIndex; index < maxStops - 1; ++index)
    {
        trip[index] = trip[index + 1];
    }

    trip[maxStops - 1] = nullptr;

    return true;
}

/// <summary>Clears all stops from the trip and deletes memory.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
void ClearTrip(Stop* trip[], int maxStops)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    for (int index = 0; index < maxStops; ++index)
    {
        if (trip[index] != nullptr)
        {
            delete trip[index];
            trip[index] = nullptr;
        }
    }
}

/// <summary>Reads the user speed (1-60 mph).</summary>
/// <returns>Speed in miles per hour.</returns>
int ReadSpeed()
{
    const int MIN_SPEED = 1;
    const int MAX_SPEED = 60;

    std::cout << "Before planning your trip, please enter your travel speed." << std::endl;
    int speed = ReadIntInRange("Speed (1-60 mph): ", MIN_SPEED, MAX_SPEED);
    std::cout << std::endl;

    return speed;
}

/// <summary>Calculates distance between two points.</summary>
/// <param name="firstStop">First stop.</param>
/// <param name="secondStop">Second stop.</param>
/// <returns>Distance as a double.</returns>
double CalculateDistance(const Stop& firstStop, const Stop& secondStop)
{
    double deltaX = static_cast<double>(secondStop.xCoordinate - firstStop.xCoordinate);
    double deltaY = static_cast<double>(secondStop.yCoordinate - firstStop.yCoordinate);

    double sumSquares = deltaX * deltaX + deltaY * deltaY;

    return std::sqrt(sumSquares);
}

/// <summary>Handles the menu option to add a stop.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
void AddStop(Stop* trip[], int maxStops)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    std::cout << "Add a new stop to your trip." << std::endl;

    int xCoordinateInput = ReadIntInRange("Enter X coordinate (-100 to 100): ", -100, 100);
    int yCoordinateInput = ReadIntInRange("Enter Y coordinate (-100 to 100): ", -100, 100);

    Stop* newStop = new Stop;
    newStop->xCoordinate = xCoordinateInput;
    newStop->yCoordinate = yCoordinateInput;

    bool added = AppendStop(trip, maxStops, newStop);

    if (!added)
    {
        DisplayError("The trip is full. Cannot add another stop.");
        delete newStop;
    } else
    {
        std::cout << "Stop added to the trip." << std::endl << std::endl;
    }
}

/// <summary>Handles the menu option to view the trip and travel time.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
/// <param name="speed">Speed in miles per hour.</param>
void GetViewTrip(Stop* trip[], int maxStops, int speed)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    int stopCount = CountStops(trip, maxStops);

    if (stopCount == 0)
    {
        std::cout << "There are no stops in the trip." << std::endl << std::endl;
        return;
    }

    std::cout << "Stop            Location    Distance (miles)      Time (minutes)" << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;

    Stop previousLocation;
    previousLocation.xCoordinate = 0;
    previousLocation.yCoordinate = 0;

    double totalDistance = 0.0;
    double totalMinutes = 0.0;
    int stopNumber = 0;

    for (int index = 0; index < maxStops; ++index)
    {
        if (trip[index] != nullptr)
        {
            ++stopNumber;

            double distance = CalculateDistance(previousLocation, *trip[index]);

            // Exact minutes as double
            double exactMinutes = (distance * 60.0) / static_cast<double>(speed);

            // Trunc to whole minutes
            int minutesWhole = static_cast<int>(exactMinutes);

            //Round up
            if (exactMinutes > static_cast<double>(minutesWhole))
            {
                ++minutesWhole;
            }

            double minutes = static_cast<double>(minutesWhole);

            totalDistance += distance;
            totalMinutes += minutes;

            std::cout << std::setw(4) << stopNumber
                << std::setw(15) << " "
                << "(" << trip[index]->xCoordinate << ", " << trip[index]->yCoordinate << ")";

            std::cout << std::setw(15) << std::fixed << std::setprecision(2) << distance;
            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << minutes << std::endl;

            previousLocation = *trip[index];
        }
    }

    std::cout << "---------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(4) << "Stops: " << stopCount
        << std::setw(26) << " "
        << std::setw(9) << std::fixed << std::setprecision(2) << totalDistance
        << std::setw(20) << std::fixed << std::setprecision(2) << totalMinutes
        << std::endl << std::endl;
}

/// <summary>Handles the menu option to delete a stop.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
void DeleteStop(Stop* trip[], int maxStops)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    int stopCount = CountStops(trip, maxStops);
    if (stopCount == 0)
    {
        std::cout << "There are no stops to delete." << std::endl << std::endl;
        return;
    }

    int stopNumber = ReadIntInRange(
        "Enter the stop number you wish to delete (1-" + std::to_string(stopCount) + "): ",
        1, stopCount);

    Stop* stop = GetStopByNumber(trip, maxStops, stopNumber);

    if (stop == nullptr)
    {
        DisplayError("Error. Stop not found.");
        return;
    }

    bool removed = RemoveStop(trip, maxStops, stop);

    if (removed)
    {
        std::cout << "Stop " << stopNumber << " has been removed from the trip." << std::endl << std::endl;
    } else
    {
        DisplayError("Unable to remove stop.");
    }
}

/// <summary>Handles the menu option to clear the trip.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
void ClearTripMenu(Stop* trip[], int maxStops)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    bool confirm = ReadYesNo("Are you sure you want to clear the trip? (Y/N): ");

    if (confirm)
    {
        ClearTrip(trip, maxStops);
        std::cout << "All stops have been removed from the trip." << std::endl << std::endl;
    } else
    {
        std::cout << "Trip was not cleared." << std::endl << std::endl;
    }
}

/// <summary>Displays the main menu.</summary>
void DisplayMenu()
{
    std::cout << "Main Menu" << std::endl;
    std::cout << "A) Add a stop" << std::endl;
    std::cout << "V) View trip" << std::endl;
    std::cout << "D) Delete a stop" << std::endl;
    std::cout << "C) Clear trip" << std::endl;
    std::cout << "Q) Quit" << std::endl << std::endl;
}

/// <summary>Handles the quit option (asks for confirmation).</summary>
/// <returns>True if user confirms quitting.</returns>
bool QuitOption()
{
    bool confirm = ReadYesNo("Are you sure you want to quit? (Y/N): ");

    if (confirm)
    {
        std::cout << "Exiting program..." << std::endl << std::endl;
        return true;
    }

    std::cout << "Returning to main menu." << std::endl << std::endl;
    return false;
}

/// <summary>Runs the main menu loop until the user quits.</summary>
/// <param name="trip">Array of stop pointers.</param>
/// <param name="maxStops">Maximum number of stops.</param>
/// <param name="speed">Travel speed in mph.</param>
void GetMenu(Stop* trip[], int maxStops, int speed)
{
    if (trip == nullptr || maxStops <= 0)
    {
        return;
    }

    bool shouldQuit = false;

    while (!shouldQuit)
    {
        DisplayMenu();

        char choice = ReadChar("Please select an option: ");
        choice = static_cast<char>(std::toupper(static_cast<unsigned char>(choice)));

        if (choice == 'A')
        {
            AddStop(trip, maxStops);
        } else if (choice == 'V')
        {
            GetViewTrip(trip, maxStops, speed);
        } else if (choice == 'D')
        {
            DeleteStop(trip, maxStops);
        } else if (choice == 'C')
        {
            ClearTripMenu(trip, maxStops);
        } else if (choice == 'Q')
        {
            shouldQuit = QuitOption();
        } else
        {
            DisplayError("Unknown menu option.");
        }
    }
}

int main()
{
    const int MAX_STOPS = 100;
    Stop* trip[MAX_STOPS];

    DisplayInfo();

    InitializeTrip(trip, MAX_STOPS);

    int speed = ReadSpeed();

    GetMenu(trip, MAX_STOPS, speed);

    ClearTrip(trip, MAX_STOPS);

    return 0;
}
