// 1CP3_Lab6_MartinMendoza.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct SSC {
	double R;
	int V;
	double k;
};

struct carbonmonoxide {
	int morning;
	int afternoon;
	int evening;
	int night;
};

int _tmain(int argc, _TCHAR* argv[])
{
	double C;
	int i;
	 srand(time(NULL));

	 SSC steadystateconc;

steadystateconc.k = (rand() % 200+100) / 1000.0;
steadystateconc.V = rand() % 20000 + 5000;
steadystateconc.R = (rand() % 25000 + 5000) / 1000.0;

cout << "Infusion Rate: " << steadystateconc.R << " mg/h" << endl;
cout << "Volume of Distribution: " << steadystateconc.V << " mL" << endl;
cout << "Elimination rate constant: " << steadystateconc.k << " per hour" << endl << endl;

C = (steadystateconc.R / (steadystateconc.V * steadystateconc.k));

cout << "The Steady State Concentration in the Plasma is: " << setprecision(3) << fixed << C << " ug/mL" << endl;






cout << "----------------------------------------------------------------------------------------------------" << endl;
cout << "Question 2" << endl;
cout << "----------------------------------------------------------------------------------------------------" << endl << endl;


ifstream inFile;
inFile.open("carbon monoxide ppm.txt");
int const DAYNUM = 31;
int mornsum = 0, aftersum = 0, evesum = 0, nightsum = 0, count = 0;
double avmorn, avafter, aveve, avnight;

carbonmonoxide ppm[DAYNUM];

cout << "Day #" << setw(20) << "Morning" << setw(20) << "Afternoon" << setw(20) << "Evening"<< setw(25) << "Night Readings"<< endl;
cout << "--------------------------------------------------------------------------------------------------------" << endl;


while (inFile) {
	for (i = 0; i < DAYNUM; i++) {
		inFile >> ppm[i].morning >> ppm[i].afternoon >> ppm[i].evening >> ppm[i].night;
		if (ppm[i].morning >= 200 || ppm[i].afternoon >=200 || ppm[i].evening >=200 || ppm[i].night >=200) {
		cout << i + 1 << setw(20) << ppm[i].morning << setw(20) << ppm[i].afternoon << setw(20) << ppm[i].evening << setw(20) << ppm[i].night << "    DANGER" << endl;

		mornsum += ppm[i].morning;
		aftersum += ppm[i].afternoon;
		evesum += ppm[i].evening;
		nightsum += ppm[i].night;

		count ++;

		} else {
			cout << i + 1 << setw(20) << ppm[i].morning << setw(20) << ppm[i].afternoon << setw(20) << ppm[i].evening << setw(20) << ppm[i].night << endl;
		}
	}
}

avmorn = static_cast<double>(mornsum) / count;
avafter = static_cast<double>(aftersum) / count;
aveve = static_cast<double>(evesum) / count;
avnight = static_cast<double>(nightsum) / count;

cout << "DANGER morning average: " << avmorn << " ppm" << endl;
cout << "DANGER afternoon average: " << avafter << " ppm" << endl;
cout << "DANGER evening average: " << aveve << " ppm" << endl;
cout << "DANGER night average: " << avnight << " ppm" << endl;



	cin.get();
	return 0;
}
