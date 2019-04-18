// SearchBinaryTreeE.cpp : Defines the entry point for the console application.
// https://leetcode.com/problems/search-in-a-binary-search-tree/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right; 
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//O(logN) average
//simply recursively visit
TreeNode* searchBST(TreeNode* root, int val) {
	if (!root) return NULL;
	if (root->val == val) { return root; }
	else {
		if (root->val > val) {
			return searchBST(root->left, val);
		}
		else {
			return searchBST(root->right, val);
		}
		
	}
	return NULL; 
}

TreeNode* createTree(vector<int> A, int left, int right, TreeNode *curr ) {
	if ( left <= right) {
		int mid = ( right + left) / 2;
		curr = new TreeNode(A[mid]);
		cout << curr->val << endl;
		curr->left = createTree(A, left, mid - 1, curr->left);
		curr->right = createTree(A, mid + 1, right, curr->right);
		return curr;
	}
	return curr;
}

void recursivePrint( TreeNode *tree ) {
	if (tree) {
		cout << tree->val << " ";
		recursivePrint(tree->left);
		recursivePrint(tree->right);
	}
}

int main()
{
	
	vector<int> arr1 = { 0,1,2 };
	vector<int> arr = { 0, 1,2,3,4,5,6,7,8,9 };
	TreeNode *tree1 = new TreeNode(0);
	//tree1 = createTree(arr1, 0, 2, tree1);
	tree1 = createTree(arr, 0, 9, tree1);
	recursivePrint(tree1);

	bool res = false;
	if (searchBST(tree1, 10) != NULL) {
		res = true;
		cout << true;
	}

	TreeNode *tree = new TreeNode(7);
	tree->left = new TreeNode(4);

    return 0;
}

