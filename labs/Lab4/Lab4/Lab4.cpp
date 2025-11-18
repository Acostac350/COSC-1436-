/*
Ivan Acosta Carrasco
Professor Michael Taylor
Lab 4
COSC-1436
Fall 2025
*/
#include <iostream>
#include <iomanip>
#include <string>

/// <summary> Displays program information</summary>
void DisplayInfo()
{
    std::cout << "Lab 4 " << std::endl
        << "Arrays and Functions"
        << std::endl
        << "Ivan Acosta Carrasco"
        << std::endl
        << "COSC-1436"
        << std::endl
        << "Fall 2025"
        << std::endl
        << std::endl;
}

/// <summary>Displays an error message</summary>
/// <param name="message">Details about the message</param>
void DisplayError(std::string message)
{
    std::cout << "ERROR: Invalid entry. " << message << std::endl << std::endl;
}

/// <summary> Reads an integer input with validation.
/// Keeps prompting until the user enters a valid integer. </summary>
/// <returns>Validated integer value.</returns>
int ReadInt()
{
    while (true)
    {
        int value;

        if (std::cin >> value)
        {
            return value;
        } else
        {
            std::cin.clear();
            std::cin.ignore();
            DisplayError("Please enter digits only. (No letters nor symbols.)");
            std::cout << "Try again: ";
        }
    }
}

/// <summary>Prompts the user to Get initial values into the array.
/// Accepts only integers >= 0.
/// 0 Means done(not stored)
/// Negative values cause error
/// Stops when user enters 0 or Max size is reached.
/// </summary>
/// <param name="values">Arrays to insert</param>
/// <param name="maxSize">Max number of elements the array can take</param>
/// <returns></returns>
int GetInitialValues(int values[], int maxSize)
{
    int count = 0;
    bool done = false;

    while (!done && count < maxSize)
    {
        std::cout << "Enter a value: ";
        int inputValue = ReadInt();

        if (inputValue > 0)
        {
            values[count] = inputValue;
            count = count + 1;
        } else if (inputValue == 0)
        {
            done = true;
        } else
        {
            std::cout << "You must enter a value greater than or equal to 0" << std::endl;
        }
    }

    if (count == maxSize)
    {
        std::cout << "You have reached the maximum number of values (" << maxSize << ")." << std::endl;
    }

    std::cout << std::endl;
    return count;
}

/// <summary>Gets menu choice from the user.
/// Accepts uppercase or lowercase letters</summary>
/// <returns>A valid menu character.</returns>
char GetMenu()
{
    char choice;
    bool valid = false;

    while (!valid)
    {
        std::cout << "Main Menu" << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "A) Add (sum of values)" << std::endl;
        std::cout << "L) Largest value" << std::endl;
        std::cout << "S) Smallest value" << std::endl;
        std::cout << "M) Mean(Average)" << std::endl;
        std::cout << "I) Insert new values" << std::endl;
        std::cout << "V) View all values" << std::endl;
        std::cout << "Q) Quit" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 'A' || choice == 'a' ||
            choice == 'L' || choice == 'l' ||
            choice == 'S' || choice == 's' ||
            choice == 'M' || choice == 'm' ||
            choice == 'I' || choice == 'i' ||
            choice == 'V' || choice == 'v' ||
            choice == 'Q' || choice == 'q')
        {
            valid = true;
        } else
        {
            DisplayError("Invalid menu option. Please try again.");
        }
    }

    return choice;
}

/// <summary> Returns the largest value in the array.
/// Validates that count > 0.
/// </summary>
/// <param name="values">Array of values</param>
/// <param name="count">Number of valid elements in the array</param>
/// <returns>The largest value or 0 if count is invalid</returns>
int GetLargestValue(int values[], int count)
{
    if (count <= 0)
    {
        DisplayError("No values available to find the largest.");
        return 0;
    }

    int largestValue = values[0];

    for (int index = 1; index < count; index = index + 1)
    {
        if (values[index] > largestValue)
        {
            largestValue = values[index];
        }
    }

    return largestValue;
}

/// <summary>Returns the smallest value in the Array.
/// VAlidates that count > 0
/// </summary>
/// <param name="values">Array of values</param>
/// <param name="count">Number of valid elements in the array.</param>
/// <returns>The smallest value or 0 if count is invalid.</returns>
int GetSmallestValue(int values[], int count)
{
    if (count <= 0)
    {
        DisplayError("No values available to find the smallest.");
        return 0;
    }

    int smallestValue = values[0];

    for (int index = 1; index < count; index = index + 1)
    {
        if (values[index] < smallestValue)
        {
            smallestValue = values[index];
        }
    }

    return smallestValue;
}

/// <summary>
/// Returns the sum(addition) of values in the array.
/// </summary>
/// <param name="values">Array of values</param>
/// <param name="count">Number of valid elements in the array</param>
/// <returns>The sum of all values</returns>
int GetSumOfValues(int values[], int count)
{
    int sumOfValue = 0;

    for (int index = 0; index < count; index = index + 1)
    {
        sumOfValue = sumOfValue + values[index];
    }

    return sumOfValue;
}

