// 1CP3_Lab7_MartinMendoza.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	ifstream COreadings;
	ofstream toxicCO;

	int CO, toxic = 0, i = 0, j = 0;


	COreadings.open("COreadings.txt");
	toxicCO.open("toxicCO.txt");

	while (!COreadings.eof()) {
		COreadings >> CO;
		i++;


	if (CO > 35) {
		toxic = CO;
		toxicCO << toxic << endl;
		j++;
		}
	}
	toxicCO.close();

	cout << "The number of readings CO readings are: " << i++ << endl;
	cout << "The number of toxic CO readings are: " << j++ << endl;


	////////Question 2///////////
	////////////////////////////////////

	cout << "Question 2" << endl;
	cout << "-------------------------------------- " << endl << endl;

	ofstream plates;
	plates.open("plates.txt", ios::app);


	int c = 0, a;
	char platenum[8], zero[2] = {'0', '/0'};

	cout << "Please input a license plate number with 7 characters (no spaces): ";
	gets_s(platenum);

	while (platenum[0] != zero[1]) {
	plates << platenum << endl;
	cout << "Please input a license plate number with 7 characters (no spaces): ";
	gets_s(platenum);

	c++;

	}

	plates.close();

	cout << "The number of iterations are: " << c << endl;

	cin.get();
	return 0;
}
