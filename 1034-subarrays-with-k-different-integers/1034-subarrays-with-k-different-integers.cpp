class Solution {
public:
    long long find_Atmost_k_distinct(vector<int>& nums,int k)
    {
        long long ans=0;
        int left=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
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