// FindCommonCharactersE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<string> commonChars(vector<string>& A) {
	vector<vector<int>> hashArray;
	vector<int> finalCount;
	vector<string> res;
	for (string strItr : A) {
		vector<int> hash(26, 0);
		for (char charItr : strItr) {
			hash[charItr - 'a']++;
		}
		hashArray.push_back(hash);
	}

	finalCount = hashArray[0];

	for (int i = 0; i < hashArray.size(); i++) {
		for (int j = 0; j < hashArray[i].size(); j++) {
			if (finalCount[j] > hashArray[i][j]) { finalCount[j] = hashArray[i][j]; }
		}
	}

	for (int j = 0; j < finalCount.size(); j++) {
		for (int i = 0; i < finalCount[j]; i++) {
			char temp = j + 'a';
			string str = "";
			str += temp;
			res.push_back(str);
		}
	}
	return res;
}

int main()
{
	vector<string> arr = { "bella", "label", "roller" };
	vector<string> arr2 = { "october", "september", "november","december"  };
	vector<string> res = commonChars(arr2);

    return 0;
}

