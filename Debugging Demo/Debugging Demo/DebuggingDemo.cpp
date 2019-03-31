// DebuggingDemo.cpp : Defines the entry point for the console application.
//	https://www.gamefromscratch.com/post/2014/08/08/Debugging-101-tutorial-or-How-to-bring-sanity-to-an-insane-world.aspx

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//Important keys:
//	f9:				create/delete breakpoint
//	f10:			step over
//	f11:			step in
//	shift + f11:	step out 
//	shift + f9		QuickWatch 
//
//bookmark by clicking grey bar 
//breakpoints are saved on document


void stepIn( int *num ) {
	for (int i = 0; i < 5; i++) {	
		*num += 1;					//put conditional breakpoint here for when *num == 4
	}								//locals window will show local variables
}

void stepOver(int *num) {
	*num += 10;
}


void stack3() {						//Call stack: current layer is on top of call stack.
	cout << "end" << endl;			//stack3() -> stack2() - > stack1()
}

void stack2() {
	stack3();
}

void stack1() {						//when you are inside stack3(), stack1() will be 2 layers down in call stack
	stack2();
}

int add100(int num) {				//when called in quickwatch, will perform function and return a number
	num += 100;
	return num;
}

int main()
{
	int a = 0;						//breakpoint here, you can change 'a' value to anything, and it'll change for the runtime
	int *num;						//breakpoint condition x==0 here can trigger 
	num = &a;
	stepIn(num);
	stepOver(num);
	add100(a);						//shift+f9, quickWatch, can evaluate functions with return value:		
									//add100(a+2)	= 117	//a was originally 115

	stack1();

	cin.get();

    return 0;
}

