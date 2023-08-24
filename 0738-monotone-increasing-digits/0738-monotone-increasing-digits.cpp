class Solution {
public:
    // int monotoneIncreasingDigits(int n) {
    //     if(n==0) return 0;
    //     vector<int> ans;
    //     int all=n;
    //     while(n>0)
    //     {
    //         int curr=n%10;
    //         ans.push_back(curr);
    //         n/=10;
    //     }
    //     reverse(ans.begin(),ans.end());
    //     int i=0;
    //     for(;i<ans.size()-1;)
    //     {
    //         if(ans[i]>ans[i+1])
    //         {
    //             break;
    //         }
    //         else if(ans[i]==ans[i+1])
    //         {
    //             int j=i;
    //             while(j<ans.size() && ans[j]==ans[i])
    //             {
    //                 j++;
    //             }
    //             if(j==ans.size())
    //             {
    //                 i=j;
    //                 continue;
    //             }
    //             if(ans[i]>ans[j])
    //             {
    //                 break;
    //             }
    //             i=j;
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }
    //     int res=0;
    //     if(i==ans.size()-1) return all;
    //     for(int j=0;j<ans.size();j++)
    //     {
    //         if(j<i) res=res*10+ans[j];
    //         else if(i==j) res=res*10+ans[j]-1;
    //         else res=res*10+9;
    //     }
    //     return res;
    // }

    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 1;
        int n = s.size();
        while(i < n && s[i] >= s[i - 1]) i++;
        if( i < n)
        while(i > 0 && s[i - 1] > s[i]){
            i--;
            s[i]--;
        }
        for(int j = i + 1; j < n; j++)s[j] = '9';
        return stoi(s);
   }
};