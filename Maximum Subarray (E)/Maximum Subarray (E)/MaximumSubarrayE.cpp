// MaximumSubarrayE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//O(2N) because you go through to find max sum, and then move towards middle from right and left to find largest subarray
int maxSubArray(vector<int>& nums) {
	//initial sum is all of the nums added
	//i increments from left, j decrements from right. Smaller one is moved first
	//check sum, if bigger, store location of i,j
	int sum = 0;
	for (int itr : nums) {
		sum += itr;
	}
	int maxSum = sum;
	
	int left = 0;
	int right = nums.size() - 1;
	int maxLeft = 0;
	int maxRight = right;

	while (left < right) {
		if (sum > maxSum) {
			maxSum = sum;
			maxLeft = left;
			maxRight = right;
		}
		if (nums[left] > nums[right]) {
			cout << nums[left] << " " << nums[right] << endl;
			sum -= nums[right];
			right--;
			cout << "right" << endl;
		}
		else {
			cout << nums[left] << " " << nums[right] << endl;
			sum -= nums[left];
			left++;
			cout << "left: "<< endl;
		}
	}
	vector<int> temp(nums.begin() + maxLeft, nums.begin()+maxRight+1);
	nums = temp;
	return maxSum;
}

//different method but still O(2N)
//idea: 1 ptr runs through to find largest sum subarray from start to right bounday
// second pointer runs through removing members to find complete largest
int maxSubArray2(vector<int>& nums) {
	int max = 0;
	int curMax = 0;
	int left = 0;
	int right = 0;

	for (int i = 0; i < nums.size(); i++) {
		curMax += nums[i];
		cout << "currMax: " << curMax <<endl;
		if (curMax > max) {
			max = curMax;
			right = i;
			cout << "new max and right: " << max << " " << right << endl;
		}
	}

	curMax = max;
	
	//for (int j = 0; j < nums.size(); j++) {			//doesn't work because you overshoot right, and start subtracting negatives from curMax that weren't in original curMax
	for (int j = 0; j < right; j++) {
		cout << "currMax2: " << curMax << endl;
		if (curMax > max) {
			max = curMax;
			left = j;
			cout << "new max and left: " << max << " " << left << endl;
		}
		curMax -= nums[j];
	}
	vector<int> temp(nums.begin() + left, nums.begin() + right + 1 );
	nums = temp;
	return max;
}
int main()
{
	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, -6, 20 };
	//cout << maxSubArray(arr) << endl;
	cout << maxSubArray2(arr) << endl;
	for (int itr : arr) {
		cout << itr << ", ";
	}

	cin.get();
    return 0;
}

