// SquareofSortedArray.cpp : Defines the entry point for the console application.
//https://leetcode.com/problems/squares-of-a-sorted-array/
//given array of num in increasing order, return array of squared values in increasing order. Includes negative nums
//Input: [-4,-1,0,3,10]
//Output: [0, 1, 9, 16, 100]

#include "stdafx.h"
#include <vector>

using namespace std;

//fastest solution, O(N)
//better than squaring all of them then sorting (NlogN)
//idea: because we have to consider negative numbers, we start from front and back end, square and then compare. 
//bigger one is added into an array res of same size as A (we fill in from back to front), and then incremented,
//we move towards center from outside
vector<int> sortedSquares(vector<int>& A) {
	int itrFront = A.size() - 1;
	int itrBack = 0;
	int aItr = A.size() - 1;				//iterates through final array

	vector<int> res(A.size());

	while (itrFront > itrBack) {
		int a = A[itrFront];
		int b = A[itrBack];
		a *= a;
		b *= b;
		if (a >= b) {
			res[aItr] = a;
			aItr--;
			itrFront--;
		}
		else {
			res[aItr] = b;
			aItr--;
			itrBack++;
		}
	}
	return res;
	
}

int main()
{
	vector<int> arr = { -4,-1,0,3,10 };
	arr = sortedSquares(arr);


    return 0;
}

