class Solution {
public:
    int getAns(int n,int ind)
    {
        if(n==0) return 1;
        int sum=0;
        for(int i=ind;i<=5;i++)
        {
            sum+=getAns(n-1,i);
        }
        return sum;
    }
    int countVowelStrings(int n) {
        if(n==1) return 5;
        return getAns(n,1);
    }
};