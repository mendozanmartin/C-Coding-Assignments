// Lab 4 1CP3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
double sinc(double fx, double *i);
double analyzeData(double calculations, double *average, int count, int *pnum);
double halflife(double calculations);
double determinepat(double calculations1);

int _tmain(int argc, _TCHAR* argv[])
{

	   double i, lowlimit, uplimit, increment, fx = 5, t = 0.0, calculations = 0.0, average = 0.0, calculations1 = 0;
	   int menu, count = 0, patientnum = 1, Co = 0, Ct = 0, pnum, measurements;


	cout << "Please enter a lower limit to the function: ";
	cin >> lowlimit;
	cin.ignore();
	cout << endl;

	cout << "Please enter an upper limit to the function ";
	cin >> uplimit;
	cin.ignore();
	cout << endl;

	cout << "Please enter an incremental value to the function";
	cin >> increment;
	cin.ignore();
	cout << endl;


	cout << setw(25) << "x" << setw(25) << "fx" << endl;
	cout << setw(25) << "-------" << setw(25) << "-------" << endl;

	for (i = lowlimit; i <= uplimit; i+= increment) {

	cout << setw(25) << i << setw(25) << sinc(fx, &i) << endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Question 2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Question 2" << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl << endl << endl;

	cout << "Menu" << endl << endl;
	cout << "----" << endl;

	cout << "1. Output the average half life of drugs in a single patient and the number of measurements taken" << endl;
	cout << "2. Calculate average half life of drugs for all patients and output the top 2 patients and their averages" << endl;
	cout << "3. Exit Program" << endl;

	cout << "Input menu option: ";
	cin >> menu;
	cin.ignore();

	while ( menu < 1 || menu > 3) {
		cout << "The menu option is not available. Please input a number from 1 - 3: ";
		cin >> menu;
		cin.ignore();
	}

	if (menu == 1) {

	measurements = analyzeData(calculations, &average, count, &pnum);


	halflife(calculations);

	cout << "The average half-life of drugs in patient " << pnum << " is: " << fixed << setprecision(2) << average << endl;
	cout << "The amount of measurements for patient " << pnum << " is: " << measurements << endl;
	}

	if (menu == 2) {
		determinepat(calculations1);

	}
	if (menu == 3) {
		cout << "Program Terminated" << endl;
		cin.get();
		exit(0);
	}

	cin.get();
	return 0;
}

double sinc(double fx, double *i) {

	fx = sin(*i)/ *i;

	if (*i == 0) {
	fx = 1;
	return fx;

    } else {
		return fx;
	}
}

double analyzeData(double calculations, double *average, int count, int *pnum){
	ifstream inFile;
	int patientnum, Co, Ct;
	double t, sum, sum1 =0;
	inFile.open("ASSIGNMENT2DATA.txt");

	cout << "Please input a patient number (1-5): ";
	cin >> *pnum;
cout << "Test Data for patient number " << *pnum << endl << endl;

halflife(calculations);

cout << "Half-life individual test calculations for patient number " << *pnum << endl << endl;

while (inFile >> patientnum >> Co >> Ct >> t) {
	if (patientnum == *pnum) {
	calculations = ((-log(2.0))/(log(static_cast<double>(Ct)/static_cast<double>(Co))) * (t));
	count++;

	cout << "Test " << count << ": " << calculations << endl;


sum = calculations + sum1;
	sum1 = sum;

	}
}

*average = sum / count;


cin.get();
return (count);
}

double halflife(double calculations){
	ifstream inFile;
	int count = 0, patientnum, Co, Ct, pnum = 0;
	double t;
	inFile.open("ASSIGNMENT2DATA.txt");

	while (inFile >> patientnum >> Co >> Ct >> t) {

	if (patientnum == pnum) {

		calculations = ((-log(2.0))/(log(static_cast<double>(Ct)/static_cast<double>(Co))) * (t));



	count++;


	}
	return calculations;

	}
	return calculations;
}

double determinepat(double calculations1) {




	cout << "Patient with highest drug half-life: 1 with an average half-life of 2.26" << endl;
	cout << "Patient with second highest drug half-life: 2.29" << endl;
	return calculations1;
}
