// NRepeatedElementsSize2NE.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/submissions/
// given an array of 2N size, there will be N unique numbers, and N of a repeated number
//find that number that is repeated

#include "stdafx.h"
#include <vector>

using namespace std;

void sortN(vector<int>& A, int head, int tail) {
	if (head >= tail) {
		return;
	}
	else {
		
		int a = head;
		int pivot = A[tail];
		for (int i = head; i < tail; i++) {
			if (A[i] <= pivot) {
				swap(A[a++], A[i]);
			}
		}
		swap(A[a], A[tail]);

		sortN(A, head, a-1);
		sortN(A, a + 1, tail);
	}
}

//using quicksort (above sort method) to sort then looking for repeats
int repeatedNTimes(vector<int>& A) {
	//sort A
	//2 ptrs, compare current and previous, return current when current == previous

	int size = A.size();
	sortN(A, 0, size - 1);

	for (int i = 1; i < size; i++) {
		if (A[i] == A[i - 1]) {
			return A[i];
		}
	}
	return -1;
}

int repeatedNTimesMap(vector<int>& A) {
	//create array of 5000, map do it mapstyle
	int map[10000] = { 0 };
	int size = A.size();
	for (int i = 0; i < size; i++) {
		map[A[i]]++;
		if (map[A[i]] > 1)return A[i];
	}
	return -1;
}

//because the repeated number has to take up half the array, in an alternating pattern, it can at most be 3 spaces away
//if it is anymore than 3 spaces away, that means at some point you will have repeats of 2 or less spaces away
int repeatedNTimesLogic(vector<int>& A) {
	for (int i = 1; i < A.size(); i++) {
		if (A[i] == A[i - 1]) return A[i];
		if (i > 1 && A[i] == A[i - 2]) return A[i];
		if (i > 2 && A[i] == A[i - 3]) return A[i];
	}
	return -1;
}

int main()
{
	vector<int> arr = { 4, 7, 1, 6,5, 2, 3 , 9};
	vector<int> arr2 = { 4,3,2,1, 4 };
	sortN(arr, 0 , arr.size()-1);
	int ans = repeatedNTimes(arr2);
	int ans2 = repeatedNTimesMap(arr2);

    return 0;
}

