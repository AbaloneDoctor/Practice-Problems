// PerfectNumE.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/perfect-number/submissions/
//perfect numbers are nums where all its divisors, except itself, total to itself. 
//eg, 28 = 1 + 2 + 4 + 7 + 14, 6 = 1 + 2 + 3

#include "stdafx.h"
#include <math.h>

using namespace std;

//concept: iterate through its divisors, and summing them. Include the complement/remainder to the sum.
//Can stop at square root (num) because any larger divisors would have been captured by earlier divisors.
// 28 , sqrt(28) is around 5. 5 lies between 4 and 7, the largest small divisor, and smallest large divisor (aka complement/remainder)
bool checkPerfectNumber(int num) {

	if (num == 1 || num == 2) return false;
	if (num % 2 == 1) return false;
	int sum = 1;
	int remainder = 0;
	int sqrtNum = sqrt(num);
	for (int i = 2; i <= sqrtNum; i++) {
		if (num % i == 0) {
			if (i == remainder) break;
			remainder = num / i;
			sum += i;
			sum += remainder;
		}
	}
	return (sum == num) ? true : false;
}

int main()
{

	bool res = checkPerfectNumber(28);
    return 0;
}

