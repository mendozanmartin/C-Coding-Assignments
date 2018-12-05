// 1CP3 Assignment 3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct wave {
int year;
int month;
int day;
int hour;
int minute;
double waveheight;
double wavelength;
};


struct DNAnt {
int A;
int C;
int G;
int T;
char DNAstrand[80][100];
};


//function prototypes
void data2DNA (void);
void countDNAnt (void);
void rcounter (int r);
void DNAtoRNA (DNAnt allDNA, int r);
void DNAtoRNAcounter (void);
void DNAtoRNA2 (DNAnt allDNA, int r);
void DNAtoRNA (DNAnt allDNA, int r);
void DNAtoRNAcounter2 (DNAnt allDNA);
void DNAtoRNAforT (DNAnt allDNA, int r) ;

int _tmain(int argc, _TCHAR* argv[])
{
ofstream steepwave;
ifstream filedata;
int b, i = 0, highdata2010, highdata2011, highdata2012;
double steepness, steepness2010 = 0, avsteepness2010, count2010 = 0, high2010 = 0;
double steepness2011 = 0, avsteepness2011, count2011 = 0, high2011 = 0;
double steepness2012 = 0, avsteepness2012, count2012 = 0, high2012 = 0;

wave wavedata[50];
filedata.open("wavedata.dat");
steepwave.open("steepwave.txt");


while (!filedata.eof()) {
filedata >> wavedata[i].year >> wavedata[i].month >> wavedata[i].day >> wavedata[i].hour >> wavedata[i].minute >> wavedata[i].waveheight >> wavedata[i].wavelength;
steepness = wavedata[i].waveheight/wavedata[i].wavelength;
if (wavedata[i].year == 2010) {
steepness2010 += steepness;
count2010++;
if (steepness > high2010) {
high2010 = steepness;
}
highdata2010 = i;
}


if (wavedata[i].year == 2011) {
steepness2011 += steepness;
count2011++;
if (steepness > high2011) {
high2011 = steepness;
}
highdata2011 = i;


}
if (wavedata[i].year == 2012) {
steepness2012 += steepness;
count2012++;
if (steepness > high2012) {
high2012 = steepness;
}
highdata2012 = i;


}
if (steepness > (1/7.0)) {
steepwave << wavedata[i].year<< '\t' << wavedata[i].month << '\t'<< wavedata[i].day <<'\t'<< wavedata[i].hour <<'\t'<< wavedata[i].minute <<'\t'<< wavedata[i].waveheight <<'\t'<< wavedata[i].wavelength << '\t' << steepness << endl;
}
i++;
}
steepwave.close();
avsteepness2010 = (steepness2010)/(count2010);
avsteepness2011 = (steepness2011)/(count2011);
avsteepness2012 = (steepness2012)/(count2012);


cout << "The average steepness in 2010 is: " << avsteepness2010 << endl;
cout << "The average steepness in 2011 is: " << avsteepness2011 << endl;
cout << "The average steepness in 2012 is: " << avsteepness2012 << endl << endl;


cout << "The steepest wave in 2010 is: " << high2010 << " and the data is:" << endl;
cout << "year" << '\t' << "month" << '\t' << "day" << '\t' << "hour" << '\t' << "minute" << '\t' << "height" << '\t' << "length" << endl;
cout << "--------------------------------------------------------------" << endl;
cout << wavedata[highdata2010].year<< '\t' << wavedata[highdata2010].month << '\t'<< wavedata[highdata2010].day <<'\t'<< wavedata[highdata2010].hour <<'\t'<< wavedata[highdata2010].minute <<'\t'<< wavedata[highdata2010].waveheight <<'\t'<< wavedata[highdata2010].wavelength << '\t' << endl<< endl;
cout << "The steepest wave in 2011 is: " << high2011 << " and the data is:" <<endl;
cout << "year" << '\t' << "month" << '\t' << "day" << '\t' << "hour" << '\t' << "minute" << '\t' << "height" << '\t' << "length" << endl;
cout << "--------------------------------------------------------------" << endl;
cout << wavedata[highdata2011].year<< '\t' << wavedata[highdata2011].month << '\t'<< wavedata[highdata2011].day <<'\t'<< wavedata[highdata2011].hour <<'\t'<< wavedata[highdata2011].minute <<'\t'<< wavedata[highdata2011].waveheight <<'\t'<< wavedata[highdata2011].wavelength << '\t' << endl << endl;
cout << "The steepest wave in 2012 is: " << high2012 << " and the data is:" << endl;
cout << "year" << '\t' << "month" << '\t' << "day" << '\t' << "hour" << '\t' << "minute" << '\t' << "height" << '\t' << "length" << endl;
cout << "--------------------------------------------------------------" << endl;
cout << wavedata[highdata2012].year<< '\t' << wavedata[highdata2012].month << '\t'<< wavedata[highdata2012].day <<'\t'<< wavedata[highdata2012].hour <<'\t'<< wavedata[highdata2012].minute <<'\t'<< wavedata[highdata2012].waveheight <<'\t'<< wavedata[highdata2012].wavelength << '\t' << endl << endl;


//////Question 2////////////////////////////////
////////////////////////////////////////////////

cout << endl << endl << endl;


cout << "Question 2" << endl;
cout << "----------------------------------------------------" << endl << endl;


int const ROW = 80, COLUMN = 100;
ifstream DNAtxt;
DNAtxt.open("DNA.txt");


data2DNA(); 
countDNAnt();
DNAnt allDNA = {0, 0, 0, 0, 0};
for (int r = 0; r < ROW; r++) {
for (int c = 0; c< COLUMN; c++) {


DNAtxt >> allDNA.DNAstrand[r][c];
}
}
ofstream RNAfile;
RNAfile.open("RNA.txt");


DNAtoRNAcounter2(allDNA);
RNAfile.close();
cin.get();
return 0;
}


