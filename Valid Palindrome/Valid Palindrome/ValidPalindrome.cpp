// ValidPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//returns if given string is a palindrome or not
//ignore non-alphanum, assume only lower case
//idea: read through, appending letters only, start matching after halfway
//2 ptrs, one at start and one at end converge in middle, while checking for same letters
// O(N+N/2) 
bool isPalindrome(string s) {						//needs N space, and takes N/2 longer. Instead iterate ptrs by ignoring nonalpha
	vector<char> letters;
	int leftPtr = 0;
	int rightPtr;
	
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) {
			letters.push_back(s[i]);
		}
	}

	rightPtr = letters.size() - 1;

	while (leftPtr != rightPtr && leftPtr < rightPtr) {
		if (letters[leftPtr] != letters[rightPtr]) {
			return false;
		}
		leftPtr++;
		rightPtr--;
	}
	return true;
}

//more efficient version
//2 ptrs, advance if one of them is nonalpha
//only compare when they are both alpha
bool isPalindrome2(string s) {
	int left = 0;
	int right = s.size() - 1;
	while (left < right) {
		if (!isalpha(s[left])) {
			left++;
		}
		if (!isalpha(s[right])) {
			right--;
		}
		if (isalpha(s[right]) && isalpha(s[left])) {
			if (s[right] != s[left]) {
				return false;
			}
			else if (s[right] == s[left]) {
				left++;
				right--;
			}
		}

	}
	return true;
}

void isPalindromeSol() {
	string pal = "l     racec ar l";
	string notPal = "palindrome";
	cout << isPalindrome2(notPal) << endl;
	cout << isPalindrome2(pal) << endl;
}


int main()
{
	isPalindromeSol();
	cin.get();
    return 0;
}

