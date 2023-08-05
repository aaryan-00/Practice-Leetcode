class Solution {
public:
    int getCount(int i)
    {
        if(i==0||i==1) return 1;
        int cnt=0;
        for(int curr=0;curr<i;curr++)
        {
            cnt+=getCount(curr)*getCount(i-curr-1);
        }
        // cout<<cnt<<endl;
        return cnt;
    }
    int numTrees(int n) {
        return getCount(n);
    }
};