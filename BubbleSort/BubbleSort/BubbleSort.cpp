// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

//O(N*N)
void bubbleSort(vector<int> &A) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 1; i < A.size(); i++){
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
				swapped = true;
			}
		}
	} while (swapped == true);
}

int main()
{
	vector<int> arr = { 1, 3, 4, 8, 2, 3, 5};
	bubbleSort(arr);
	
	/*
	for (int itr : arr) {					//use debugger and check arr in local variables after function is ran
		cout << itr << " ";
	}
	*/

    return 0;
}

