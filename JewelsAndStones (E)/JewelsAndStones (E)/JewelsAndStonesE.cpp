// JewelsAndStonesE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <algorithm>	//sort
#include <iostream>
#include <vector>

using namespace std;

//idea: sort s and j , 2 ptrs in each, jPtr is only incremented when sPtr finds match
//O(NlogN)	2*NlogN for sort, + N for iterating through S
int numJewelsInStones(string J, string S) {
	sort(J.begin(), J.end());
	sort(S.begin(), S.end());

	int jPtr = 0;													//keeps track of which letter you're comparing in J
	int jCount = 0;
	for (int sPtr = 0; sPtr < S.size(); sPtr++) {
		if (J[jPtr] == S[sPtr]) {
			jCount++;
			if (sPtr < S.size() - 1 && S[sPtr + 1] != J[jPtr]) {	//if s+1 is not at end and the next letter is different from J[jPtr], move jPtr
				jPtr++;
			}
		}
	}
	
	return jCount;
}


//idea: hash table like implementation using the letter int value as key, count instances 
// O(N), N to iterate through S + N to iterate through J
//put S chars into buckets, S[i]+0, increment hash[i]++
//go through J, add up numbers of hash[J[i]+0]
int numJewelsInStonesHash(string J, string S) {
	int hash[58] = { 0 };
	int jCount = 0;
	for (char itr : S) {
		hash[itr - 'A']++;						//increments itr's letter's position in hash table
	}
	for (char itr : J) {
		jCount += hash[itr - 'A'];				//adds on value stored at locartion of char itr in hash table
	}
	return jCount;
}



int main()
{
	int res = numJewelsInStones("aAb", "aAAbbbb");
	cout << res << endl;
	
	res = numJewelsInStones("zZd", "aAAbbbb");
	cout << res << endl;

	res = numJewelsInStonesHash("aAb", "aAAbbbb");
	cout << res << endl;
	res = numJewelsInStonesHash("zZd", "aAAbbbb");
	cout << res << endl;


	char temp = 'A' + 26;
	cout << temp<< endl;	//A-Z are 0-25, a-z are 32-57

	cin.get();

    return 0;
}

