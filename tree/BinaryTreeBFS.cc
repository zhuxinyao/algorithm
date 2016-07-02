#include <stdlib.h>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;

//BFS non-recursive
//leetcode - 102.Binary Tree Level Order
vector<vector<int> > levelOrder(TreeNode* root) {
	vector<vector<int> > ret;
	if (root == NULL) return ret;
	queue<TreeNode*> treeQueue;
	treeQueue.push(root);
	
	while (!treeQueue.empty()) {
		
		ret.push_back(vector<int>());
		vector<int>& valList = ret.back();

		const int n = treeQueue.size();
		valList.reserve(n);
		for (int i = 0; i < n; i++) {
			const TreeNode* tmp = treeQueue.front();
			treeQueue.pop();

			//add val in tree node to the list
			//can be replaced by other operation
			valList.push_back(tmp->val);

			if (tmp->left) treeQueue.push(tmp->left);
			if (tmp->right) treeQueue.push(tmp->right);
		}
	}
	
	return ret;
}
