// RobotReturntoOriginE.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/robot-return-to-origin/submissions/
// Robot moves in pattern of string of L, R, U, or D. Take string, return true or false if returns home

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//Use 2 counters to count U/D and L/R, should both equal 0 if back at home
//O(N) because iterates through argument once
bool judgeCircle(string moves) {
	int rCount = 0;
	int uCount = 0;
	for (char itr : moves) {
		if (itr == 'R') rCount++;
		else if (itr == 'L') rCount--;
		else if (itr == 'U') uCount++;
		else if (itr == 'D') uCount--;
	}
	if (rCount == 0 && uCount == 0) {
		return true;
	}
	else return false;
}

int main()
{	
	string arg = "RRLLUUDDD";
	bool ans = judgeCircle(arg);
    return 0;
}