/// <summary>
/// Returns the average of the values in the array.
/// Validates that count > 0.   
/// Display average to 4 decimal places when used.</summary>
/// <param name="values">Array of values.</param>
/// <param name="count">Number of valid elements in the array.</param>
/// <returns>The mean/Average as a double, or 0.0 if count is invalid.</returns>
double GetMeanOfValues(int values[], int count)
{
    if (count <= 0)
    {
        DisplayError("No values available to calculate the Average.");
        return 0.0;
    }

    int sumValue = GetSumOfValues(values, count);

    double averageValue = sumValue;
    averageValue = averageValue / count;

    return averageValue;
}

/// <summary> Displays the values in the array. 10 per line.</summary>
/// <param name="values">Array of values</param>
/// <param name="count">Number of valid elements in the array.</param>
void DisplayValues(int values[], int count)
{
    if (count <= 0)
    {
        std::cout << "No values in the array to display." << std::endl << std::endl;
        return;
    }

    std::cout << "Array values: " << std::endl;

    for (int index = 0; index < count; index = index + 1)
    {
        std::cout << std::setw(6) << values[index] << "    ";

        if ((index + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
}

/// <summary>
/// Allows user to insert new values into existing array.
/// Does not eliminate existing values.
///</summary>
/// <param name="values">Array of values.</param>
/// <param name="maxSize">Maximum allowed size.</param>
/// <param name="currentCount">Current number of valid elements</param>
/// <returns>The new count of valid elements.</returns>
int InsertNewValues(int values[], int maxSize, int currentCount)
{
    if (currentCount >= maxSize)
    {
        std::cout << "The array is already full. Cannot insert more values." << std::endl << std::endl;
        return currentCount;
    }

    bool done = false;
    int count = currentCount;

    std::cout << "Insert new values. Enter 0 when you are done." << std::endl;

    while (!done && count < maxSize)
    {
        std::cout << "Enter a value: ";
        int inputValue = ReadInt();

        if (inputValue > 0)
        {
            values[count] = inputValue;
            count = count + 1;
        } else if (inputValue == 0)
        {
            done = true;
        } else
        {
            std::cout << "You must enter a value greater than or equal to 0" << std::endl;
        }
    }

    if (count == maxSize)
    {
        std::cout << "You have reached the maximum number of values (" << maxSize << ")." << std::endl;
    }

    std::cout << std::endl;
    return count;
}

int main()
{
    DisplayInfo();

    const int MAX_VALUES = 100;
    int values[MAX_VALUES];
    int valueCount = 0;

    // Story 2: initial input
    valueCount = GetInitialValues(values, MAX_VALUES);

    bool quit = false;

    // Story 3–9: main menu loop
    while (!quit)
    {
        char choice = GetMenu();

        if (choice == 'Q' || choice == 'q')
        {
            quit = true;
        } else if (choice == 'L' || choice == 'l')
        {
            // Story 4: largest
            if (valueCount > 0)
            {
                int largest = GetLargestValue(values, valueCount);
                std::cout << "The Largest value is = " << largest << std::endl << std::endl;
            } else
            {
                DisplayError("No values available. Please insert values first.");
            }
        } else if (choice == 'S' || choice == 's')
        {
            // Story 5: Smallest
            if (valueCount > 0)
            {
                int smallest = GetSmallestValue(values, valueCount);
                std::cout << "The Smallest value is = " << smallest << std::endl << std::endl;
            } else
            {
                DisplayError("No values available. Please insert values first.");
            }
        } else if (choice == 'A' || choice == 'a')
        {
            // Story 6: Sum = addition
            if (valueCount > 0)
            {
                int sum = GetSumOfValues(values, valueCount);
                std::cout << "The Sum of values is = " << sum << std::endl << std::endl;
            } else
            {
                DisplayError("No values available. Please insert values first.");
            }
        } else if (choice == 'M' || choice == 'm')
        {
            // Story 7: Mean = Average
            if (valueCount > 0)
            {
                double mean = GetMeanOfValues(values, valueCount);
                std::cout << std::fixed << std::setprecision(4);
                std::cout << "The average is = " << mean << std::endl << std::endl;
                std::cout.unsetf(std::ios::fixed);
                std::cout << std::setprecision(6);
            } else
            {
                DisplayError("No values available. Please insert values first.");
            }
        } else if (choice == 'V' || choice == 'v')
        {
            // Story 8: View
            DisplayValues(values, valueCount);
        } else if (choice == 'I' || choice == 'i')
        {
            // Story 9: Insert
            valueCount = InsertNewValues(values, MAX_VALUES, valueCount);
        }
    }

    std::cout << "Adios!" << std::endl;
    return 0;
}