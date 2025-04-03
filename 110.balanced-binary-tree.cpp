/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <cmath>
#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
public:
    int height(TreeNode* n, bool& balanced)
    {
        if (!n)
            return 0;
        else
        {
            int hl = height(n->left, balanced), hr = height(n->right, balanced);
            if (abs(hl - hr) > 1)
                balanced = false;
            return max(hl, hr) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        return !root || (abs(height(root->left, balanced) - height(root->right, balanced)) <= 1 && balanced);
    }
};
// @lc code=end

