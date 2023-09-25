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
    unordered_set<int> s;
    vector<TreeNode*> ans;
    void dfs(TreeNode* &root)
    {
        if(root==nullptr) return;
        dfs(root->left);
        dfs(root->right);
        if(s.count(root->val))
        {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root=nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &i:to_delete)
        {
            s.insert(i);
        }
        dfs(root);
        if(root) ans.push_back(root);
        return ans;
    }
};