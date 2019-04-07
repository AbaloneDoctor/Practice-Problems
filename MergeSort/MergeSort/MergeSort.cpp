// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;
															//merge will only be called on arrays of size >1
void merge(vector<int> &A, int left, int right, int mid) {	//note: mid will always be = to left because of rounding down, when you divide by 2
	vector<int> aLeft, aRight;								//this is why we iterate from left to <mid+1. Guarantees you run once at least
	
	for (int i = left; i <= mid ; i++) {
		aLeft.push_back(A[i]);
	}
	for (int j = mid+1; j <= right; j++) {						//this will always run because mid will always be smaller than right	
		aRight.push_back(A[j]);									
	}
	int itrLeft = 0;									//iterates through left temp array
	int itrRight = 0;									//iterates through right temp array
	int aItr = left;									//iterates through original vector A
														//have to start at left because we are working from original array A
	int leftEnd = mid - left + 1;
	int rightEnd = right - mid;
	while (itrLeft < leftEnd && itrRight < rightEnd) {	//compare members of left and right subarrays, merge into 1 array in sorted order
		if (aLeft[itrLeft] > aRight[itrRight]) {		//stops when one of subarrays are completely copied over
			A[aItr] = aRight[itrRight];
			itrRight++;
			aItr++;
		}
		else {												//default adds left value if comparison is same (keeps stability/order)
			A[aItr] = aLeft[itrLeft];
			itrLeft++;
			aItr++;
		}
	}
	if (itrLeft == leftEnd) {									//finishes copying the unfinished array into final array
		for (itrRight; itrRight < rightEnd; itrRight++) {
			A[aItr] = aRight[itrRight];
			aItr++;
		}
	}
	else {
		for (itrLeft; itrLeft < leftEnd; itrLeft++) {
			A[aItr] = aLeft[itrLeft];
			aItr++;
		}
	}
}

void mergeSort(vector<int> &A, int left, int right) {
	if (right > left) {										//runs until right == left (when you're at a subarray size of 1)
		int mid = left + (right - left) / 2;				//because of rounding down, mid will always finish == left, not right (eg when array size == 2)
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, right, mid);

	}
}

int main()
{
	vector<int> arr = { 1, 3, 6, 2, 4, 5 };
	vector<int> arr2 = { 9, 1, 8, 3, 7, 6, 2, 4, 5 };
	vector<int> arrSmall = { 3,1 };
	vector<int> arr1 = { 1 };
	//merge(arr, 0, 5, 2);
	//mergeSort(arr2, 0, 8);
	//mergeSort(arr, 0, 5);
	mergeSort(arr1, 0, 0);
    return 0;
}

