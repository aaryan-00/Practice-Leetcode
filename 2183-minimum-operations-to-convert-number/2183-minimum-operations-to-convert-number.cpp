class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        unordered_set<int> s;
        q.push(start);
        s.insert(start);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int temp=q.front();
                q.pop();
                if(temp==goal) return level;
                if(temp>1000||temp<0) continue;
                for(int iter=0;iter<nums.size();iter++)
                {
                    int curr=temp-nums[iter];
                    if(curr==goal) return level+1;
                    if(curr>=0 && curr<=1000 && s.count(curr)==0)
                    {
                        q.push(curr);
                        s.insert(curr);
                    }
                    curr=temp+nums[iter];
                    if(curr==goal) return level+1;
                    if(curr>=0 && curr<=1000 && s.count(curr)==0)
                    {
                        q.push(curr);
                        s.insert(curr);
                    }
                    curr=temp^nums[iter];
                    if(curr==goal) return level+1;
                    if(curr>=0 && curr<=1000 && s.count(curr)==0)
                    {
                        q.push(curr);
                        s.insert(curr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};