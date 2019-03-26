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
//timing is O(N^3), N is length of string of digits
vector<string> letterCombinationsBrute(string digits) {
	string arr[10] = { "0", "0", "abc", "def", "ghi", "jkl", "mno" , "pqrs", "tuv", "wxyz" };
	vector<string> combos;

	//seed the first digit's letters in										//EG. 234, seedNum = 2 ([2]34)
	int seedNum = digits[0] - '0';											//arr[2] = "abc"
	for (char letter : arr[seedNum]) {										//combos = { "a", "b", "c"}
		string newString;
		newString.push_back(letter);
		combos.push_back(newString);
	}
	for (int itr = 1; itr < digits.size(); itr++) {							//for every remaining number in string digits (3 and 4)
		vector<string> updatedCombos;
		int num = digits[itr] - '0';
		for (string combItr : combos) {										//for every word in current combos	{"a", "b", "c"}	
			for (int currItr = 0; currItr < arr[num].size(); currItr++) {	//for every letter in new combo { "d", "e", "f"}, { "g", "h", "i" }
				string newCombo = combItr;									//generate a new word combo, start with prev combo { "a", "b", "c" } 
				newCombo += arr[num][currItr];								//append current combo {"ad", "ae", "af" , "bd", "be" .. }
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

	void backtrack( string newCombo, string remainingDigits, string letter) {	//EG digits = 234
		if (remainingDigits.size() == 0) {						//base case, when digits is shrunken to nothing
			newCombo += letter;
			combos.push_back(newCombo);
		}
		else {
			newCombo += letter;									// ""
			int currDigit = remainingDigits[0] - '0';			// "abc"
			string currLetters = t9[currDigit];
			remainingDigits.erase(remainingDigits.begin());		//erase first digit in remaining digits,	digits = []34
			for (char itr : currLetters) {						// for each  'a', 'b', 'c'
				string singleLetter(1, itr);					//properly convert from char to string, 1 is size
				backtrack(newCombo, remainingDigits, singleLetter);
			}													//recursively (backtrack) creates: { "adg", "adh", "adj", "aeg", "aeh", "aei"...}
		}														//order: 111, 112, 113, 121, 122, 123, 131, 132, 133, 211, 212, 213, 221, 222...
	}

	vector<string> letterCombinationsBacktrack(string digits) {
		backtrack("", digits, "");
		return combos;
	}

	//search using backtrack
	bool search(string digits, string combo) {
		if (combo.size() > digits.size()) return false;		//combo can be shorter, but not longer (ie combo has been input by digits)
		if (combo.size() == 0) return true;					//base case: you've gone through every letter and nothing has returned false, return true
		else {
			string currLetters = t9[digits[0] - '0'];		//return letter group of first num
			for (char itr : currLetters) {					
				string itrString(1, itr);					//convert itr letter(char) to a string of a single leter
				if (combo[0] == itr) {						//if matches, keep searching, if not nothing happens, but will default to return false
					digits.erase(digits.begin());			//	if none of the letters match	
					combo.erase(combo.begin());				//erase first digit and first letter of combo since we've matched
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
		cout << "input t9 number to generate all possible t9 words: ";
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
		cout << "Search: input digits and combo you want to check: " << endl;
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

