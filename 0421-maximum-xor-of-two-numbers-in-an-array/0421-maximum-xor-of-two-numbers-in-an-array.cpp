struct Node{
    Node *links[2];
    bool containKey(int bit)
    {
        if(links[bit]!=nullptr) return true;
        return false;
    }
    void put(int bit,Node *node)
    {
        links[bit]=node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie{
private:
    Node *root;
public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containKey(bit)==false)
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int findMax(int num)
    {
        Node *node = root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containKey(!bit))
            {
                maxi=maxi|(1<<i);
                node=node->get(!bit); 
            }
            else
            {
                node=node->get(bit); 
            }
        }
        return maxi;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &i:nums)
        {
            trie.insert(i);
        }
        int ans=0;
        for(auto &i:nums)
        {
            ans=max(ans,trie.findMax(i));
        }
        return ans;
    }
};