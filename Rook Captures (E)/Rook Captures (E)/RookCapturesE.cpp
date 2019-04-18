// RookCapturesE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
	
	int boardSize = board.size();
	int pCount = 0;
	int Ri = -1;
	int Rj = -1;
	int up = -1, down = -1, right = -1, left = -1;
	for ( int i = 0; i < boardSize; i++) {
		for ( int j = 0; j < boardSize; j++) {
			if (board[i][j] == 'R') {	
				Ri = i;
				Rj = j;
				up = i, down = i;
				left = j, right = j;
				break;
			}
		}
	}

	if (Ri >= 0 && Rj >= 0) {
		for (int k = 0; k < boardSize; k++) {
			if (up > 0) {
				up--;
				if (board[up][Rj] == 'p') pCount++;
				if (board[up][Rj] != '.') up = -1;
			}
			if (down < 8) {
				down++;
				if (board[down][Rj] == 'p') pCount++;
				if (board[down][Rj] != '.') down = 9;
			}
			if (left > 0) {
				left--;
				if (board[Ri][left] == 'p') pCount++;
				if (board[Ri][left] != '.') left = -1;
			}
			if (right < 8) {
				right++;
				if (board[Ri][right] == 'p') pCount++;
				if (board[Ri][right] != '.') right = 9;
			}
		}
	}

	return pCount;

}



int main()
{
	vector<vector<int>> vec = { {1,2}, {2,3}, {3,4} };
	vector<vector<char>> board = 
		{
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'p', '.', '.', '.', '.'},
		{'.', '.', '.', 'R', 'D', '.', '.', 'p'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', 'D', '.', '.', '.', '.'},
		{'.', '.', '.', 'p', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.'}
	};
	int res = numRookCaptures(board);
	return 0;
}

