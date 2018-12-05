// Lab 1: Defines the entry point for the console application.
// ///////////////////////////////////////////////////////////////////
// Developer: Martin Mendoza
// Student ID: 400083973
// Purpose: display information, to convert degrees into radians and to create 'if' statements
// Authorship: I, Martin Mendoza, student number 400083973, certify that this material
// is my original work. No other person's work has been used without due acknowledgement
// and I have not made my work available to anyone else
//////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string First_Name; 
	char Gender;
	int number, option, Age, r;
	double result, Hourly_Wage, S, C, T, s, degrees, radians;
	double const PI = 3.14159, R = 5;


	First_Name = "Jim";
	Age = 23;
	Hourly_Wage = 11.75;
	Gender = 'M';

	// Question 1.
	cout << "First Name: " << First_Name << endl;
	cout << "Age: " << Age << endl;
	cout << "Hourly Wage: " << Hourly_Wage << "$" << endl;
	cout << "Gender: " << Gender << endl;


	//Question 2
	//converting radians into degrees

	cout << "Please input an angle (in degrees) to convert into radians ";
	cin >> degrees;
	cin.ignore();

	radians = degrees*PI/180;

	S = sin(radians);
	C = cos(radians);
	T = tan (radians);

	cout << "The angle in radians is " << radians << endl;
	cout << "The radius is " << R << "cm" << endl;
	s = radians * R;
	//arch length of circle
	cout << "The arch length of the circle is " << s << "cm" << endl;

	cout << "Sine of the radian angle... " << S << endl;
	cout << "Cosine of the radian angle... " << C << endl;
	cout << "Tangent of the radian angle... " << T << endl;


	//Question 3
	//prompt user for whole number
	cout << "Please enter a whole number ";
	cin >> number;
	cin.ignore();
	cout << "Your number is " << number << endl;



	cout << "1. Number divisible by 3? " << endl;
	cout << "2. Number between 10 and 100? " << endl;
	//prompt user to choose from a menu

	cout << "Please choose a option (1 or 2) from the menu ";

	cin >> option;
	cin.ignore();


	//if statements depending on users input
	result = number % 3;
	if (option == 1) {
		 if (result == 0)
			cout << "Your number is divisible by 3" << endl;
		 if (result != 0)
			 cout << "Your number is not divisible by 3" <<endl;
	} else if (option == 2) {
		 if (100 < number)
			cout << "Your number is greater than 100" << endl;
		 if (10 > number)
			 cout << "Your number is less than 10" << endl;
		 else if (10 <= number && number <= 100)
			 cout << "You number is in between 10 and 100" << endl;

	} else {
			cout << "That number is not part of the menu";
		}
	cin.get();
	return 0;
}
