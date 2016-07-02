#include <stdlib.h>
#include <vector>
#include <stack>
#include "tree.h"
using namespace std;

//Pre order traversal  non-recurive
//leetcode  144 Binary Tree Preorder Traversal
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ret;
	if (root == NULL) return ret;
	TreeNode* pTree = root;
	stack<TreeNode*> treeStack;

	while (!treeStack.empty()||pTree) {
	    if (pTree) {
	        ret.push_back(pTree->val);
	        treeStack.push(pTree);
	        pTree = pTree->left;
	    } else {
	        pTree = treeStack.top();
	        treeStack.pop();
	        pTree = pTree->right;
	    }
	}
	return ret;
}
