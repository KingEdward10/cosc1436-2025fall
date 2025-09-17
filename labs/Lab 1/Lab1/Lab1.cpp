// Lab 1: Grade Calculator
// Name: Edward Watts
// COSC 1436 Fall 2025
//

#include <iostream>
#include <string>
#include <iomanip>
int main()
{
    std::cout << "Please enter your name: ";
	std::string name;
	std::getline(std::cin, name);	
	std::cout << name << std::endl;

	// Labs
	std::cout << "Please enter lab 1: ";

	double lab1 = 0;
	std::cin >> lab1;	

	std::cout << " Please enter lab 2: ";
	double lab2 = 0;
	std::cin >> lab2;

	std::cout << " Please enter lab 3: ";
	double lab3 = 0;	
	std::cin >> lab3;

	std::cout << " Please enter lab 4: ";
	double lab4 = 0;
	std::cin >> lab4;

	// Exams
	std::cout << "Please enter exam 1: ";	
	double exam1 = 0;
	std::cin >> exam1;

	std::cout << "Please enter exam 2: ";
	double exam2 = 0;
	std::cin >> exam2;

	std::cout << "Please enter exam 3: ";
	double exam3 = 0;	
	std::cin >> exam3;

	// Other Grades
	std::cout << "Please enter partcipation: ";
	double participation = 0;
	std::cin >> participation;

	std::cout << "Please enter final exam: ";
	double finalExam = 0;
	std::cin >> finalExam;
	std::cout << std::endl;

	// Results
	std::cout << name << ", your lab grades are : " << '\n';
	std::cout << std::endl;

		std::cout << "Lab 1: " << lab1 << '\n';
		std::cout << "Lab 2: " << lab2 << '\n';
		std::cout << "Lab 3: " << lab3 << '\n';
		std::cout << "Lab 4: " << lab4 << std::endl;
		std::cout << std::endl;

	std::cout << name << ", your exam grades are : " << '\n';
	std::cout << std::endl;

		std::cout << "Exam 1: " << exam1 << '\n';
		std::cout << "Exam 2: " << exam2 << '\n';
		std::cout << "Exam 3: " << exam3 << std::endl;

		std::cout << std::endl;	

		std::cout << name << ", your other grades are : " << '\n';
		std::cout << std::endl;

		std::cout << "Participation: " << participation << '\n';
		std::cout << "Final Exam: " << finalExam << std::endl;

		std::cout << std::endl;

		std::cout << name << ", your class grades are : " << '\n';
		std::cout << std::endl;
		double labAverage = (lab1 + lab2 + lab3 + lab4) / 4;
		double examAverage = (exam1 + exam2 + exam3) / 3;
		double finalGrade = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);

		std::cout << std::fixed << std::setprecision(2) << "Lab Average (65%): " << labAverage << '\n';
		std::cout << "Exam Average (20%): " << examAverage << '\n';
		std::cout << "Participation (5%): " << participation << '\n';
		std::cout << "Final Exam (10%): " << finalExam << std::endl;
		std::cout << std::endl;
		
		std::cout << "Class Average: " << finalGrade << std::endl;
		std::cout << std::endl;

		std::cout << "Congradulations!";
		std::cout << std::endl;
		







	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
