/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start

class Solution {
public:
    int b(TreeNode* root, int& ret) {
        if (!root)
            return 0;
        
        int lheight = b(root->left, ret);
        int rheight = b(root->right, ret);
        ret = max(ret, lheight + rheight);

        return max(lheight, rheight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        b(root, ret);
        return ret;
    }
};
// @lc code=end

