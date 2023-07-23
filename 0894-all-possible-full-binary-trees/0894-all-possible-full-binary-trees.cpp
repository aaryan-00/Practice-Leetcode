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
    // unordered_map<int,vector<TreeNode*>> memo;
    // vector<TreeNode*> allPossibleFBT(int n) {
    //     if(n%2==0) return {};
    //     if(n==1) return {new TreeNode()};
    //     if(memo[n].size()!=0) return memo[n];
    //     vector<TreeNode*> res;
    //     for(int i=1;i<n;i+=2)
    //     {
    //         vector<TreeNode*> left=allPossibleFBT(i);
    //         vector<TreeNode*> right=allPossibleFBT(n-i-1);

    //         for(auto l:left)
    //         {
    //             for(auto r:right)
    //             {
    //                 TreeNode* root=new TreeNode();
    //                 root->left=l;
    //                 root->right=r;
    //                 res.push_back(root);
    //             }
    //         }

    //     }
    //     return memo[n]=res;
    // }

    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        vector<vector<TreeNode*>> dp(n+1);

        dp[1].push_back(new TreeNode());
        for(int i=3;i<=n;i+=2)
        {
            for(int inner=1;inner<i-1;inner+=2)
            {
                vector<TreeNode*> left=dp[inner];
                vector<TreeNode*> right=dp[i-inner-1];
                for(auto l:left)
                {
                    for(auto r:right)
                    {
                        TreeNode* root=new TreeNode();
                        root->left=l;
                        root->right=r;
                        dp[i].push_back(root);
                    }
                }

            }

        }
        return dp[n];
    }
};