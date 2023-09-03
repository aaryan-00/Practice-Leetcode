class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto &i:wordList)
        {
            mp[i]++;
        }
        queue<pair<string,string>> q;
        q.push({beginWord,""});
        int level=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string curr=q.front().first;
                string prev=q.front().second;
                q.pop();
                if(curr==endWord) return level;
                for(int i=0;i<curr.size();i++)
                {
                    for(char j='a';j<='z';j++)
                    {
                        string temp=curr;
                        temp[i]=j;
                        // cout<<temp<<endl;
                        if(temp!=curr && temp!=prev && mp.find(temp)!=mp.end())
                        {
                            mp.erase(temp);
                            q.push({temp,curr});
                        }
                    }
                }
            }
            level++;
        }
        return 0;
        
    }
};