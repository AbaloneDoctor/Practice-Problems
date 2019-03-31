// SortArraybyParityIIE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//idea: one odd ptr, one even ptr in new vector 
vector<int> sortArrayByParityII(vector<int>& A) {
	vector<int> arr(A.size());
	int evenPtr = 0;
	int oddPtr = 1;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] % 2 == 0) {
			arr[evenPtr] = A[i];
			evenPtr += 2;
		}
		else {
			arr[oddPtr] = A[i]; 
			oddPtr += 2;
		}
	}
	return arr;
}

void sortArrayByParityIISol() {
	vector<int> arg = {4, 2, 5, 7, 1, 2, 2, 1};
	vector<int> res = sortArrayByParityII(arg);
	for (int itr : res) {
		cout << itr << " ";
	}
	cout << endl;

}

int main()
{
	sortArrayByParityIISol();
	cin.get();
    return 0;
}

