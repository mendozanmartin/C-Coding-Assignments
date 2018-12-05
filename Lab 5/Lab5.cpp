// 1CP3_Lab5_Martin_Mendoza.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cmath>
#include <xtgmath.h>
#include <string>
#include <conio.h>


using namespace std;

void print2dArray(double arr[60][6], int ROW, int COLUMN);


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	const int ARRAYSIZE = 101;
	int i, numbers[ARRAYSIZE], maxnum = -5, sum, sum1 = 0, maxindex = 5;
	double average;

	for (i = 0; i < ARRAYSIZE; i++) {
		numbers[i] = rand() % 100 + 100;


		sum = numbers[i] + sum1;
		sum1 = sum;


	if (numbers[i] > maxnum) {
		maxnum = numbers[i];

	maxindex = i;

	}


	}

	average = sum / ARRAYSIZE;

	cout << "The total of all the 100 numbers is: " << sum << endl;
	cout << "The average of the 100 numbers is: " << average << endl;
	cout << "The maximum number is: " << maxnum << endl;
	cout << "The index of the maximum value is: " << maxindex << endl;

	////////////////////Question 2///////////////////////////
	/////////////////////////////////////////////////////////


	ifstream infile;
	infile.open("scores.txt");
	int const ROW = 50, COLUMN = 6;
	int r, c, rindex, cindex;
	double arr[ROW][COLUMN], sumr[ROW] = {0}, sumc[COLUMN] = {0}, highc = -5000, lowr = 5000, closest50, closestindex, abs50 = 50000, low50;

	for (r = 0; r < ROW; r++){
		for(c = 0; c < COLUMN; c++){


			infile >> arr[ r ][ c ] ;
		}

		}

	print2dArray(arr, ROW, COLUMN);
	cout << endl << endl << endl;

	for(r = 0; r< ROW; r++) {
		for (c = 0; c < COLUMN; c++) {

			sumr[r] += arr[r][c];
		}

		if (sumr[r] < lowr) {
			lowr = sumr[r];
			rindex = r;

		}
	}

	for (c = 0; c < COLUMN; c++) {
	for(r = 0; r< ROW; r++) {

		sumc[c] += arr[r][c];
	}
		if (sumc[c] > highc) {
			highc = sumc[c];
			cindex = c;
		}
	}

	for (c = 0; c < COLUMN; c++) {
	for(r = 0; r< ROW; r++) {


		if (fabs((arr[r][c]) - 50) < abs50) {

		abs50 = (fabs((arr[r][c]) - 50));

		}
	}
	}






		cout << "The highest column total is: " << highc << endl;
		cout << "The column number with the highest total is: " << cindex << endl << endl;

		cout << "The row with the lowest total is: " << lowr<< endl;
		cout << "The row number with the lowest total is: " << rindex << endl;

		cout << "The number closest to 50 is: " << abs50 << endl;

		//////////Question 3//////////////
		//////////////////////////////////



		cout << "Please input a password that meets the following criteria. " << endl;
		cout << "1. The password should be at least six characters long. " << endl;
		cout << "2. The password should contain at least one upper case and one lower case letter. " << endl;
		cout << "3. The password should have at least one digit. " << endl;

		cout << "Password: ";



	cin.ignore();
	return 0;
}

void print2dArray(double arr[50][6], int ROW, int COLUMN) {

	for (int row = 0; row < ROW; row++){
		for(int col = 0; col < COLUMN; col++){
			cout << arr[ row ][ col ] << "\t";
		}
		cout << "\n";
	}
	}
