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
    
    vector<TreeNode*> getTree(int low,int high)
    {
        vector<TreeNode*> ans;
        if(low>high) return {nullptr};
        for(int curr=low;curr<=high;curr++)
        {
            vector<TreeNode*> left=getTree(low,curr-1);
            vector<TreeNode*> right=getTree(curr+1,high);
            for(auto i:left)
            {
                for(auto j:right)
                {
                    TreeNode* root=new TreeNode(curr);
                    root->left=i;
                    root->right=j;
                    ans.push_back(root);
                }
            }
        }
        return ans;

    }
    vector<TreeNode*> generateTrees(int n) {
        return getTree(1,n);
    }
};