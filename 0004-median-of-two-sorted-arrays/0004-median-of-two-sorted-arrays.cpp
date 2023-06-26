class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);//ensuring that binary search happens on minimum size array
        
        int low=0,high=n,medianPos=((m+n)+1)/2;
        while(low<=high) {
            int cut1 = (low+high)>>1;
            int cut2 = medianPos - cut1;
            int l1,l2,r1,r2;
            if(cut1==0) l1=INT_MIN;
            else l1= nums1[cut1-1];

            if(cut2==0) l2=INT_MIN;
            else l2= nums2[cut2-1];

            if(cut1==n) r1=INT_MAX;
            else r1= nums1[cut1];

            if(cut2==m) r2=INT_MAX;
            else r2= nums2[cut2];
            
            if(l1<=r2 && l2<=r1) {
                if((m+n)%2 != 0)
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    }
};