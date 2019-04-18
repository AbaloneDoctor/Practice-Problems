// MountainArrayPeakE.cpp : Defines the entry point for the console application.
//	https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//binary search, O(logN)
//idea: because 3 sequential numbers have to necessarily be either a<b<c, a<b>c, or a>b>c, this is perfect for binary search
//either go left or right, or you've found it
int search(vector<int>&A, int l, int m, int r) {
	if (A[m - 1] < A[m] && A[m]>A[m + 1]) {
		return m;
	}
	else {
		if (A[m - 1] < A[m] && A[m] < A[m + 1]) {
			return search(A, m, (m + r) / 2, r);
		}
		if (A[m - 1] > A[m] && A[m] > A[m + 1]) {
			return search(A, l, (m + l) / 2, m);
		}
	}
}

int peakIndexInMountainArray(vector<int>& A) {
	int right = 0;
	int left = A.size() - 1;
	int mid = (left + right) / 2;
	return search(A, right, mid, left);
}

int main()
{
	vector<int> arr = { 0,1,0 };
	int res = peakIndexInMountainArray(arr);


	vector<int> arr2 = { 0,2, 3, 4, 5, 6, 8, 9, 1,0 };
	int res2 = peakIndexInMountainArray(arr2);

    return 0;
}

