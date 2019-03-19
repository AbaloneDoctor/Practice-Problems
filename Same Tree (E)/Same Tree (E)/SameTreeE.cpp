// SameTreeE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

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
	
	//not working properly	FINISH THIS
	void printTreeInOrder(TreeNode* node) {
		if (!node) return;
		else {
			cout << node->val << " ";
			printTree(node->left);
			printTree(node->right);
		}
	}

};

void isSameTreeDEMO() {
	
	Solution sol;

	TreeNode *first = new TreeNode(0); 
	first = sol.generateTree({ 0,1,2,3,4,5,6, 7 }, 0, first);
	TreeNode *second = new TreeNode(1); 
	second = sol.generateTree({ 0,1,2,3,4,5, 7, 6 }, 0, second);
	
	sol.printTree(first);
	cout << endl;
	sol.printTree(second);
	cout << endl;
	cout << sol.isSameTree(first, second);

	cin.get();

}

int main()
{
	isSameTreeDEMO();
    return 0;
}

