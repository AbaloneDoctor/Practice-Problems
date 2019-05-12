// SelfDividingNumE.cpp : Defines the entry point for the console application.
//	https://leetcode.com/problems/self-dividing-numbers/submissions/
//	return vector of nums in range (inclusive) that are self dividing, ie every 10's place is a divisor of itself
// 128: 128 % 1 == 0; 128 % 2 == 0; 128 % 8 == 0

#include "stdafx.h"
#include <vector>

using namespace std;

bool divisorCheck(int num);

//Each num is checked Log10(N) times (number of places of N), * N 
//O(NlogN)
vector<int> selfDividingNumbers(int left, int right) {
	vector<int> res;
	for (int i = left; i <= right; i++) {
		if (divisorCheck(i)) res.push_back(i);
	}
	return res;
}

bool divisorCheck(int num) {
	//while it's bigger than 0, 128 % 10, /10
	int numOG = num;
	int temp;
	while (num > 0) {
		temp = num % 10;
		if (temp == 0) { return false; }
		if (numOG % temp != 0) {
			return false;
		}
		num = num / 10;
	}
	return true;
}



int main()
{
	vector<int> arr = selfDividingNumbers(1, 322);

    return 0;
}

