class Solution {
public:
int ans=0;
    void getmaxi(vector<int> &arr,int left,int right)
    {
        left--,right++;
        int lcnt=0,rcnt=0;
        while(left>=0)
        {
            if(arr[left]<arr[left+1])
            {
                left--;
                lcnt++;
            }
            else break;
        }
        while(right<arr.size())
        {
            if(arr[right]<arr[right-1])
            {
                right++;
                rcnt++;
            }
            else break;
        }
        if(lcnt && rcnt)
        {
            
            ans=max(ans,lcnt+rcnt+1);
        }
    }
    // void getmaxieven(vector<int> &arr,int left,int right)
    // {
    //     int one=left ,two=right;
    //     left--,right++;
    //     int cnt=2;
    //     while(left>=0 && right<arr.size())
    //     {
    //         if(arr[left]<arr[left+1] && arr[right]<arr[right-1])
    //         {
    //             left--,right++;
    //             cnt+=2;
    //         }
    //         else break;
    //     }
    //     if(cnt>2)
    //     {
    //         ans=max(ans,cnt);
    //     }
    // }
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        // cout<<n<<endl;
        for(int i=0;i<n;i++)
        {
            getmaxi(arr,i,i);
            // if(arr[i]!=arr[i+1])
            //     getmaxi(arr,i,i+1);
        }
        return ans;
    }
};