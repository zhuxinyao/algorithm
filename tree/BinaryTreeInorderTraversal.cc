#include <stdlib.h>
#include <vector>
#include <stack>
#include "tree.h"
using namespace std;

//In order traversal  non-recurive
//leetcode 94 Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ret;
	if (root == NULL)
		return ret;

	TreeNode *pTree = root;
	stack<TreeNode*> treeStack;
	
	while (!treeStack.empty() || pTree) {
		if (pTree) {
		    treeStack.push(pTree);
		    pTree = pTree->left;
		} else {
		    pTree = treeStack.top();
		    treeStack.pop();
		    ret.push_back(pTree->val);
		    pTree = pTree->right;
		}
	}
	return ret;
}
