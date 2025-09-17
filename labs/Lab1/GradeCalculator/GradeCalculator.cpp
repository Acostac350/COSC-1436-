/*
* Ivan Acosta Carrasco ID #1869290
* Lab#1
* Professor Michael Taylor
* COSC-1436 Fall 2025
*/

#include <iostream>
#include <string>
int main()
{
    std::cout << "Lab 1" << std::endl; std::cout << "Ivan Acosta Carrasco #1869290" << std::endl; std::cout << "COSC 1436 Fall 2025" << std::endl;
    std::cout << "\n";
    
    // Used \n because I wanted a space between my credentials and the project

    std::string firstName, surName;
    std::cout << "Please enter your name: "; std::cin >> firstName;
    std::getline(std::cin, surName);
    double lab1, lab2, lab3, lab4;
    
    std::cout << "Enter Lab 1: "; std::cin >> lab1;
    std::cout << "Enter Lab 2: "; std::cin >> lab2;
    std::cout << "Enter Lab 3: "; std::cin >> lab3;
    std::cout << "Enter Lab 4: "; std::cin >> lab4;

    double exam1, exam2, exam3;

    std::cout << "Enter Exam 1: "; std::cin >> exam1;
    std::cout << "Enter Exam 2: "; std::cin >> exam2;
    std::cout << "Enter Exam 3: "; std::cin >> exam3;
    double labAverage = (lab1 + lab2 + lab3 + lab4) / 4;
    
    double participation, finalExam;
   
    std::cout << "Enter Participation Grade: "; std::cin >> participation;
    std::cout << "Enter Final Exam Grade: "; std::cin >> finalExam;
    std::cout << "\n";
    // used \n because I don't know another way to break lines besides endl and \n - Also reads better
    double examAverage = (exam1 + exam2 + exam3) / 3;
   
    double classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);
    std::cout << "\n";
    std::cout << firstName << surName << ", Your Lab grades are:  " << std::endl; std::cout << "Lab 1 = " << lab1 << std::endl;
    std::cout << "Lab 2 = " << lab2 << std::endl; std::cout << "Lab 3 = " << lab3 << std::endl; 
    std::cout << "Lab 4 = " << lab4 << std::endl; 
    // std::cout << "\n";
    
    std::cout << "Your Lab Average is = " << labAverage << std::endl;
    std::cout << "\n";
    
    std::cout << firstName << surName << ", Your Exam grades are: ";
    std::cout << "\n";
    std::cout << "Exam 1 = " << exam1 << std::endl; std::cout << "Exam 2 = " << exam2 << std::endl;
    std::cout << "Exam 3 = " << exam3 << std::endl; 
    std::cout << "Your Exam Average is = " << examAverage << "\n";
   
    std::cout << firstName << surName << ", Your class grade is listed as followed: " << "\n" << std::endl;
    
    std::cout << "Lab Average (65%) = " << labAverage << " %" << std::endl;
    std::cout << "Exam Average (20%) = " << examAverage << " %" << std::endl;
    std::cout << "Participation (5%) = " << participation << " %" << std::endl;
    std::cout << "Final Exam is (10%) = " << finalExam << " %" << std::endl;
    std::cout << "Class Average = " << classAverage << " %" << std::endl;

    return 0;
  
}


