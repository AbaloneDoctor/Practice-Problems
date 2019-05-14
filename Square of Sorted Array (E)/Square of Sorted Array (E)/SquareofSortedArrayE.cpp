// SquareofSortedArrayE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

/*
options: sort then square, NlogN
or 2 ptrs, N, but N space

//either fast runtime with N space usage, or slow run time (inplace sort) but constant space usage

2 pointers, start at ends, square and compare, then put into vector

//head ptr, tail ptr
//while ( headptr < tail ptr)
//square then compare, for larger one, push and inc

*/

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> res;
		int head = 0;
		int tail = A.size() - 1;
		int headSqr;
		int tailSqr;
		while (head <= tail) {
			headSqr = pow(A[head], 2);
			tailSqr = pow(A[tail], 2);
			//headSqr = A[head] * A[head];
			//tailSqr = A[tail] * A[tail];
			if (headSqr > tailSqr) {
				res.push_back(headSqr);
				head++;
			}
			else {
				res.push_back(tailSqr);
				tail--;
			}
		}
		return { res.rbegin(), res.rend() };
	}
};


int main()
{
	vector<int> arr = { -4,-1,0,3,10 };

	Solution sol;
	vector<int> res = sol.sortedSquares(arr);

    return 0;
}

