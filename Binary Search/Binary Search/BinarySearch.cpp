// BinarySearch.cpp : Defines the entry point for the console application.
// https://www.geeksforgeeks.org/binary-search/

#include "stdafx.h"
#include <array>
#include <iostream>

using namespace std;

bool binarySearch(int A[], int left, int right, int x) {
	//base case
	int mid = (left + right) / 2;
	if (x == A[mid]) { 
		return true; }
	if (left >= right ) {													
		return false;
	}
	else {
		
		if ( A[mid] > x) {
			return binarySearch(A, left, mid-1, x);							//this is where the decrement happens
		}
		else  {
			return binarySearch(A, mid+1, right, x);
		}
	}
}

int binarySearch2(int A[], int left, int right, int x) {					//returns index where x is, also uses slightly different recursion
	if (right >= left) {
		//int mid = (left + right) / 2;										//only calculates if right >= left (saves time on 1 loop lol)
		int mid = left + (right - left) / 2;								//safer for overflow 
		if (x == A[mid]) {
			return mid;
		}
		if (x > A[mid]) {
			return binarySearch2(A, mid + 1, right, x);
		}
		else {
			return binarySearch2(A, left, mid - 1, x);
		}
	}
	return -1;																//compared to binarySearch, no else statement, just defaults to -1
																			//if you don't return a true/value during recursion
}

int binarySearchIterative(int A[], int x, int size) {
	//int right = sizeof(A)/sizeof(*A);
	int right = size - 1;
	int left = 0;
	while (right >= left) {
		int mid = left + (right - left) / 2;
		if (A[mid] == x) {
			return mid;
		}
		if (A[mid] > x) {
			right = mid - 1;

		}
		else {
			left = mid + 1;
		}

	}
	return -1;

}

int main()
{
	int arr[] = { 3, 3,3,3,3,4, 7, 8, 9 , 10, 11};
	//bool res = binarySearch(arr, 0, 9, 2);
	//int res = binarySearch2(arr, 0, 10, 11);
	int res = binarySearchIterative(arr, 9, 11);
	cout << res;

	cin.get();
    return 0;
}

