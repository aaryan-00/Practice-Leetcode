class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,ans=0,mini=min(height[l],height[r]);
        while(l<r)
        {
            if(height[l]<mini)
            {
                ans+=mini-height[l];
                l++;
            }
            else if(mini>height[r])
            {
                ans+=mini-height[r];
                r--;
            }
            else
            {
                if(height[l]<height[r])
                {
                    mini=height[l];
                    l++;
                }
                else
                {
                    mini=height[r];
                    r--;
                }
            }
        }
        return ans;
    }
};