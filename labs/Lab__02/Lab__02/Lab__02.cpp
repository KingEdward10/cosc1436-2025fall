// Lab__02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lab2
// COSC 1436
// Edward Watts. 

#include <iostream>
#include <iomanip>


int main()
{
	int loanAmount=0;
	double interestRate=0;
	double monthlyPayment=0;
	
	
	//std::cout << "Please enter the loan amount: ";
	//std::cin >> loanAmount;
	

	while (loanAmount < 1.0 || loanAmount > 1000)
	{
		std::cout << "  Please enter a loan amount between $1 and $1000: ";
		std::cin >> loanAmount;
		

		if (loanAmount < 1 || loanAmount > 1000) 
		{
			std::cout << " Invalid entry. Please enter a loan amount between $1 and $1000: ";
		}
			
	}
	//
	  
	
	

	while (interestRate < 1.0 || interestRate > 100.0)
	{
		std::cout << " Please enter the interest rate: ";
		std::cin >> interestRate;

		if (interestRate < 1.0 || interestRate > 100.0)
		{
			std::cout << " Invalid entry. Please enter an interest rate between 1% and 100%: ";

		}

	}


	

	while (monthlyPayment < 1 || monthlyPayment > 1000)
	{
		std::cout << " Please enter your monthly payment: ";
		std::cin >> monthlyPayment;

		if (monthlyPayment < 1 || monthlyPayment > loanAmount)
		{
		std::cout << " Invalid entry. Please enter a monthly payment between $1 and full loan amount: ";
		
		}
	}
	double monthlyInterestRate = interestRate / 100 ;

	

	
	std::cout << std::fixed << std::setprecision(2);

	
	std::cout << "Loan Amount: $" << loanAmount << std::endl;

	std::cout << " " << std::endl;
	std::cout << " Month    Balance    Payment    Interest    New Balance" << std::endl;
	std::cout << " ---------------------------------------------------------" << std::endl;

	double balance = loanAmount;
	double totalPayment = 0.0;
	double totalInterest = 0.0;

	for (int month = 1; month < 12; ++month)
	{   
		double payment = 0.0;
		double interest = 0.0;
		double newBalance = balance;

		
		
		if (month == 1) 
		{

			payment = 0.0;
			interest = 0.0;
		}
		else if (balance > 0.0)
		{
			if (monthlyPayment > balance)
			{
				payment = balance;
			}
			else
			{
				payment = monthlyPayment;
			}

			newBalance -= payment;

			if (newBalance > 0.0)
			{
				interest = newBalance * monthlyInterestRate;
				newBalance += interest;
			}
			else
			{
				interest = 0.0;
				newBalance = 0.0;
			}

			totalPayment += payment;
			totalInterest += interest;
		}
		else {
			newBalance = 0.0;
			payment = 0.0;
			interest = 0.0;
		}

		std::cout << std:: setw(2) << month  << "    $"
			<< std::setw(8) << balance << "   $"
			<< std::setw(6) << payment << "   $"
			<< std::setw(7) << interest << "  $"
			<< std::setw(11) << newBalance << std::endl;
		balance = newBalance;
	}
	std::cout << " ---------------------------------------------------------" << std::endl;
	std::cout << "Total: $" 
		
		<< std::setw(17) << totalPayment  << std::setw(11) << totalInterest  << std::endl;

	//std::cout << index + 1 << std::endl;

	//if ((index + 1) % 12 == 0)
		//std::cout << std::endl;

	return 0;
}
