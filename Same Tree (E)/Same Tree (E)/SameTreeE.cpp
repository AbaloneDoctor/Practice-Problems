// SameTreeE.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/same-tree/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

void printArray(vector<int> arr);
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//idea: backtrack through eaceh one, checking both tree nodes simultaneously
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		/*if (p->left == NULL && p->right == NULL &&			//when at leaf node, left and right don't exist!
			q->left == NULL && q->right == NULL &&				//similar to when itr == null, but you still check for itr->next
			p->val == q->val) return true;
			*/
		if (!p && !q) {				//if both are null (reached a leaf node)
			return true;
		}
		else if (p && q) {
			if (p->val == q->val) {
				bool res = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
				return res;
			}
			else {					
				return false;
			}
		}
		return false;				//cases where either p or q exists, but other doesn't
	}

	TreeNode* generateTree(vector<int> arr, int itr, TreeNode* node) {
		if (itr < arr.size() ) {
			TreeNode *newNode = new TreeNode(arr[itr]);
			node = newNode;
			//cout << "node val: " << node->val << endl;
		
			node->left = generateTree(arr, 2*itr+1, node->left);		//why do you have to do node->left =? 
			node->right = generateTree(arr, 2*itr+2, node->right);		//shouldn't it do it automatically?
		}
	
		return node;
	}

	//Prints tree in recursive/visit order
	void printTree( TreeNode* node) {
		//cout << "print" << endl;
		if (node){
			cout << node->val <<" ";
			printTree(node->left);
			printTree(node->right);
		}
		else {
			//cout << "empty" << endl;
		}
	}
	

	//EXTRA: visually prints tree
	void printTreeVisual( vector<int> arr ) {
		
		//using array length, you know how deep and wide the tree is, print according to that
		//height is equal to log2(array size rounded down)

		
		int height = log2(arr.size());
		height++;														//add 1 for head node
		float log2Height = log2(arr.size());							//check for when incomplete levels
		if (log2Height > height) height++;				
		cout << "height: " << height << endl;
		int leadingSpaces = (height/3)*pow(2,(height-1))+(height/3);	//basic idea is 2^height - 1 for leading spaces
		int intraSpaces = (height/3)*pow(2,height);						//2^height for spaces; higher level, more spaces
		
		int itr = 0;
		for (int i = 0; i < height; i++) {								//iterate through every level of tree
			for (int k = 0; k < leadingSpaces; k++) {					//print leading spaces
				cout << " ";		
			}
			leadingSpaces/=2;											//reduce leading spaces for next level
	
			for (int j = 0; j < pow(2, i); j++) {						//iterate through each node in level
				if (itr < arr.size()) {									//add leading zero for 0-9
					if (arr[itr] < 10)cout << " ";
					cout << arr[itr];
					for (int l = 0; l < intraSpaces; l++) cout << " ";	//spaces between nodes in rows
					itr++;												//iterates through array
				}
			}
			cout << endl;
			intraSpaces--;
			intraSpaces/=2 ;
		}
	}

};



void printArray(vector<int> arr) {
	for (int itr : arr) cout << itr << " ";
	cout << endl;
}


void printTreeDemo() {
	Solution sol;
	TreeNode* tree = new TreeNode(0);
	vector<int> arr = { 0,1,2,3,4,5,6 };
	vector<int> arr2 = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	vector<int> arr3 = { 
		1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1,1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1, 
		1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1,1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1 ,
		1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1,1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1 ,
		1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1,1, 1, 1, 1 , 1 , 1, 1, 1, 1 , 1 };

	sol.printTreeVisual(arr);
	cin.get();
}



void isSameTreeDEMO() {
	
	Solution sol;

	TreeNode *first = new TreeNode(0); 
	vector<int> firstTreeArr = { 0,1,2,3,4,5,6};
	first = sol.generateTree( firstTreeArr, 0, first);
	TreeNode *second = new TreeNode(1); 
	vector<int> secondTreeArr = { 0,1,2,3,4,5, 6 };
	second = sol.generateTree(secondTreeArr, 0, second);
	
	sol.printTreeVisual(firstTreeArr);
	cout << endl;
	sol.printTreeVisual(secondTreeArr);
	cout << endl;
	
	string res;
	(sol.isSameTree(first, second))? res = "true" : res = "false";
	cout << res;
	cin.get();

}

int main()
{
	isSameTreeDEMO();
	//printTreeDemo();
    return 0;
}

