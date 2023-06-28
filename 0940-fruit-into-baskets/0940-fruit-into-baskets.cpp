class Solution {
public:
    // int totalFruit(vector<int>& fruits) {
    //     int ans=0;
    //     int left=0;
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<fruits.size();i++)
    //     {
    //         mp[fruits[i]]++;
    //         while(mp.size()>2)
    //         {
    //             mp[fruits[left]]--;
    //             if(mp[fruits[left]]==0)
    //             {
    //                 mp.erase(fruits[left]);
    //             }
    //             left++;
    //         }
    //         ans=max(ans,i-left+1);
    //     }    
    //     return ans;
    // }

    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        vector<int> hashh(n+1,0);
        int ans=0,left=0,cnt=0;
        for(int i=0;i<fruits.size();i++)
        {
            hashh[fruits[i]]++;
            if(hashh[fruits[i]]==1) cnt++;
            while(cnt>2)
            {
                hashh[fruits[left]]--;
                if(hashh[fruits[left]]==0)
                {
                    cnt--;
                }
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};