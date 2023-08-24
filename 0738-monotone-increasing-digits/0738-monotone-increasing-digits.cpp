class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n==0) return 0;
        vector<int> ans;
        int all=n;
        while(n>0)
        {
            int curr=n%10;
            ans.push_back(curr);
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        // for(auto i:ans)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int i=0;
        for(;i<ans.size()-1;)
        {
            if(ans[i]>ans[i+1])
            {
                break;
            }
            else if(ans[i]==ans[i+1])
            {
                int j=i;
                while(j<ans.size() && ans[j]==ans[i])
                {
                    j++;
                }
                if(j==ans.size())
                {
                    i=j;
                    continue;
                }
                if(ans[i]>ans[j])
                {
                    break;
                }
                i=j;
            }
            else
            {
                i++;
            }
        }
        // cout<<i<<endl;
        int res=0;
        if(i==ans.size()-1) return all;
        for(int j=0;j<ans.size();j++)
        {
            if(j<i) res=res*10+ans[j];
            else if(i==j) res=res*10+ans[j]-1;
            else res=res*10+9;
        }
        return res;

    }
};