class Solution {
public:
    // int firstMissingPositive(vector<int>& nums) {
    //     unordered_set<int> s;
    //     for(auto i:nums)
    //     {
    //         if(i<=0) continue;
    //         s.insert(i);
    //     }
    //     int maxi=*max_element(nums.begin(),nums.end());
    //     if(maxi<=0) return 1;
    //     for(int i=1;i<=maxi;i++)
    //     {
    //         if(s.count(i)==0) return i;
    //     }
    //     return maxi+1;
    // }

    // int firstMissingPositive(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     int iter=0;
    //     while(iter<nums.size() && nums[iter]<=0)
    //     {
    //         iter++;
    //     }
    //     if(iter==nums.size()) return 1;
    //     int curr=1,prev=0;
    //     while(iter<nums.size())
    //     {
    //         if(prev==nums[iter])
    //         {
    //             iter++;
    //         }
    //         else
    //         {
    //             if(curr!=nums[iter])
    //             {
    //                 return curr;
    //             }
    //             prev=nums[iter];
    //             iter++;
    //             curr++;  
    //         }
    //     }
    //     return curr;
    // }


    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (nums[i] != (i+1))
                return i+1;
        return n+1;
    }
};