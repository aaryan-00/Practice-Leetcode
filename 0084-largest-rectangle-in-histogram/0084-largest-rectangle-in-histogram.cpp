class Solution {
public:
    // using one stack and no vector(i.e. one pass)
    // int largestRectangleArea(vector<int>& heights) {
    //     stack<int> s;
    //     int n=heights.size();
    //     int ans=0;
    //     for(int i=0;i<=n;i++)
    //     {
    //         while(!s.empty() && (i==n || heights[s.top()]>=heights[i]))
    //         {
    //             int height=heights[s.top()];
    //             s.pop();
    //             int width;
    //             if(s.empty()) width=i;
    //             else width=i-s.top()-1;
    //             ans=max(ans,height*width);
    //         }
    //         s.push(i);
    //     }
    //     return ans;
    // }

    //using 2 vector and stack two times (i.e. two pass)
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right_min(n);
        vector<int> left_min(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty()) left_min[i]=0;
            else left_min[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty()) 
        {
            s.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty()) right_min[i]=n-1;
            else right_min[i]=s.top()-1;
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(right_min[i]-left_min[i]+1)*heights[i]);
        }
        return ans;
    }
};