// FindSquareRootwBinSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int findSquareRoot(int n, int low, int high) {
	int mid = low + (high - low) / 2;
	if (mid*mid == n) {
		return mid;
	}
	if ( high >= low) {
		if (mid*mid > n) {
			findSquareRoot(n, low, mid - 1);
		}
		else {
			findSquareRoot(n, mid + 1, high);
		}
	}
	else return low;				//return low will give closest square root
	//else return -1;				//return -1 if it doesn't have a square root
}

//int findSquareRoot( )

int main()
{
	int res = findSquareRoot(1001, 0, 1001);
	
    return 0;
}

