#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include "tree.h"
using namespace std;

//convert a binary tree into string, and a string to a binary tree
//leetcode  297 Serialize and Deserialize Binary Tree
TreeNode* createTree(string& str, int* lpos) {
        if (*lpos >= str.length())
            return NULL;
        int rpos = str.find_first_of(',', *lpos);
        if (rpos == string::npos)
            rpos = str.length();
        const string &nodVal = str.substr(*lpos, rpos - *lpos);
        *lpos = rpos + 1;

        if (nodVal == "#")
            return NULL;
        TreeNode* root = new TreeNode(atoi(nodVal.c_str()));
		root->left = createTree(str, lpos);
        root->right = createTree(str, lpos);
        return root;
}

TreeNode* deserialize(string data) {
        int pos = 0;
        return createTree(data, &pos);
}

string serialize(TreeNode* root) {
        string ret;
        if (root == NULL)
            return ret;
        
        TreeNode* tmp = root;
        stack<TreeNode*> s;
        char buf[20];
        
        while (!s.empty() || tmp) {
            if (tmp) {
                s.push(tmp);
                sprintf(buf, "%d,", tmp->val);
                ret.append(buf);
                tmp = tmp->left;
            } else {
                tmp = s.top();
                s.pop();
                ret.append("#,");
                tmp = tmp->right;
            }
        }
        return ret;
}

int main() {
	string t("1,#,2,#,#");
	TreeNode* root = deserialize(t);
	string s = serialize(root);
	cout << s << endl; 
	
}
