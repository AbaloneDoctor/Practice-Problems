// UniqueMorseCodeWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

/*
The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.

return unique transformations of each group of words
*/

using namespace std;

class Solution {
public:
	vector<string> morseCodeKey = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
									".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
									"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	//O(N), N is length of word
	//not necessary, written incase I wanted to use in other solutions
	string convertToMorse(string word) {
		string res = "";
		for (char itr : word) {
			int index = itr - 'a';
			res += morseCodeKey[index];
		}
		return res;
	}

	//O(N^2) for each word N = words.size(), you have to convert O(N)
	int uniqueMorseRepresentations(vector<string>& words) {
		map<string, int> hash;
		for (int i = 0; i < words.size(); i++) {
			string morseWord = "";
			//convertToMorse(words[i]);
			for (char itr : words[i]) {
				morseWord += morseCodeKey[itr - 'a'];
			}
			if (hash.find(morseWord) == hash.end()) {
				hash.insert(pair<string, int >(morseWord, 1));
			}
		}
		return hash.size();
	}
};

int main()
{
	Solution sol;
	vector<string> words = { "gin", "zen", "gig", "msg", "msg" };
	int res = sol.uniqueMorseRepresentations( words );
	cout << res;
	cin.get();
    return 0;
}

