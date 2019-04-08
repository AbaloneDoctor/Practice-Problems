// HammingDistance.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/hamming-distance/
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

/*
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
↑   ↑
*/

#include "stdafx.h"


//idea: convert to binary and compare each digit (the remainder after division)
//O(logN), N == to the bigger of x and y
int hammingDistance(int x, int y) {
	int ham = 0;
	while (x != 0 || y != 0) {
		if (x % 2 != y % 2) {				//check if their 1's place is the same
			ham++;
		}
		x /= 2;
		y /= 2;
	}
	return ham;
}


//bitwise operator method
//xor on binary code takes n time (for length of binary num)
//but the lenth of bin num is log(n) of value
//so it's also O(logN)
//idea: xor x and y, then count
int hammingDistanceBitwise(int x, int y) {
	int xor = x^y;							//xor: prints binary num with bits == 1 where x and y differ
	int ham = 0;							//eg 1110^1111 == 0001
	while (xor > 0) {
		ham += xor&1;						// AND mask will, eg 1101 & 0001 == 0001 (returns first digit bit)
		xor >>= 1;							//bitshift to right, same as divide by 2
	}
	return ham;
}

int main()
{
	int arg1 = 1;
	int arg2 = 2;
	int a = hammingDistance(arg1, arg2);
	int b = hammingDistanceBitwise(arg1, arg2);



    return 0;
}

