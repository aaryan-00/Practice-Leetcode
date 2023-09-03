class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp;
        for(auto &i:wordList)
        {
            mp.insert(i);
        }
        queue<string> q;
        q.push(beginWord);
        int level=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string curr=q.front();
                q.pop();
                if(curr==endWord) return level;
                for(int i=0;i<curr.size();i++)
                {
                    for(char j='a';j<='z';j++)
                    {
                        string temp=curr;
                        temp[i]=j;
                        // cout<<temp<<endl;
                        if(temp!=curr && mp.count(temp))
                        {
                            mp.erase(temp);
                            q.push({temp});
                        }
                    }
                }
            }
            level++;
        }
        return 0;
        
    }
};