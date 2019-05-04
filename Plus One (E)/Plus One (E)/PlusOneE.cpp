// PlusOneE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//given an array of single digit numbers representing a number, plus one to the array
//no leading 0's
//obvious way, add go from back to end, add number, if greater than 1, mod it by 10, and add 1 to next int
//problem is if you carry a 1 at most significant digit, you have to insert at front, causing another n operations to adjust array
//O(2N)? I'm not sure if returning the array reversed takes N time or not
//03:51 PM - 05.01.19 : 
vector<int> plusOne(vector<int>& digits) {
	//from end to beginning of array
		//add 1 and check if greater than 9, if so add 1 to next, repeat
	//then return vector in reverse order
	int add1 = 1;
	vector<int> res;
	//pitfalls: you cannot do for( i=end; i ==0; i--). Has to be i>=0
	for (int i = digits.size()-1; i >= 0; i--) {
		int sum = digits[i] + add1;
		if (sum > 9) { 
			sum = sum % 10; 
			add1 = 1;
		}
		else {
			add1 = 0;
		}
		res.push_back(sum);
	}
	if (add1 == 1) { res.push_back(1); }
	return { res.rbegin(), res.rend() };
}


//04:28 PM - 05.01.19 : running >= N times, only run until you don't need to add anymore
//break down into cases
vector<int> plusOneCheckFirst(vector<int>& digits) {
	//case 1: 999 - > 1000
	//case 2: 123 -> 124
	//case 3: 129 -> 130
	int onesPlace = digits.size() - 1;
	for (int i = onesPlace; i >= 0; i--) {
		if (digits[i] < 9) {
			digits[i]++;
			return digits;
		}
		if (digits[i] == 9) {
			digits[i] = 0;
		}
	}
	//if reaches here, that means every digits[i] has been a 9
	//so add new 0 at end, and set largest place digit to 1
	digits[0] = 1;
	digits.push_back(0);
	return digits;
}

int main()
{
	vector<int> arr = { 9, 9, 9, 9, 9 };
	arr = plusOne(arr);

    return 0;
}

