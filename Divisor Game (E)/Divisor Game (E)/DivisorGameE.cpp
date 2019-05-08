// DivisorGameE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

//x has to be a factor of N
//find factor, if it exists, 
//assuming optimal play, you would choose result leading to true
//note: if B is on 2, it's false for A
//1   2   3    4     5
//F   T   F  T/F(T)  F
//for 4, A chooses 1 or 2, meaning B gets 3 or 2
//if B gets 2, its F,
//if B gets 3, B chooses 1 -> 2, A chooses 1, T
//Is a num necesasrily the inverse result if B is on it? (yes because of 
//optimal play)

//efficient on memory use, but runs at N^2 time because you loop through each i's factors
bool divisorGame(int N) {

	vector<int> dp(N+1, 0);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	

	//you can OR all results of factors of current n, return true if there is a 
	//solution that gives you 1
	
	for (int i = 3; i <= N; i++) {
		bool orRes = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				//checks all factors of i for a true for A
				//[i-j] is B's result, so ![i-j] is A's
				orRes = orRes || !(dp[i - j]);
			}
		}
		dp[i] = orRes;
	}
	return dp[N];
}


//06:19 PM - 05.07.19 : IDEA: because A is playing optimally, she can guarantee that she gets 2 on even numbers
//eg, N = 8, factors: 1,2,4. A choose 4, N=4 B choose 1, N=3 A choose 1, N=2 B choose 1, N=1 A lose
//			A choose 1, N=7 B choose 1, N=6 A choose 1, N=5 B choose 1, N=4 A choose 1, N=3 B choose 1, N=2 A choose 1, A win
//eg, N = 10, factors, 1,2,4,5. A choose 5, N=5 B choose 1, N=4 A choose 1, N=3 B choose 1
//eg, N = 16, factors, 1,2,4,8. A choose 1, N=15 B choose 3, N=12 A choose 1
//eg, N = 24, facotrs, 1,2,3,4,6,8,12. A choose 3, N=21 (1,3,7) B chooses 7, N=14 A choose 7
// A can always choose largest odd prime number for initial divisor, forces it to be odd for B
// if it's odd for B, no matter what B chooses, it'll make it even and A can force B to have odd prime
//Because every even number contains factors 2 and an odd number (or just 1 if small enough)
//		Inverse is true: on Odds, B can guarantee A never gets even

bool divisorGameEfficient(int N) {
	return (N % 2 == 0) ? true : false;
}

int main()
{

	bool res = divisorGame(9);

    return 0;
}

