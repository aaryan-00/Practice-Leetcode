/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void getParents(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> getNodeAtDistanceK(TreeNode* target,int k)
    {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty() && level<k)
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* curr=q.front();
                q.pop();
            
                if(curr->left && vis[curr->left]==false)
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && vis[curr->right]==false)
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && vis[parent[curr]]==false)
                {
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
            level++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getParents(root);
        return getNodeAtDistanceK(target,k);
    }
};