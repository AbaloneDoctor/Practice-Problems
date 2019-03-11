// InttoRoman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

//idea iterate through number, for each digit, put appropriate numeral
//Runs at O(N) size, N being the # of places in given number

string intToRoman(int num) {
	string romanNum;
	//divide by 10 until you reach 0. Runs N times, N = # of places in num
	int shrinkingNo = num;
	int places = 1;
	char oneAnalogue;
	char fiveAnalogue;
	char tenAnalogue;
	while (shrinkingNo > 0) {
		
		//cout << "digit: " << shrinkingNo % 10 << endl;	//gives number at each place

		int digit = shrinkingNo % 10;

		/*
		//NOTE: you cannot use relational operators (like > < == ) in switch statements. 
		//In this case we wanted to do a catchall for places > 4, and could'nt do it directly
		//BUT it can be done with a default case!!
		switch (places) {
		case 1:
			oneAnalogue = 'I';
			fiveAnalogue = 'V';
			break;
		//cases 2-3 here
		case 4:						//if you wanted to do a catchall for num>4 places, you would not be able to do that here
			oneAnalogue = 'M';
			fiveAnalogue = ' ';
			break;
		
		//ADD DEFAULT TO CATCH ALL (which is basically places > 4)
		default:
			oneAnalogue = 'M';
			fiveAnalogue = 'MMMMM';		//can't actually do that here directly, this is a char. You can do it through code tho
		}*/

		if(places == 1) {
			oneAnalogue = 'I';
			fiveAnalogue = 'V';
			tenAnalogue = 'X';
		}

		else if (places == 2) {
			oneAnalogue = 'X';
			fiveAnalogue = 'L';
			tenAnalogue = 'C';
		}

		else if (places == 3) {
			oneAnalogue = 'C';
			fiveAnalogue = 'D';
			tenAnalogue = 'M';
		}
		else if (places == 4) {
			oneAnalogue = 'M';
			fiveAnalogue = ' ';			//don't have to worry about this since input is <3999
			tenAnalogue = ' ';
		}

		if (digit <= 3) {
			for (int i = 0; i < digit; i++) {
				romanNum.insert(romanNum.begin(), oneAnalogue);
			}
		}
		else if (digit == 4) {			//HAVE TO PUSH IN REVERSE ORDER. INSERTING AT FRONT! SAME FOR digit<5 and 9!
			romanNum.insert(romanNum.begin(), fiveAnalogue);
			romanNum.insert(romanNum.begin(), oneAnalogue);
		}
		else if (digit == 5) {
				romanNum.insert(romanNum.begin(), fiveAnalogue); 			
		}
		else if ( 9 > digit && digit > 5 ) {				
			for (int i = 0; i < digit - 5; i++ ){
				romanNum.insert(romanNum.begin(), oneAnalogue);
			}
			romanNum.insert(romanNum.begin(), fiveAnalogue);
		}
		else if (digit == 9) {	
			romanNum.insert(romanNum.begin(), tenAnalogue);
			romanNum.insert(romanNum.begin(), oneAnalogue);
		}
		shrinkingNo /= 10;
		places++;
	}
	return romanNum;
}



int main()
{
	string num;
	while (num != "end" ) {
		cin >> num;

		for (auto it : num) {
			if (!isdigit(it)) {	//ends program if non-number is found
				return 0;
			}
		}

		int numInt = stoi(num);
		cout << intToRoman(numInt) << endl;
	}

	cin.get();

    return 0;
}
