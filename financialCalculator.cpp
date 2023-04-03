#include <iostream>
#include <cmath>
using namespace std;

string border = "--------------------------------------------------------";
string title = "                  Financial Calculator                  ";
int selection;

double simpleInterest()
{
	double initialInvestment, time, interestRate, interest;

	cout << "Please enter your initial investment." << endl;
	cin >> initialInvestment;
	cout << "Please enter your annual interest rate (%)." << endl;
	cin >> interestRate;
	cout << "Please enter your time period (in years)." << endl;
	cin >> time;

	interest = initialInvestment * (interestRate / 100) * time;
	cout << "Your interest earned is " << interest << endl;

	return interest;
};

double compoundInterest()
{
	double initialInvestment, time, noOfTimesCompounded, interestRate, interest;

	cout << "Please enter your initial investment." << endl;
	cin >> initialInvestment;
	cout << "Please enter your annual interest rate (%)." << endl;
	cin >> interestRate;
	cout << "Please enter the number of times the interest is compounded per year." << endl;
	cin >> noOfTimesCompounded;
	cout << "Please enter your time period (in years)." << endl;
	cin >> time;

	interest = initialInvestment * (pow((1 + ((interestRate / 100) / noOfTimesCompounded)), (noOfTimesCompounded * time)));
	cout << "Your interest earned is " << interest << endl;
	return interest;
};

double presentValue()
{
	double time, discountRate, presentValue, futureValue;

	cout << "Please enter the amount of money to be received in the future." << endl;
	cin >> futureValue;
	cout << "Please enter the discount rate or the rate of return." << endl;
	cin >> discountRate;
	cout << "Please enter your time period (in years)." << endl;
	cin >> time;

	presentValue = futureValue / (pow((1 + (discountRate / 100)), time));
	cout << "Your present value is " << presentValue << endl;
	return presentValue;
};

double futureValue()
{
	double time, discountRate, presentValue, futureValue;

	cout << "Please enter the initial amount of money invested." << endl;
	cin >> presentValue;
	cout << "Please enter the discount rate or the rate of return." << endl;
	cin >> discountRate;
	cout << "Please enter your time period (in years)." << endl;
	cin >> time;

	futureValue = presentValue * (pow((1 + (discountRate / 100)), time));
	cout << "Your future value is " << futureValue << endl;
	return futureValue;
};

double ROI()
{
	double ROI, investmentCost, investmentGain;

	cout << "Please enter the gain in investment." << endl;
	cin >> investmentGain;
	cout << "Please enter the cost in investment." << endl;
	cin >> investmentCost;

	ROI = (investmentGain - investmentCost) / investmentCost;
	cout << "Your return on investment is " << (ROI * 100) << " %" << endl;
	return ROI;
};

void Welcome()
{

	bool cont, redo;
	string choice;

	do
	{
		cout << border << endl;
		cout << title << endl;
		cout << border << endl;
		cout << "Please choose what you would like to calculate!" << endl;
		cout << border << endl;
		cout << "1.Simple Interest" << endl;
		cout << "2.Compound Interest" << endl;
		cout << "3.Present Value" << endl;
		cout << "4.Future Value" << endl;
		cout << "5.Return on Investment" << endl;
		cin >> selection;

		do
		{
			switch (selection)
			{
			case 1:
				simpleInterest();
				cont = false;
				break;
			case 2:
				compoundInterest();
				cont = false;
				break;
			case 3:
				presentValue();
				cont = false;
				break;
			case 4:
				futureValue();
				cont = false;
				break;
			case 5:
				ROI();
				cont = false;
				break;
			default:
				cout << "Please choose a number between 1 and 6!" << endl;
				break;
			}

		} while (cont);
		cout << "Would you like to calculate something else!(Y/N)" << endl;
		cin >> choice;

		if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes")
		{
			Welcome();
		}
		else
		{
			redo = false;
		}
	} while (redo);
}

int main()
{
	Welcome();
	return 0;
};