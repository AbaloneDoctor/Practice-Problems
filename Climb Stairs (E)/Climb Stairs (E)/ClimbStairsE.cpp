// ClimbStairsE.cpp : Defines the entry point for the console application.
//	https://leetcode.com/problems/climbing-stairs/
// dynamic programming
// Can take 1 or 2 steps, how many different ways to climb N steps?
// explanation: Current step, for 1 or 2 steps, is all the ways possible to get to previous step + all ways possible 
//		to get to 2nd previous step. 
// Expanded: it's arbitrary for any N steps, just add the possibilites for those too

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//iterative tabulation, bottom up approach
int climbStairsTab(int n) {
	//base case: 0 stairs, 1 way, 1 stairs, 1 way. 2 stairs, 2 ways.
	//create array, set first 2 to 0 and 1
	//current step is equal to all the different ways to 1 step ago, and all the different ways to 2 steps ago
		//so add n-1, and n-2 together

	int paths[1000];
 	paths[0] = 1;
	paths[1] = 1;
	for (int i = 2; i <= n; i++) {
		paths[i] = paths[i - 1] + paths[i - 2];
	}
	return paths[n];
}

//recursive top down approach
int climbStairsRec(int n) {
	//base case: if n = 0 or 1 , return 1 way
	//else add up previous result and 2nd previous result
	if (n == 0 || n == 1) return 1;
	else {
		return climbStairsRec(n - 1) + climbStairsRec(n - 2);
	}
}

//Calculate the ways to reach endStep given allowed numbers of steps
//eg, how to get to 6th step, if you can take (1, 3, 5) steps
//idea: as you build array, you sum all paths for each step increment for each array member
int climbStairsAny(int endStep, vector<int> numSteps) {		
	//cases:
		//pattern: take all of previous, append -1 step, then -3 step, then -5 step IF ABLE. Eg, 4 can't append -5
		// 0 = 1, 1 = 1, 2 = 1 : (1,1), 3 = 2 : (1,1,1) | (3), 4 = 3 : (1,1,1,1) (1,3) | (3,1) , 
		//5 = 5 (1,1,1,1,1) (1,1,3) (1,3,1) | (3,1,1) | (5), 
		//6 = 8 (1,1,1,1,1,1) (1,1,1,3) (1,1,3,1) (1,3,1,1) (1,5) | (3,1,1,1) (3,3) | (5,1) 
		//pattern:	-1 | -3 | -5

	int paths[1000];
	paths[0] = 1;

	for (int i = 1; i <= endStep; i++) {
		int totalPaths = 0;
		int itr = 0;
		//for each step number
		// eg for each {1,3,5}
		for (int j : numSteps) {
			// eg i = 4, will loop 4-(1), then 4-(3), then break because 4-(5) is illegal
			if (i < numSteps[itr]) break;
			//if (i == numSteps[itr]) itr++;
			itr++;
			totalPaths += paths[i - j];
		}
		paths[i] = totalPaths;
	}
	return paths[endStep];
}


int main()
{	
	int res1 = climbStairsTab(3);
	int res2 = climbStairsRec(3);
	
	//customized steps (steps in form of array)
	//this one is same as the first two implementations
	int res3a = climbStairsAny(5, { 1,2 });		//should return 8
	//custom steps of 1,3,5
	int res3b = climbStairsAny(7, { 1,3,5 });	//should return 12

    return 0;
}

