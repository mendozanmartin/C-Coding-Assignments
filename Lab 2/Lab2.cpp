// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//question 1

	double volume, initial, increment, ending, value, average;
	const double PI = 3.141592654;
	int numbers, countNumbers = 0, sum, sum1;
	ifstream inFile;



	cout << "Please input an initial radius (m): ";
	cin >> initial;
	cin.ignore ();

	cout << "Please input an incremental value for the radius: ";
	cin >> increment;
	cin. ignore ();

	cout << "Please input an ending value for the radius: ";
	cin >> ending;
	cin. ignore();

	cout << setw(25) << "Radius" << setw(19) << "Volume" << endl;
	cout << setw(25) << "-----------" << setw(19) << "----------" << endl;
	for (initial; initial <= ending; initial+= increment) {
		volume = 4 * PI * pow(initial, 3) / 3;
		cout << setw(20) << initial << "m" << setw(20) << volume << "m" << endl;

	}
	//question 2


	cout << "Please enter a number between 0 - 200: " << endl;
	cin >> value;
	cin.ignore();

	while ( value < 0 || value > 200) {
	cout << value << " is not between 0 and 200. Please choose again. " << endl;
	cin >> value;
	cin.ignore();

	} if (value >=0 && value <=200) {
		cout << "Your number is: " << value <<  ". " << value << " is in between 0 and 200." << endl;
}

	//question 3



	inFile.open("Random.txt");

	sum1 = 0;

	if (inFile) {

	while (inFile >> numbers) {
	countNumbers++;

	sum = numbers + sum1;
	sum1 = sum;

	}

}
	average = static_cast<double> (sum) / countNumbers;

	cout << "There are " << countNumbers << " numbers in the file." << endl;
	cout << "The sum of the numbers is " << sum << endl;
	cout << "The average of the sum of the numbers is " << average << endl;


	cin.get();
	return 0;
}
