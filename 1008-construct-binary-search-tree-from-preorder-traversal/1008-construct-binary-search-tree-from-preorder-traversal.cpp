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
    TreeNode* create(vector<int>& preorder, int start,int end)
    {
        if(start>end)
        {
            return nullptr;
        }
        if(start==end)
        {
            return new TreeNode(preorder[start]);
        }
    
        TreeNode* root=new TreeNode(preorder[start]);
        int i=start;
        while(i<=end && preorder[start]>=preorder[i])
        {
            i++;
        }
        root->left=create(preorder,start+1,i-1);
        root->right=create(preorder,i,end);
        

        // int index=-1;
        // for(int i=start+1;i<=end;i++)
        // {
        //     if(preorder[start]>preorder[i])
        //     {
        //         index=i;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // if(index!=-1)
        // {
        //     root->left=create(preorder,start+1,index);
        //     root->right=create(preorder,index+1,end);
        // }
        // else
        // {
        //     root->right=create(preorder,start+1,end);
        // }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder,0,preorder.size()-1);
    }
};