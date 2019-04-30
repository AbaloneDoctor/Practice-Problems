// ReverseStringsE.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/reverse-string/
//reverse string in place

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//using 2 ptrs to switch
//O(N) time complexity,  O(1) space complexity
void reverseString(vector<char>& s) {
	//2 ptrs, one at start one at end
	//while first ptr is smaller than last ptr
		//swap s[i++] with s[j--] 
	int i = 0;
	int j = s.size()-1;
	while (i < j) {
		swap(s[i++], s[j--]);
	}
}


//using stack
//doesn't use O(1) memory though
void reverseStringStack(vector<char>& s) {
	//for each letter in s, push into stack
	//then go through and top/pop back into s
	stack <char> stack;
	for (auto itr = s.begin(); itr != s.end(); ) {
		stack.push(*itr++);
		//s.erase(itr);
	}
	//this will refer to actual position in s if you use address
	for (char &itr : s) {
		itr = stack.top();
		stack.pop();
	}
	return;
}


//returning a range using iterators
string reverseStringVectorItr(string s) {		//"abcdefg"
	//return { s.end(), s.begin() };			//triggers "invalid iterator range"
	return { s.rbegin(), s.rend() };
	//return string(s.rbegin(), s.rend());		//same solution without string constructor
	//return { s.begin(), s.begin()+2 };		//returns "ab"
}

int main()
{
	vector<char> word = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	reverseString(word);
	reverseStringStack(word);

	string wordString(word.begin(), word.end());
	wordString = reverseStringVectorItr(wordString);

    return 0;
}

