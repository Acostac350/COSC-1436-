/*
Lab 2
Ivan Acosta Carrasco ID# 1869290
Professor Michael Taylor
COSC-1436
Fall 2025
*/
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::cout << "Lab 2" << std::endl;
    std::cout << "Ivan Acosta Carrasco" << std::endl;
    std::cout << "Student ID #1869290" << std::endl;
    std::cout << "COSC-1436 Fall 2025" << std::endl << std::endl;

    int loanAmount;
    std::cout << "Please enter the Loan Amount: ";
    std::cin >> loanAmount;

    // Loan amount is within valid range
    while (loanAmount < 1 || loanAmount > 1000)
    {
        std::cout << "Invalid value. Please enter a numeric value between 1$ and 1,000$." << std::endl;
        std::cin >> loanAmount;
    }

    // Prompt for the interest rate
    float interestRate;
    std::cout << "Please enter the Interest rate (%): ";
    std::cin >> interestRate;

    // Ensure the interest rate is within valid range
    while (interestRate < 1.0 || interestRate > 100.0)
    {
        std::cout << "Invalid value. Interest rate must be from 1% to 100%." << std::endl;
        std::cin >> interestRate;
    }

    double payment;

    std::cout << "Enter your payment amount (Between 0 and " << loanAmount << " ): ";
    std::cin >> payment;

    while (payment < 0 || payment > loanAmount)
    {
        std::cout << "Invalid value. Please enter an amount from (0$ to " << loanAmount << "): " << std::endl;
        std::cin >> payment;
    }

    double initialBalance = static_cast<double>(loanAmount);  // to Initialize outside loop
    double totalPaid = 0.0;
    double totalInterest = 0.0;

    // Table needs adjustments
    std::cout << std::endl;
    // Output table
    std::cout << std::setw(8) << std::left << "Month:"
        << std::setw(20) << "Loan Balance:"
        << std::setw(20) << "Payment:"
        << std::setw(20) << "Interest:"
        << std::setw(20) << " New Balance:"
        << std::endl;
    std::cout << std::setw(83) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    for (int month = 1; month <= 12; ++month)
    {
        double currentPayment = 0.0;
        double monthlyInterest = 0.0;
        double endingBalance = initialBalance; 
        double afterPaymentBalance;  // Temp helper for clarity. New addition

        if (month == 1)
        {
            // First month - no payment, no interest
            currentPayment = 0.0;
            monthlyInterest = 0.0;
            endingBalance = initialBalance;
        } else if (initialBalance <= 0)
        {
            currentPayment = 0.0;
            monthlyInterest = 0.0;
            endingBalance = 0.0;
        } else
        {
            // Cap payment at remaining balance
            if (payment > initialBalance)
                currentPayment = initialBalance;
            else
                currentPayment = payment;

            afterPaymentBalance = initialBalance - currentPayment;  // Temp for readability

            // Calc monthly interest on balance after payment
            if (afterPaymentBalance <= 0) {
                monthlyInterest = 0.0;
                endingBalance = 0.0;
            } else {
                monthlyInterest = afterPaymentBalance * (interestRate / 100.0);
                endingBalance = afterPaymentBalance + monthlyInterest;
            }

            // Update totals
            totalPaid += currentPayment;
            totalInterest += monthlyInterest;
        }

        // Output need to come back and FIX
        std::cout << std::setw(8) << month
            << "$ " << std::setw(20) << std::fixed << std::setprecision(2) << initialBalance
            << "$ " << std::setw(20) << std::fixed << std::setprecision(2) << currentPayment
            << "$ " << std::setw(15) << std::fixed << std::setprecision(2) << monthlyInterest
            << "$ " << std::setw(20) << std::fixed << std::setprecision(2) << endingBalance
            << std::endl;

        // Update for next month
        initialBalance = endingBalance;
    }

    std::cout << std::setw(83) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    std::cout << "Initial Loan Amount: $" << std::fixed << std::setprecision(2) << loanAmount << std::endl;
    std::cout << "Total Interest Paid: $" << std::fixed << std::setprecision(2) << totalInterest << std::endl;
    std::cout << "Total Amount Paid: $" << std::fixed << std::setprecision(2) << totalPaid << std::endl;

    return 0;

};