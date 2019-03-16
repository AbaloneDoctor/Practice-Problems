// LetterCombinationsofPhoneNumber.cpp : Defines the entry point for the console application.
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.


#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void printList(vector<string> arr);											//forward declaration for debugging

//Brute force method
//Idea: go through
//timing is O(3^N), N is length of string of digits
vector<string> letterCombinationsBrute(string digits) {
	string arr[10] = { "0", "0", "abc", "def", "ghi", "jkl", "mno" , "pqrs", "tuv", "wxyz" };
	vector<string> combos;

	//seed the first digit's letters in
	int seedNum = digits[0] - '0';
	for (char letter : arr[seedNum]) {
		string newString;
		newString.push_back(letter);
		combos.push_back(newString);
	}
	for (int itr = 1; itr < digits.size(); itr++) {							//for every number in string digits
		int num = digits[itr] - '0';
		vector<string> updatedCombos;

		for (string combItr : combos) {										//for every word in current combos		
			for (int currItr = 0; currItr < arr[num].size(); currItr++) {	//for every letter in new combo (so 3 or 4)
				string newCombo;											//generate a new word combo 
				newCombo += combItr;
				newCombo += arr[num][currItr];
				updatedCombos.push_back(newCombo);
			}
		}
		combos = updatedCombos;												//update old list to include new additions
	}																		//eg. a,b,c -> ae, be, ce, ad, bd, cd, ae, be, ce
	return combos;
}

void printList( vector<string> list ) {
	int count = 0;
	for (string s : list) {
		cout << s << " ";
		count++;
	}
	cout << endl;
	cout << "Number of combinations: " << count << endl;
}


int main()
{
	string input;
	while (1) {
		cout << "input t9 number: ";
		cin>>input;
		if (input == "end") break;
		printList( letterCombinationsBrute(input) );
	} 
	cin.get();

    return 0;
}

