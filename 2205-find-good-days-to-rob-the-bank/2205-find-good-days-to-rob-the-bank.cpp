class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        // int s=0;
        // int maxi=0; 
        // while(s<n)
        // {
        //     int e=s;
        //     if(e+1<n && arr[e+1]<arr[e])
        //     {
        //         int cntl=0;
        //         while(e+1<n && arr[e+1]>arr[e]) 
        //         {
        //             e++;
        //             cntl++;
        //             if(cntl>=time)
        //             {

        //             }
        //         }
        //         //arr[e] is peak;
        //         if(e+1<n && arr[e+1]<arr[e])
        //         {
        //             while(e+1<n && arr[e+1]<arr[e]) e++;
        //             maxi=max(maxi,e-s+1);
        //         }
        //     }
        //     s=max(e,s+1);
        // }
        vector<int> preleft(n,0),preright(n,0);
        for(int i=1;i<n;i++)
        {
            if(security[i]<=security[i-1])
            {
                preleft[i]=1+preleft[i-1];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(security[i]<=security[i+1])
            {
                preright[i]=1+preright[i+1];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            // cout<<preleft[i]<<" "<<preright[i]<<endl;
            if(preleft[i]>=time && preright[i]>=time)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};