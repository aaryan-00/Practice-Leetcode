class Solution {
public:
    long k;
    long dp[10][10][10][2][2][20];
    // int solve(string &num,int pos,bool tight,bool isLeading,int cntEven,int cntOdd,int rem)
    int solve(vector<int> &num,int pos,bool tight,bool isLeading,int cntEven,int cntOdd,int rem)
    {
        if(pos==num.size())
        {
            if(cntEven==cntOdd && rem==0) return 1;
            else return 0;
        }
        if(dp[pos][cntEven][cntOdd][tight][isLeading][rem]!=-1) return dp[pos][cntEven][cntOdd][tight][isLeading][rem];
        int ub = 9;
        if (tight == 1)
        {
            // ub = num[pos]-'0';
            ub = num[pos];
        }
        long ans=0;
        for(int dig=0;dig<=ub;dig++)
        {
            if(isLeading && dig==0)
            {
                ans+=solve(num,pos+1,0,1,0,0,0);
            }
            else
            {
                ans+=solve(num,pos+1,tight&(dig==ub),0,cntEven+(dig%2==0),cntOdd+(dig%2!=0),(rem*10+dig)%k);
            }
        }
        return dp[pos][cntEven][cntOdd][tight][isLeading][rem]=ans;
    }
    int getAns(int n)
    {
        // string num=to_string(n);
        vector<int> num;
        while(n>0)
        {
            num.push_back(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        return solve(num,0,1,1,0,0,0);
    }
    int numberOfBeautifulIntegers(int low, int high, int K) {
        k=K;
        low--;
        return getAns(high)-getAns(low);
    }
};