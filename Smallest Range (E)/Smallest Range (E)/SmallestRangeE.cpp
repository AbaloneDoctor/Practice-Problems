// SmallestRangeE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>


using namespace std;

//O(NlogN) time because of sort
int smallestRangeI(vector<int>& A, int K) {

	if (A.size() <= 1) { return 0; }
	sort(A.begin(), A.end());

	int low = A[0];
	int high = A[A.size() - 1];
	int gap = high - low;
	if (gap < (2 * K)) {
		return 0;
	}
	else {
		return gap - (2 * K);
	}

}

int smallestRange2(vector<int> &A, int K) {
	//find lowest, find highest
	//if gap is < 2 * K, return 0
	//if not, return gap - 2 * k
	
	if (A.size() <= 0 ) return 0;
	int high = 0;
	int low = 10000;
	for (int itr : A) {
		if (itr > high) high = itr;
		if (itr < low) low = itr;
	}
	int gap = high - low;
	
	int res;
	(gap <= 2 * K) ? res = 0 : res = gap - 2 * K;
	return res;

}

int main()
{
	vector<int> arr = {1,3,6};
	int res = smallestRange2(arr, 1);

    return 0;
}

