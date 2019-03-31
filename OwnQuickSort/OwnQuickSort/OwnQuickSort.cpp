// OwnQuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

//print array function
void printArr(int *A, int start, int end) {
	int range = end - start + 1;	//end - start is iterator distance, have to add 1 because you want to be inclusive of start and end
	for( int i = 0 ; i < range; i ++){
		cout << A[i] << " ";
		
	}
	cout << endl;
}

//idea: parition algorithm uses pivot to compare elements, looking for smaller members (i iterator). 
//2 iterators, i is fast itr that runs through entire array, pIndex running from start to eventual pIndex location
//pIndex increments forward after it finds smaller than pivot member and swaps it to pIndex current location
//Smaller members are swapped to the front/right of pivot's (eventual) location (pIndex)
int partition(int *A, int start, int end) {		//start and end are i positions, not size related
	int pivot = A[end];							//we're using rightmost member as pivot
	int pIndex = start;							//pIndex keeps place of where you're swapping in elements smaller than pivot
	for (int i = start; i < end; i++) {
		if (A[i] < pivot) {
			swap(A[i], A[pIndex]);
			pIndex++;
		}
	}
	swap(A[end], A[pIndex]);
	return pIndex;
}

void quickSort(int *A, int start, int end) {
	if (start == end) {}						//base case: we don't want return anything because we are sorting in place
	if (start < end) {							//we want to stop at start==end (when array is size 1), so we stop recursing right before
		int pIndex = partition(A, start, end);
		quickSort(A, start, pIndex-1);			//sort left of pIndex
		quickSort(A, pIndex+1, end);			//sort right of pIndex
	}
}

void quickSortSol() {
	cout << "quickSort, right member pivot: "<<endl;
	int arr[] = { 1,5,9, 10, 2, 6,3,2,7, 4 };
	quickSort(arr, 0, 9);
	for (auto itr : arr) {
		cout << itr << " ";
	}
	cout << endl;
}


//use rand() to choose pivot instead of far right member
int partitionRand(int *A, int start, int end) {		//start and end are i positions, not size related
	srand(time(NULL));								//seed random
	int randMember = start + rand() % (end - start + 1);
	//cout << randMember << " ";
	int pivot = A[randMember];
	swap (A[end], A[randMember]);

	int pIndex = start;								//pIndex keeps place of where you're swapping in elements smaller than pivot
	for (int i = start; i < end; i++) {
		if (A[i] < pivot) {
			swap(A[i], A[pIndex]);
			pIndex++;
		}
	}
	swap(A[end], A[pIndex]);
	//printArr(A, start, end);			//for the print statements, it only prints the left hand recursions. Why? How is it sorting without printing right?
	return pIndex;
}


void quickSortRand(int *A, int start, int end) {
	if (start < end) {								//we want to stop at start==end (when array is size 1), so we stop recursing right before
		printArr(A, start, end);
		int pIndex = partitionRand(A, start, end);

		cout << "sort left" << endl;
		quickSortRand(A, start, pIndex - 1);		//sort left of pIndex
		cout << "sort right" << endl;
		quickSortRand(A, pIndex + 1, end);			//sort right of pIndex
		printArr(A, start, end);
	}
}

void quickSortSolRand() {
	cout << "quickSort, random pivot: " << endl;
	int arr[] = { 1,5,9, 10, 2, 6,3,2,7, 4 };
	quickSortRand(arr, 0, 9);
	for (auto itr : arr) {
		cout << itr << " ";
	}
	cout << endl;
}



int main()
{
	quickSortSol();

	int run = 1;
	while (run == 1) {
		quickSortSolRand();
		cin >> run;
	}
	cin.get();

    return 0;
}

