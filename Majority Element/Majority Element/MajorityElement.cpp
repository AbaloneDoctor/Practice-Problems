// MajorityElement.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/majority-element/
//given an array, retun element that appears more than n/2 times
//https://leetcode.com/problems/majority-element/solution/
//implement sorting, divide and conquer, randomization methods

#include "stdafx.h"
#include <vector>

#define MAX 200

using namespace std;

int majorityElement(vector<int>& nums) {
	vector<int> table(MAX, 0);
	for (int i = 0; i < nums.size(); i++) {
		table[nums[i]]++;
		if (table[nums[i]] > nums.size() / 2) {
			return nums[i];
		}
	}
	return -1;
}


int main()
{

	vector<int> arr = { 3, 2, 7, 1, 2, 7, 3, 3, 3 , 0, 0 , 7, 7,7,7,7,7,7,7};
	int ans = majorityElement(arr);

    return 0;
}

