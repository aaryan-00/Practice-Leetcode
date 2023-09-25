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
    const int m=1e9+7;
    // long long tot_sum=0;
    unordered_map<TreeNode*,long long> mp;
    long long dfs(TreeNode* root)
    {
        if(root==nullptr) return 0;
        long long left=dfs(root->left);
        long long right=dfs(root->right);
        return mp[root]=(root->val+left+right);
    }
    // void totalSum(TreeNode* root)
    // {
    //     if(root==nullptr) return;
    //     totalSum(root->left);
    //     totalSum(root->right);
    //     tot_sum+=root->val;
    // }

    
    int maxProduct(TreeNode* root) {
        dfs(root);
        // for(auto i:mp)
        // {
        //     cout<<i.first->val<<" "<<i.second<<endl;
        // }
        long long maxi=0;
        long long total=mp[root];
        // cout<<total<<endl;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=nullptr)
            {
                long long one=mp[curr->left];
                long long other=total-one;
                long long temp=(one*other);
                maxi=max(maxi,temp);
                q.push(curr->left);
            }
            if(curr->right!=nullptr)
            {
                long long one=mp[curr->right];
                long long other=total-one;
                long long temp=(one*other);
                maxi=max(maxi,temp);
                q.push(curr->right);
            }
        }
        return maxi%m;
    }
};