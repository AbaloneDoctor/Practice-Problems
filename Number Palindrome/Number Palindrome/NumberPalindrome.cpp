// NumberPalindrome.cpp : Defines the entry point for the console application.
// determine if a number is a palindrome WITHOUT converting to string
// must include negatives

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>

using namespace std;

//idea: compare first and last digits, using %10
//	if negative, immediately return false, if 1 digit, return true
//timing: O(N) = (N)+(N/2) where N is number of digits of inputted integer
bool isPalindrome1(int x) {
	//from 0 to midpoint, divide by %10, then compare it in reverse using a stack with the rest still using %10
	//compare
	vector<int> arr;

	if (x < 10 ) return true;
	if (x < 0) return false;

	while (x > 0) {
		arr.push_back(x % 10);
		x /= 10;
	}
	int j = arr.size() - 1;
	for (int i = 0; i < arr.size()/2+1; i++) {
		if (arr[j] != arr[i]) {
			return false;
		}
		j--;
	}
	return true;
}

//more efficient solution
//timing: O(N), N is length of integer (doesn't have to run extra n/2 times)
//uses stack (more logical data structure)
bool isPalindrome2(int x) {
	
	stack<int> firstHalf;
	float placesHalfFloat = log10(x)+1;
	int odd = (int)placesHalfFloat % 2;
	int placesHalf = (int)placesHalfFloat /2;
	
	if (x < 10) return true;
	if (x < 0) return false;

	for (int i = 0; i < placesHalf; i++) {
		//cout << x % 10 << endl;
		firstHalf.push(x % 10);
		x /= 10;
	}

	if (odd == 1) x /= 10;						//skip middle element if length of integer is odd

	for (int i = 0; i < placesHalf; i++) {
		//cout << x % 10 << endl;					//will only print up until differeing number 
		if (firstHalf.top() != x % 10) return false;
		firstHalf.pop();
		x /= 10;
	}
	return true;
}

//O(N) time complexity, and simpler than first two solutions
//go through x starting from one's place, and reversing it
bool isPalindrome3(int x) {
	int original = x;
	int reversed = 0;

	if (x < 10) return true;
	if (x < 0) return false;

	while (x > 0) {						//starts from 1's place goes to max place
		reversed *= 10;					//grows reversed by 1 digit	(appending 0, aka *10)
 		reversed += x % 10;				//add x's current one's place
		x /= 10;
	}
	if (original == reversed) {
		return true;
	}
	else return false;
}


//Latest/fastest solution
//O(N/2) but really O(N) time complexity
//compares digits starting at both ends, moving towards middle
bool isPalindrome4(int x) {								//EG. 32123
	int places = log10(x) + 1;							//returns what power of 10 it is; + 1 because 32123 = 10^5, but 6 places
	int power10 = pow(10, places-1);					//32123 6 places, but 10^5 power
	int xLeft = x;										//x "pops" 1's place, xLeft "pops" highest place
	int rightEnd;
	int leftEnd;

	if (x < 10) return true;
	if (x < 0) return false;
	
	for (int i = 0; i < places/2; i++) {
		rightEnd = x % 10;								//"pop" right end:	3212[3]
		x /= 10;										//32123->3212[]

		leftEnd = xLeft / power10;						//"pop left end:	[3]2123
		xLeft %= power10;								//32123->[]2123
		power10 /= 10;

		cout << "leftEnd, rightEnd, xLeft, x: " <<  leftEnd << " " << rightEnd << " " <<  xLeft  << " " << x << endl;

		if (rightEnd != leftEnd) return false;
	}
	return true;
}


int main()
{
	cout << "Input number to check for palindrome-ness" << endl;
	int input = 1;
	while ( input != 0) {
		cin >> input;
		//cout << isPalindrome1(input) << endl;
		//cout << isPalindrome2(input) << endl;;
		//cout << isPalindrome3(input) << endl;
		cout << isPalindrome4(input) << endl;
	}

	cin.get();
    return 0;
}

