/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int moves;
    int getAns(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getAns(root->left), right = getAns(root->right);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        moves=0;
        getAns(root);
        return moves;
    }
};