// ToLowerCase.cpp : Defines the entry point for the console application.
//https://leetcode.com/problems/to-lower-case/
//Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

/*
Input: "Hello"
Output: "hello"
*/

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

//using ascii codes, iterate through str and find corresponding lowercase if str[i] is uppercase
//O(N) runtime
string toLowerCase(string str) {
	for (int i = 0; i < str.size(); i++ ) {
		int temp = str[i];
		char letter;
		if ( str[i] >= 65 && str[i] <= 90) {
			temp += 32;
			str[i] = temp;
		}
	}
	return str;
}


string toLowerCaseCleaner(string str) {
	for (char& c : str) {
		if (c >= 'A' && c <= 'Z') {
			c += 'a' - 'A';
		}
	}
	return str;
}


int main()
{
	string res = toLowerCase("ABCDhello");
	string res2 = toLowerCaseCleaner("ABCDhello");

    return 0;
}

