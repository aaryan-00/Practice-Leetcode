class Solution {
public:
    long long find_Atmost_k_distinct(vector<int>& nums,int k)
    {
        long long ans=0;
        int left=0;
        int cnt=0;
        unordered_map<int,int> mp;
        // vector<long long> mp(2e4,0);
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            // if(mp[nums[i]]==1) cnt++;
            
            while(mp.size()>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=i-left+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find_Atmost_k_distinct(nums,k)-find_Atmost_k_distinct(nums,k-1);
    }
};