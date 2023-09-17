class Solution {
public:
    bool isPoss(int mid,vector<int> & compo,int budget,vector<int> &stock,vector<int> &cost)
    {
        long temp=0;
        for(int i=0;i<stock.size();i++)
        {
            long req=compo[i]*(long)mid-stock[i];;
            long curr=max((long)0,req);
            temp+=curr*cost[i]; 
        }
        // cout<<mid<<" "<<temp<<endl;
        return temp<=budget;


    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans=0;
        for(int i=0;i<k;i++)
        {
            int curr=0;
            vector<int> compo=composition[i];
            int lo=0,hi=INT_MAX;
            while(lo<=hi)
            {
                int mid=(lo+hi)>>1;
                if(isPoss(mid,compo,budget,stock,cost))
                {
                    curr=mid;
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }

            }
            ans=max(ans,curr);
        }
        return ans;  

    }
};