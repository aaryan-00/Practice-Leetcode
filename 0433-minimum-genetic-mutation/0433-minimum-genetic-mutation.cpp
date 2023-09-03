class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> mp;
        for(auto &i:bank)
        {
            mp.insert(i);
        }
        queue<string> q;
        q.push(startGene);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            // cout<<sz<<endl;
            while(sz--)
            {
                string curr=q.front();
                q.pop();
                if(curr==endGene) return level;
                for(int i=0;i<curr.size();i++)
                {
                    for(char j='A';j<='Z';j++)
                    {
                        string temp=curr;
                        temp[i]=j;
                        if(temp!=curr && mp.count(temp))
                        {
                            mp.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};