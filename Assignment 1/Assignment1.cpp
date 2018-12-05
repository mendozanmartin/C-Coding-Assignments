// first_project.cpp : Defines the entry point for the console application.
// ///////////////////////////////////////////////////////////////////
// Developer: Martin Mendoza
// Student ID: 40008973
// Purpose: decisions and looping
// Functions: main( ) - main program, getsubstrateConcentration(sc), getgrowthMax(gM), getsatConst(satconst), getMaxDtest(mD);
// Authorship: I, Martin Mendoza, student number 400083973, certify that this material
// is my original work. No other person's work has been used without due acknowledgement
// and I have not made my work available to anyone else
//////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <xtgmath.h>

using namespace std;

//function prototypes
int getsubstrateConcentration (int sc);
double getgrowthMax(double gM);
double getsatConst(double satconst);
double getMaxDtest(double mD);

int _tmain(int argc, _TCHAR* argv[]){
	double growthMax, gM, satConst, satconst, maxD, MaxDtest, mD, Wc1, Wc2, TWc, centerGravity, Fmoment;
	int sc, substrateConcentration, nC, i;

	srand(time(NULL)) ;

	//get substrate concentration and making sure number is within parameters
	cout << "Please enter the initial substrate concentration (integer between 25-75 and divisible by 5) ";
	cin >> sc;
	cin.ignore();



	substrateConcentration = getsubstrateConcentration (sc);

	//get growth Max
	cout << "Please enter the maximum specific growth rate per hour (in between but not including 0.2 and 0.7) ";
	cin >> gM;
	growthMax = getgrowthMax(gM);


	//get the saturation constant
	satconst = 100; //this step is just for initializing the variable 'satconst'
	satConst = getsatConst(satconst);

	cout << "Initial substrate concentration: " << substrateConcentration << "g/L" << endl;
	cout << "Maximum specific growth rate (per hour): " << growthMax << "/hr" << endl;
	cout << "Saturation constant: " << satConst << "h/L" << endl;


	//getting maximum dilution rate (Hours per Liter)
	maxD = growthMax * (1 - sqrt(satConst/(satConst + substrateConcentration)));
	cout << "The maximum dilution rate (per hour) of the CSTR is " << fixed << setprecision(3) << maxD << "/hr" << endl;

	//test to see if maximum dilution calculations are within kinetic parameters
	MaxDtest = getMaxDtest(maxD);

	cout << endl << endl;
	cout << "Question 2" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Please enter the amount of passengers in the plane (maximum 2 persons) ";
	cin >> nC;

	while (nC != 1 && nC !=2){
		cout<< "Error: Please enter a value of 1 or 2\n";
		cout<< "Please enter the amount of passengers in the plane (maximum 2 persons): ";
		cin >> nC;
		cin.ignore();
	}

	 if (nC == 1) {
		cout << "Please input the weight (85-400lbs) of the passenger " << endl;
		cout << "Weight of passenger: ";
		cin >> Wc1;
		cin.ignore();

	while (Wc1 < 85 || Wc1 > 400) {
		cout << "Error: Please input a value that is between 85-400lbs" << endl;
		cin >> Wc1;
		cin.ignore();

	}
		TWc = Wc1;
		cout << "The total weight of passengers is " << TWc << "lbs" << endl;
		cout << "Number of passengers: " << nC << endl;
		cout << "Weight of passenger: " << Wc1 << "lbs" << endl;


	 } else if (nC == 2) {
		cout << "Please input the individual weights (in between 85-400lbs) of the passengers " << endl;

		cout << "Weight of first passenger: ";
		cin >> Wc1;

		while (Wc1 < 85 || Wc1 > 400) {
		cout << "Error: Please input a value that is between 85-400lbs" << endl;
		cin >> Wc1;
		cin.ignore();

		}

		cout << "Weight of second passenger: ";
		cin >> Wc2;
		TWc = Wc1 + Wc2;
		cout << "Total weight of passengers is " << TWc << "lbs" << endl;

		while (Wc2 < 85 || Wc2 > 400) {
		cout << "Error: Please input a value that is between 85-400lbs" << endl;
		cin >> Wc2;
		cin.ignore();
	}


		cout << "Number of passengers: " << nC << endl;
		cout << "Weight of first passenger: " << Wc1 << "lbs" << endl;
		cout << "Weight of second passenger: " << Wc2 << "lbs" << endl;
		cin.get();
	}

	//table for cargo weight and center of gravity

	 Fmoment = 1169167.3;
	 cout << setw(25) << "--------------" << setw(35) << "-------------" << endl;
	 cout << setw(25) << "Cargo Weight (lbs)" << setw(35) << "Center of Gravity (inches)" << endl;
	 cout << setw(25) << "--------------" << setw(35) << "-------------" << endl;

	 for (i = 0; i <= 5000; i += 500) {

	centerGravity = (2751405 + (120*TWc) + Fmoment + (345*i))/ (12639+TWc+i);
	if (centerGravity < 315) {
	cout << setw(25) << fixed << setprecision(1) <<  i << setw(35) << fixed << setprecision(3) << centerGravity << endl;
	}
	if (centerGravity >=315) {

			cout << setw(25) << fixed << setprecision(1) <<  i << setw(35) << fixed << setprecision(3) << centerGravity << "*" << endl;
		}


	 }

	cin.get();
	return(0);

}

//function defintions

int getsubstrateConcentration (int sc){

	if (25 <= sc && 75 >= sc && sc % 5 == 0) {
		return (sc);
	}else{
		cout << "That value is not within the parameters given" << endl;
		cin.get();
		exit(0);
	}
}
double getgrowthMax(double gM) {
	if (0.2 < gM && gM < 0.7) {

	cin.get();
	return (gM);

	}else{
	cin.get();
	cout << "That value is not within the parameters" << endl;
	cin.get();
	exit(0);

	}
}

double getsatConst(double satconst) {
	satconst = rand() % 5 + 2;
	return (satconst);
}

double getMaxDtest(double mD) {
	if (0.35 < mD && 0.45 > mD) {
	cout << "Kinetic parameters are acceptable. " ;
	return(0);
} else {
	cout << "Kinetic parameters are not acceptable. " ;
	return(0);
}
}
