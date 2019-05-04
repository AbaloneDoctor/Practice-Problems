// Factorial.cpp : Defines the entry point for the console application.
// Solve factorial, 3! = 3 * 2 * 1
//https://www.geeksforgeeks.org/solve-dynamic-programming-problem/
//https://www.geeksforgeeks.org/tabulation-vs-memoizatation/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//iterative
//bottom up approach
int factorial(int target) {
	int product = 1;
	for (int i = 1; i <= target; i++) {
		product *= i;
	}
	return product;
}

//tabulation: builds table as you go sequentially
//builds it linearly, bottom up
int factorialTabulation(int target) {
	int arr[10000];
	arr[0] = 1;
	for (int i = 1; i <= target; i++) {
		arr[i] = arr[i - 1] * i;
	}
	return arr[target];
}

//recursive 
//bottom up
int factorialRecursive(int target) {
	if (target == 0) {
		return 1;
	}
	else {
		return factorialRecursive(target - 1)*target;
	}
}

//Memoization: builds table irrespective to actual order
//recursive, exponential time
int factorialMemo(int target, vector<int> &arg ) {
	//assigns all 1000 members of vector to be -1
	if(arg.empty()) arg.assign(1000, -1);
	//ie base case
	if (target == 0) return 1;
	if (arg[target] == -1) {
		int nextTarget = target - 1;
		int res = target * factorialMemo(  nextTarget , arg);
		return res;
	} else //if (arg[target] != -1) 
		return arg[target];
	}

// int factorial
int main()
{
	int res = factorial(4);
	res = factorial(5);
	res = factorialTabulation(4);

	int res2 = factorialMemo(5, vector<int>() );

    return 0;
}

