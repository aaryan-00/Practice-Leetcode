class Solution {
public:
    // int dp[10001][101];
    // int getAns(int floor,int eggs)
    // {
    //     if(floor<=1) return floor;
    //     if(eggs==1) return floor;
    //     if(dp[floor][eggs]!=-1) return dp[floor][eggs];
    //     int mini=INT_MAX;
    //     for(int i=1;i<=floor;i++)
    //     {
    //         mini=min(mini,1+max(getAns(i-1,eggs-1),getAns(floor-i,eggs)));
    //     }
    //     return dp[floor][eggs]=mini;
    // }
    // int superEggDrop(int k, int n) {
    //     memset(dp,-1,sizeof(dp));
    //     return getAns(n,k);
    // }


    int dp[10001][101];
    int getAns(int floor,int eggs)
    {
        if(floor<=1) return floor;
        if(eggs==1) return floor;
        if(dp[floor][eggs]!=-1) return dp[floor][eggs];
        int mini=INT_MAX,l=1,h=floor,temp=0;
        while(l<=h)
        {
            int mid=(l+h)>>1;
            int bottom=getAns(mid-1,eggs-1);   //egg broken check for down floors of mid
            int up=getAns(floor-mid,eggs) ;   // not broken check for up floors of mid
            temp=1+max(bottom,up);          //store max of both 
            if(bottom<up){                  //since up is more than bottom and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //bottom > up so we will go downward 
            {    
                h=mid-1;
            }
            mini=min(mini,temp);               //store minimum attempts
        }
        return dp[floor][eggs]=mini;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(n,k);
    }
};