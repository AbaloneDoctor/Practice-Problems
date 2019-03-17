// LetterCombinationsofPhoneNumber.cpp : Defines the entry point for the console application.
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//March 15-16

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
		vector<string> updatedCombos;
		int num = digits[itr] - '0';
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

//Solution using backtracking/recursion
//timing is faster because it doesn't go through each path. When it reaches end of 1 combo, it steps back 1 letter and does the 
//next letter of the group in the for(:) loop
class solution {
public:
	vector<string> combos;
	string t9[10] = { "", "", "abc", "def", "ghi", "jkl", "mno" , "pqrs", "tuv", "wxyz" };

	void backtrack( string newCombo, string remainingDigits, string letter) {
		if (remainingDigits.size() == 0) {
			newCombo += letter;
			combos.push_back(newCombo);
		}
		else {
			newCombo += letter;
			int currDigit = remainingDigits[0] - '0';
			string currLetters = t9[currDigit];
			remainingDigits.erase(remainingDigits.begin());		//erase first digit in remaining digits
			for (char itr : currLetters) {						
				string singleLetter(1, itr);					//properly convert from char to string
				backtrack(newCombo, remainingDigits, singleLetter);
			}
		}
	}

	vector<string> letterCombinationsBacktrack(string digits) {
		backtrack("", digits, "");
		return combos;
	}

	//search using backtrack
	bool search(string digits, string combo) {
		if (combo.size() > digits.size()) return false;		//combo can be shorter, but not longer (ie combo has been input by digits)
		if (combo.size() == 0) return true;
		else {
			string currLetters = t9[digits[0] - '0'];
			for (char itr : currLetters) {
				string itrString(1, itr);
				if (combo[0] == itr) {
					digits.erase(digits.begin());
					combo.erase(combo.begin());
					return search(digits, combo);			//will return true if they are all recursively true
				}
			}
			return false;
		}
	}
};

void printList( vector<string> list ) {						//print function for both brute and backtrack methods
	int count = 0;
	for (string s : list) {
		cout << s << " ";
		count++;
	}
	cout << endl;
	cout << "Number of combinations: " << count << endl;
}

void letterCombinationsDEMO() {
	string input;
	while (1) {
		solution sol;
		cout << "input t9 number: ";
		cin>>input;
		if (input == "end") break;
		//printList( letterCombinationsBrute(input) );
		printList(sol.letterCombinationsBacktrack(input));	
	}
}

void letterCombinationsSearchDEMO() {
	string input;
	string input2;
	while (1) {
		solution sol;
		cout << "input digits and combo: " << endl;
		cin >> input;
		if (input == "end") break;
		cin >> input2;
		cout << sol.search(input, input2) << endl;
	} 
}

int main()
{

	letterCombinationsDEMO();
	letterCombinationsSearchDEMO();
 
	cin.get();

    return 0;
}

