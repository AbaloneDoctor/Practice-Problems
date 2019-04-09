// HouseRobber.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/house-robber/
//given an array of nums, find largest amount of sum you can make without using nums adjacent to each other
//ie at least one space in between every num you choose

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

int robRecurse( vector<int> nums, int itr, int max, int currMax ) {
	if (itr > nums.size() - 1) {
		//currMax += nums[itr];
		return (currMax >= max) ? currMax : max;
	}
	else {
		currMax += nums[itr];
		if (currMax > max) max = currMax;
		int res1 = robRecurse(nums, itr + 2, max, currMax);
		int res2 = robRecurse(nums, itr + 3, max, currMax);
		return (res1 >= res2) ? res1 : res2;
	}
}

int rob(vector<int>& nums) {
	int itr = 0;
	int max = 0;
	int currMax = 0;
	int res0 = 0;
	int res1 = 0; 
	res0 = robRecurse(nums, itr, max, currMax);			//start at first member
	res1 = robRecurse(nums, itr + 1, max, currMax);		//skip first 1 (you would never skip 2 AT THE START
	return (res0 >= res1) ? res0 : res1;				//because you would just include it) eg: 1, 1, 9
	
}

int main()
{
	vector<int> arr = { 1,3,1, 9 , 1 , 9 , 1 , 9 };
	vector<int> arr2 = {9, 9, 9, 9, 9};
	int res = rob(arr2);
	
    return 0;
}

