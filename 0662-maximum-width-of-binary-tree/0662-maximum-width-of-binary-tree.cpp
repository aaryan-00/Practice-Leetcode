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
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root,0});
        while (!q.empty())
        {
            int sz = q.size();
            int curMin = q.front().second;
            int leftLimit, rightLimit;
            for (int i = 1; i <= sz; i++)
            {
                long curr = q.front().second-curMin; // subtracted to prevent integer overflow
                TreeNode *temp = q.front().first;
                q.pop();
                if (i == 1)leftLimit = curr;
                if (i == sz)rightLimit = curr;
                if (temp->left)q.push({temp->left,curr * 2 + 1});
                if (temp->right)q.push({temp->right,curr * 2 + 2});
            }
            ans = max(ans, rightLimit - leftLimit + 1);
        }
        return ans;
    }
};