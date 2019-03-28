// 4SumM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//brute force
//check for every possible combination of 4sums, to prevent dupes, check array with a map
vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {
	vector<vector<int>> res; 
	vector<int> temp;
	//unordered_map<vector<int>, bool> hash;
	return res;
} 

/*
recursive, go each num and branch to ohter options, removing them from array as you pass the updated array
minus current num from target
stop at 4 iterations (when ans is size==4), if target == 0, return vector


*/

//returns duplicates, same numbers, but different order
//vector<int> arg = { 1, 0, -1, 0, -2, 2 };
class Solution {
public:
	map<vector<int>, int> map;
	vector<vector<int>> recurse4Sum(vector<int> num, vector<int> ans, vector<vector<int>> &ansArr, int target) {
		if (ans.size() == 4) {
			cout << "4th" << endl;
			if (target == 0) {
				if (map.find(ans) == map.end()) {
					map.insert(pair<vector<int>, int>(ans, 1));
					ansArr.push_back(ans);
				}

			}
			ans = {};
			return ansArr;
		}
		else if (ans.size() < 4) {
			cout << "ans size: " << ans.size() << endl;
			for (int i = 0; i < num.size(); i++) {

				vector<int> tempNum = num;

				int tempInt = tempNum[i];
				vector<int> tempAns = ans;
				
				tempNum.erase(tempNum.begin() + i);
				tempAns.push_back(tempInt);

				
				//for (auto itr : tempNum) { cout << itr << " "; }
		
				//for (auto itr : tempAns) { cout << itr << " "; }

				recurse4Sum(tempNum, tempAns, ansArr, target - tempInt);
				
			}
			return ansArr;
		}

	}

	//idea: sort first, then compare
	//{-2, -1, 0 , 1 , 2 }
	//check smallest and largest,

};

int main()
{
	vector<int> arg = { 1, 0, -1, 0, -2, 2 };
	vector<int> ans = {};
	vector<vector<int>> ansArr = {};
	Solution sol;
	sol.recurse4Sum(arg, ans, ansArr, 0);

	int i = 0;
	for (auto vecItr : ansArr) {
		for (auto inItr : vecItr) {
			cout << inItr << " ";
		}
		i++;
		cout << endl;
	}
	cout << i << endl;
	cin.get();

    return 0;
}

