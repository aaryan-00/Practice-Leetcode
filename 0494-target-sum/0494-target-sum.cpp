class Solution {
public:
    int recur(int ind,vector<int> &nums,int target,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(target==0 && nums[0]==0)
            {
                return 2;
            }
            else if(target==0||target==nums[0])
            {
                return 1;
            }
            else return 0;
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        //not taken
        int ntkn=recur(ind-1,nums,target,dp);
        //taken
        int tkn=0;
        if(nums[ind]<=target)
        {
            tkn=recur(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target]=tkn+ntkn;
    }
    int findTargetSumWays(vector<int>& num, int target) {
        int n=num.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=num[i];
        }
        int tar=sum-target;
        if(tar<0 || tar&1) return 0;
        tar/=2;
        // vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        // return recur(n-1,num,tar,dp);
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
        // if(num[0] == 0) dp[0][0] =2;
        // else
        // {
        //     for(int i=0;i<n;i++)
        //     {
        //         dp[i][0]=1;
        //     }
        //     if(num[0]<=tar && num[0]!=0)
        //     {
        //         dp[0][num[0]]=1;
        //     }
        // } 
        // if(num[0] == 0) dp[0][0] =2; // 2 cases -pick and not pick
        // else dp[0][0] = 1;  // 1 case - not pick

        // if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        if(num[0]<=tar)
        {
            dp[0][num[0]]=1;
        }
        if(num[0]==0)
        {
            dp[0][0]=2;
        }
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 0; target<=tar; target++){
                
                int notTaken = dp[ind-1][target];
        
                int taken = 0;
                    if(num[ind]<=target)
                        taken = dp[ind-1][target-num[ind]];
            
                dp[ind][target]= (notTaken + taken);
            }
        }
        return dp[n-1][tar];
    }
};