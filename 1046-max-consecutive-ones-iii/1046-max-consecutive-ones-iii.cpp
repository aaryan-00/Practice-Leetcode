class Solution {
public:
    //using vector
    // int longestOnes(vector<int>& nums, int k) {
    //     vector<int> pos;
    //     int ans=0;
    //     int cnt=0;
    //     int start=0;
    //     int iter=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]==0)
    //         {
    //             pos.push_back(i);
    //             cnt++;
    //         }
    //         if(cnt>k)
    //         {
    //             start=pos[iter]+1;
    //             iter++;
    //             cnt--;
    //         }
    //         ans=max(ans,i-start+1);
    //     }
    //     return ans;
    // }


    //using pq
    // int longestOnes(vector<int>& nums, int k) {
    //     priority_queue<int,vector<int>,greater<int>> pq;
    //     int ans=0;
    //     int cnt=0;
    //     int start=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]==0)
    //         {
    //             pq.push(i);
    //             cnt++;
    //         }
    //         if(cnt>k)
    //         {
    //             start=pq.top()+1;
    //             pq.pop();
    //             cnt--;
    //         }
    //         ans=max(ans,i-start+1);
    //     }
    //     return ans;
    // }

    //normal
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int cnt=0;
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cnt++;
            }
            if(cnt>k)
            {
                while(cnt!=k)
                {
                    if(nums[start]==0) cnt--;
                    start++;
                }
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }




};