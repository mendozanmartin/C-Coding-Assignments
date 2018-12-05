// Lab4 1CP3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void read2Values (double *v1, double *v2);
bool calculateBox (double length, double width, double height, double *surfaceArea, double *volume);

int _tmain(int argc, _TCHAR* argv[])
{
	double value1, value2, length, width, height, surfaceArea, volume;

	read2Values(&value1, &value2);


	cout << "The first value is: " << value1 << endl;
	cout << "The second value is: " << value2 << endl;

	//Question 2
	//--------------------------------------------------------------------------------------------------
	cout << "----------------------------------------------------------" << endl << endl;


	cout << "Please input a length value (length > 0): ";
	cin >> length;
	cin.ignore();

	cout << "Please input a width value (width > 0): ";
	cin >> width;
	cin.ignore();

	cout << "Please input a height value (height > 0): ";
	cin >> height;
	cin.ignore();

	calculateBox(length, width, height, &surfaceArea, &volume);

if (calculateBox(length, width, height, &surfaceArea, &volume)) {

	cout << "The surface area of the rectangle is: " << surfaceArea << endl;
	cout << "The volume of the rectangle is: " << volume << endl;
} else {
	cout << "Error: The dimensions are not greater than 0" <<  endl;
}

	cin.get();
	return 0;
}

void read2Values (double *v1, double *v2){

	cout << "Please enter 2 decimal values that are greater than 0" << endl;
	cout << "v1: ";
	cin >> *v1;
	cin.ignore();

	while (*v1 <= 0) {
		cout << "Error: Please input a value greater than 0" << endl;
		cout << "v1: ";
		cin >> *v1;
		cin.ignore();
	}



	cout << "v2: ";
	cin >> *v2;
	cin.ignore();



	while (*v2 <= 0) {
		cout << "Error: Please input a value greater than 0" << endl;
		cout << "v2: ";
		cin >> *v2;
		cin.ignore();
	}
}

bool calculateBox (double length, double width, double height, double *surfaceArea, double *volume) {
	if (length && width &&  height >0) {
		*volume = length * width * height;
		*surfaceArea = 2 * (length*width) + 2 * (height*width) + 2 *(length*height);

		return true;

	} else {
		return false;
	}
}
