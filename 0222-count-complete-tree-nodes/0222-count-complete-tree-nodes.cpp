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
    int findHeightLeft(TreeNode* curr) {
        int height = 0; 
        while(curr) {
            height++; 
            curr = curr->left; 
        }
        return height; 
    }
    int findHeightRight(TreeNode* curr) {
        int height = 0; 
        while(curr) {
            height++; 
            curr = curr->right; 
        }
        return height; 
    }
        
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        
        return 1 + leftNodes + rightNodes; 
    }
};