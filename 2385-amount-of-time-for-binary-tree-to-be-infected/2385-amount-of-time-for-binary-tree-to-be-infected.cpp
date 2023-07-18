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
    TreeNode* begin;
    unordered_map<TreeNode*,TreeNode*> parent;
    void getParents(TreeNode* root,int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            if(curr->val==start)begin=curr;
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
    int getTimeToInfect()
    {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(begin);
        vis[begin]=true;
        int level=0;
        while(!q.empty())
        {
            level++;
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
        }
        return level-1;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        getParents(root,start);
        return getTimeToInfect();
    }
};