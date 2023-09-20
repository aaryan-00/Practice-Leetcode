class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> preleft(n,1),preright(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                preleft[i]=1+preleft[i-1];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
            {
                preright[i]=1+preright[i+1];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            cout<<preleft[i]<<" "<<preright[i]<<endl;
            if(i<k||i+k>=n) continue;
            
            if(preleft[i-1]>=k && preright[i+1]>=k)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};