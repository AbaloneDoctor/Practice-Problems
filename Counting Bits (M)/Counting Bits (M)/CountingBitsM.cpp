// CountingBitsM.cpp : Defines the entry point for the console application.
//https://leetcode.com/problems/counting-bits/

// Pattern
// 8-11, same as i - 8/2, 12-15 = i-8/2 +1
// 0, 1, | 1, 2, | 1, 2, 2, 3, | 1, 2, 2, 3, 2, 3, 3, 4, |
// 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, | 1
// 0, 01, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100
// 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110,
// 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000
//notice each segment has first half same as previous segment, second half is same segment but incremented by 1

#include "stdafx.h"
#include <vector>

using namespace std;
vector<int> countBits(int num) {

	vector<int> arr(num+1, 0);
	arr[0] = 0;
	arr[1] = 1;
	
	//arr iterator
	int itr = 2;

	//only needs to run log2(num) times because for each loop, it'll run 2^i times
	for (int i = 1; i <= log2(num); i++) {
		//first half is identical equal to previous segment
		int halfInc = pow(2, i) / 2;
		for (int j = 0; j < halfInc; j++) {
			arr[itr] = arr[itr - halfInc];
			itr++;
			if (itr > num)return arr;
		}
		//second half is identical to first half, but incremented by 1 for all
		for (int j = 0; j < halfInc; j++) {
			arr[itr] = arr[itr - halfInc] + 1;
			itr++;
			if (itr > num)return arr;
		}
	}
	return arr;
}


int main()
{
	
	vector<int> res = countBits(17);

    return 0;
}