void data2DNA (void) {
ifstream DNAfile;
ofstream DNAtxt;
int const ROW = 80, COLUMN = 100;
int r, c;
int DNAarr[ROW][COLUMN];


DNAfile.open("data.txt") ;
DNAtxt.open("DNA.txt");


for (r = 0; r < ROW; r++) {
for (c = 0; c< COLUMN; c++) {
DNAfile >> DNAarr[r][c];
}
}


for (int row =0; row <ROW; row++){
for (int col = 0; col <COLUMN; col ++){
if (DNAarr[row][col] == 1) {
DNAtxt << "A" << " ";
} else if (DNAarr[row][col] == 2) {
DNAtxt << "C" << " ";
}else if (DNAarr[row][col] == 3) {
DNAtxt << "G" << " ";
} else if (DNAarr[row][col] == 4) {
DNAtxt << "T" << " ";
}
}
DNAtxt << endl;
}
DNAtxt.close();


}


void countDNAnt (void) {
int A, C, G, T;
cout << endl << endl;
cout << "Amount of 'A', 'C', 'G' , 'T' in each DNA strand" << endl << endl;


cout << "Strand number" << setw(10) <<  "A" << setw(10) << "C" << setw(10) << "G" << setw(10) << "T" << endl;
cout << "----------------------------------------------------" << endl << endl;


for (int r = 0; r < 80; r++) {
rcounter(r);
}
}




void rcounter (int r) {
ifstream DNAtxt;
int c, A = 0, C = 0, G = 0, T = 0;
char nucleotides;
char ACGT[80][100];



DNAtxt.open("DNA.txt");
for (int row = 0; row < 80; row++) {
for (int col = 0; col <100; col ++) {
DNAtxt >> ACGT[row][col];


}


}




for (int col = 0; col < 100; col ++) {

if (ACGT[r][col] == 'A') {
A++;
} else if (ACGT[r][col] == 'C') {
C++;
} else if (ACGT[r][col] == 'G') {
G++;
} else if (ACGT[r][col] == 'T') {
T++;
}

}
cout << r << setw(22) << A << setw(10) << C << setw(10) << G << setw(10) << T << endl;
}

void DNAtoRNAcounter2 (DNAnt allDNA) {
for (int r = 0; r < 80; r++) {


DNAtoRNAforT(allDNA, r);
}
}

void DNAtoRNAforT (DNAnt allDNA, int r) {
int T = 0;
for (int col = 0; col <100; col ++) {
if(allDNA.DNAstrand[r][col] == 'T') {
T++;
}
}
if (T >= 25) {
DNAtoRNA(allDNA, r);
}
if (T < 25) {
DNAtoRNA2(allDNA,r);
}
}

void DNAtoRNA (DNAnt allDNA, int r) {
for (int col = 0; col <100; col ++) {
if (allDNA.DNAstrand[r][col] == 'T') {
cout << 'U' << ' ';
} else {
cout << allDNA.DNAstrand[0][col] << ' ';


}
}
cout << endl;
}
void DNAtoRNA2 (DNAnt allDNA, int r) {
for (int col = 0; col <100; col ++) {
cout << allDNA.DNAstrand[0][col] << ' ';
}
cout << endl;
}
