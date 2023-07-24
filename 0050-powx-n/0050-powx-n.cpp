class Solution {
public:
    // double getPow(double x,long n)
    // {
    //     if(n==0) return 1;
    //     if(n&1)
    //     {
    //         return x * myPow(x,n-1);
    //     }
    //     return myPow(x*x,n/2);
    // }
    // double myPow(double x, int n) {
    //     if(n==0) return 1;
    //     if(n<0) x=1/x;
    //     long num=abs(n);
    //     double ans=getPow(x,num);
    //     return ans;  
    // }


    // double myPow(double x, int n) {
    //     double res=1;
    //     while(n)
    //     {
    //         if(n&1)
    //         {
    //             if(n<0)
    //             {
    //                 res=res/x;
    //             }
    //             else
    //             {
    //                 res*=x;
    //             }
    //         }
    //         x*=x;
    //         n/=2;
    //     }
    //     return res; 
    // }


    double myPow(double x, int n) {
        if(n<0) x=1/x;
        double res=1;
        n=long(abs(n));
        while(n)
        {
            if(n&1)
            {
                res*=x;
            }
            x*=x;
            n/=2;
        }
        return res;
    }
};