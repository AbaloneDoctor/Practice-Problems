// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void insertionSort(int arr[], int n) {
	//for each member of arr
	//save current
	//compare if forward is lesser than current
	//if it is, move backward, shifting all of them forward 1 until you find something smaller
	int curr;
	int j;
	for (int i = 0; i < n; i++) { 
		curr = arr[i];
		j = i-1;									//using 2 itrs, j and j-1
		while (j >= 0 && arr[j] > curr) {			//iterates toward arr[0] and stops when encounter a smaller value
			arr[j + 1] = arr[j];					//also won't start until j == 1, first iteration when i = 0; j = -1 and it properly won't loop
			j -= 1;
		}
		arr[j+1] = curr;							//because of j-=1, j will always be one more smaller
	}

}


//own implementation, functionally same as above
void insertionSort2(int arr[], int n) {
	int itr;									//starts from current i and iterates towards arr[0]
	int curr;									//current val we're placing
	for (int i = 0; i < n; i++) {
		curr = arr[i];
		itr = i; 
		while ( curr < arr[itr - 1] && i > 0) {	//while curr is smaller than 1 before
			arr[itr] = arr[itr - 1];
			itr--;
		}
		arr[itr] = curr;
	}
}

int main()
{
	int arr[] = { 1, 3, 4, 2, 6, 7, 9, 5 };
	insertionSort2(arr, 8);
    return 0;
}

