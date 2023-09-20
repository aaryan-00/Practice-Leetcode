class Solution {
public:
// int ans=0;
//     void getmaxi(vector<int> &arr,int left,int right)
//     {
//         left--,right++;
//         int lcnt=0,rcnt=0;
//         while(left>=0)
//         {
//             if(arr[left]<arr[left+1])
//             {
//                 left--;
//                 lcnt++;
//             }
//             else break;
//         }
//         while(right<arr.size())
//         {
//             if(arr[right]<arr[right-1])
//             {
//                 right++;
//                 rcnt++;
//             }
//             else break;
//         }
//         if(lcnt && rcnt)
//         {
            
//             ans=max(ans,lcnt+rcnt+1);
//         }
//     }

    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        // for(int i=0;i<n;i++)
        // {
        //     getmaxi(arr,i,i);
        // }
        // return ans;

        int s=0,e;
        int maxi=0;
        while(s<n)
        {
            e=s;
            if(e+1<n && arr[e+1]>arr[e])
            {
                while(e+1<n && arr[e+1]>arr[e]) e++;
                //arr[e] is peak;
                if(e+1<n && arr[e+1]<arr[e])
                {
                    while(e+1<n && arr[e+1]<arr[e]) e++;
                    maxi=max(maxi,e-s+1);
                }
            }
            s=max(e,s+1);
        }
        return maxi;
    }
};