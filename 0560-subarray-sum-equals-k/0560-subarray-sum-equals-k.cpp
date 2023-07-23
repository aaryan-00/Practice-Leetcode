class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int n = nums.size(); 
        
    //     int prefix[n]; 
        
    //     prefix[0] = nums[0]; 
    //     for(int i = 1; i < n; i++)
    //     {
    //         prefix[i] = nums[i] + prefix[i - 1];
    //     }
    //     unordered_map<int,int> mp;
    //     int ans = 0; 
        
    //     // for(int i = 0; i < n; i++)
    //     // {
    //     //     if(prefix[i] == k) ans++;
    //     //     ans += mp[prefix[i] - k];
    //     //     mp[prefix[i]]++;
    //     // }

    //     mp[0]=1;
    //     for(int i = 0; i < n; i++)
    //     {
    //         ans += mp[prefix[i] - k];
    //         mp[prefix[i]]++;
    //     }
        
    //     return ans;   
    // }


    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int,int> mp;
        int ans = 0,sum=0; 

        mp[0]=1;
        for(int i = 0; i < n; i++)
        {
            sum+=nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        
        return ans;

           
    }
};