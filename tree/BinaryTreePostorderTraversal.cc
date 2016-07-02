#include <stdlib.h>
#include <vector>
#include <stack>
#include <iostream>
#include "tree.h"
using namespace std;

//Post order traversal non-recurive
//leetcode - 145 Binary Tree Postorder Traversal
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ret;
	if (root == NULL) return ret;
	TreeNode* pTree = root;
	TreeNode* pLastView = NULL;
	stack<TreeNode*> treeStack;

	while (!treeStack.empty() || pTree) {
		if (pTree) {
			treeStack.push(pTree);
			pTree = pTree->left;
		} else {
			pTree = treeStack.top();
			if (pTree->right == NULL || pTree->right == pLastView) {
				ret.push_back(pTree->val);
				pLastView = pTree;
				treeStack.pop();
				pTree = NULL;
			} else {
				pTree = pTree->right;
			}
		}
	}
	return ret;
}
