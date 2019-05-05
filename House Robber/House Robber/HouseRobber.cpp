// HouseRobber.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/house-robber/
//given an array of nums, find largest amount of sum you can make without using nums adjacent to each other
//ie at least one space in between every num you choose

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

//helper function
int robRecurse( vector<int> nums, int itr, int max, int currMax ) {
	if (itr > nums.size() - 1) {
		//currMax += nums[itr];
		return (currMax >= max) ? currMax : max;
	}
	else {
		currMax += nums[itr];
		if (currMax > max) max = currMax;
		//1 space in between
		int res1 = robRecurse(nums, itr + 2, max, currMax);
		//2 spaces in between
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

//using dynamic programming
//09:06 PM - 05.03.19 : 
// https://leetcode.com/problems/house-robber/discuss/55838/DP-O(N)-time-O(1)-space-with-easy-to-understand-explanation
//int robDP(vector<int>& nums) {
//}

/*
CASES: 
	-current n, rob or not to rob:
		-rob n, then add to max of rob(n-2, n-3)
		-don't rob n, add to max of rob (n-1, n-2)

*/

int robDP(vector<int>& nums) {

	if (nums.empty()) {
		return 0;
	}

	vector<int> arr;
	unsigned int numsLength = nums.size();

	if (numsLength == 1) {
		return nums[0];
	}
	if (numsLength == 2) {
		return max(nums[0], nums[1]);
	}
	else {
		arr.push_back( nums[0]);
		arr.push_back( nums[1]);
		for (int i = 2; i < numsLength; i++) {
			int current = nums[i];
			//2 choices: take current + 1 before prev, or take prev and skip current
			int prevMax = max(current + arr[i - 2], arr[i - 1]);
			arr.push_back(max(prevMax, current));
		}
	}
	return arr[numsLength - 1];

}

int main()
{
	vector<int> arr = { 1,3,1, 9 , 1 , 9 , 1 , 9 };
	vector<int> arr3 = { 1,3,1, 9 , 1 , 50 , 19 , 9 };
	vector<int> arr2 = {9, 9, 9, 9, 9};
	int res = rob(arr3);
	res = robDP(arr3);
    return 0;
}

