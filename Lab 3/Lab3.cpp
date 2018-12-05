// Lab 3 1CP3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <istream>

using namespace std;

//function prototypes
void underlinetitle (string title);
double calculateCR (double b, double d);
int findClosest(int x, int y, int z);

int _tmain(int argc, _TCHAR* argv[])
{
	string title,numbers, a, b, c;
	double CR, bounce, drop;
	int closest, x = 50, y = 50, z = 50, q = 5, r = 2, s = 5;
	ifstream inFile;


	//question 1
	cout << "Please type enter a title for this document: ";
	getline(cin, title);

	cout << endl;
	cout << title << endl;

	underlinetitle(title);



	//question 2
	cout << "Bounce height: ";
	cin >> bounce;
	cin.ignore();

	cout << "Drop height: ";
	cin >> drop;
	cin.ignore();


	CR = calculateCR(bounce, drop);

	if (CR == -1.0) {
		cout << "Error: Invalid input" << endl;
	}
	cout << "Coefficient of Restitution: " << setprecision(3) << fixed << CR << endl;


	//question 3


	while ((x, y, z) != 0 ) {

		cout << "Please enter 3 numbers to determine which is the closest to 0" << endl;

		cout << "x: ";
		cin >> x;
		cin.ignore();

		cout << "y: ";
		cin >> y;
		cin.ignore();


		cout << "z: ";
		cin >> z;
		cin.ignore();


	closest = findClosest(x, y, z);

	cout << "The closest number to 0 is: " << closest << endl;
	}

	cout << "Program close" << endl;

	//Bonus Question

	inFile.open("LAB3DATA.txt");


	if (inFile) {

		getline(inFile,(a,b,c));


		cout << a  << b << c << endl;

	a = q;
	b = r;
	c = s;

		if (q && r && s == 0) {
			cin.get();
			exit(0);
		} else{


			while (inFile >> a >> b >> c) {


			cout << a  << " " << b << " " << c << endl;



		}
		}
	} else {
		cout << "File does not exist" << endl;
	}

	cin.get();
	return 0;
}

//function definition
void underlinetitle (string title) {

	for (int i = 1; i <= title.length() ; i++) {
		cout << "=";

	}
	cout << endl;
}

double calculateCR (double b, double d) {
	double CR;

	CR = sqrt(b / d);

	if (CR <= 0 || b > d) {
		return (-1.0);
	} else {
		return CR;

	}
}

int findClosest(int x, int y, int z) {

	int closest;

		if (abs(x) < abs(y) && abs(x) < abs(z)) {
			return x;
		} else if (abs(y) == abs(x) && abs(y) < abs(z)) {
			return x;
		} else if (abs(z) == abs(x) && abs(z) < abs(y)) {
			return x;
		} else if (abs(z) <= abs(y) && abs(z) >= abs(x)) {
			return x;

		} else if (abs(y) < abs(x) && abs(y) <= abs(z)) {
			return y;
		}
		return z;


}
