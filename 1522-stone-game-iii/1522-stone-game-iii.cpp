// class Solution {
// public:
//     int dp[50001][2];
//     int getAns(vector<int> &piles,int ind,bool alice)
//     {
//         int n=piles.size();
//         if(ind==n) return 0;
//         if(dp[ind][alice]!=-1) return dp[ind][alice];
//         if(alice)
//         {
//             int currSum=0,ans=INT_MIN;
//             for(int x=1;x<=min(3,n-ind);x++)
//             {
//                 currSum+=piles[x+ind-1];
//                 ans=max(ans,currSum+getAns(piles,ind+x,!alice));
//             }
//             return dp[ind][alice]=ans;

//         }
//         int currSum=0,ans=INT_MAX;
//         for(int x=1;x<=min(3,n-ind);x++)
//         {
//             currSum+=piles[x+ind-1];
//             ans=min(ans,getAns(piles,ind+x,!alice));
//         }
//         return dp[ind][alice]=ans;
//     }
//     string stoneGameIII(vector<int>& stoneValue) {
//         memset(dp,-1,sizeof(dp));
//         int total=0;
//         for(auto i:stoneValue)
//         {
//             total+=i;
//         }
//         int alice= getAns(stoneValue,0,1),bob=total-alice;
//         if(alice>bob) return "Alice";
//         if(bob>alice) return "Bob";
//         return "Tie";
//     }
// };

class Solution {
    int dp[50001];
    int helper(vector<int>& s,int i){
        if(i>s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        else{
            int ans=INT_MIN;
            ans=max(ans,s[i]-helper(s,i+1));
            if(i+1<s.size())ans=max(ans,s[i]+s[i+1]-helper(s,i+2));
            if(i+2<s.size())ans=max(ans,s[i]+s[i+1]+s[i+2]-helper(s,i+3));
            return dp[i]=ans;
        }
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        for(int i=0;i<stoneValue.size();i++) dp[i]=-1;
        int Alice=helper(stoneValue,0);
        if(Alice>0) return "Alice";
        else if(Alice<0) return "Bob";
        return "Tie";
    }
};