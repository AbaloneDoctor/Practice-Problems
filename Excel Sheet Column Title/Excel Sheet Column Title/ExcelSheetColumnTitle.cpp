// ExcelSheetColumnTitle.cpp : Defines the entry point for the console application.
//	Given an integer, return its column title. Eg 1->A.. 26->Z, 27->AA
//	Note: you should be able to convert from one to another, AA = 1*26^1 (26) + 1*26^0 (1)= 27

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
timing: O(logN), dividing a given N by 26 until you hit 0

take number, divide by 26, each time it can be divided is equal to # in abc, and remainder is corresponding num
260/ 26 = 100, /26 , 3 = 78, 22 remainder which is v, so CV. 

take n % 26, remainder is push_front()
while n > 0 { n % 26, push front; n/=26; }

*/

string convertToTitleDivision( int n ) {
	vector<string> titles = { "Z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y" };
	string res;
	//int divisor = 26;
	while (n > 0) {
		
		int remainder = n % 26;
		if (remainder == 0) { n--; }			//have to skip 1 because Z is naturally A**
		//cout << "remainder: " << remainder << endl;
		res.insert(0, titles[remainder]);
		//n--;									//why does using this instead of ^ do the same exact thing?
		//cout << "n: " << n << endl;
		n /= 26;
		//cout << "n post /: " << n << endl;
		
	}
	return res;
}

//Loops for user input numbers
void convertToTitleDEMO() {
	int input = 1;
	while (input != 0) {
		cout << "Input number to convert to title: ";
		cin >> input;
		cout << convertToTitleDivision(input) << endl;
	}
}

//Prints all combinations from 0 to 9999
void convertPrintAllDemo() {
	cout << "Printing titles for 0-9999:" << endl;
	for (int i = 0; i < 1000; i++) {
		cout << convertToTitleDivision(i) <<" ";
	}
	cin.get();
}

int main()
{
	convertToTitleDEMO();
	convertPrintAllDemo();
	
	cin.get();
    return 0;
}

