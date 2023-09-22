class Solution {
public:
    // int getAns(vector<int>& target, vector<int>& arr,int i,int j)
    // {
    //     if(i==target.size()||j==arr.size()) return 0;
    //     int ans=0;
    //     if(target[i]==arr[j])
    //     {
    //         ans=max(ans,1+getAns(target,arr,i+1,j+1));
    //     }
    //     ans=max(ans,max(getAns(target,arr,i+1,j),getAns(target,arr,i,j+1)));
    //     return ans;
    // }
    int minOperations(vector<int>& target, vector<int>& arr) {
        // return target.size()-getAns(target,arr,0,0);
        unordered_map<int,int> mp;
        for(int i=0;i<target.size();i++)
        {
            mp[target[i]]=i;
        }
        vector<int> nums;
        for(auto &i:arr)
        {
            if(mp.find(i)!=mp.end())
            {
                nums.push_back(mp[i]);
            }
        }
        if(nums.size()==0) return target.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(temp.back()<nums[i])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return target.size()-temp.size();
    }
};