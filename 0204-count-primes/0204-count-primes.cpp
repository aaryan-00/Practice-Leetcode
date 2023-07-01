class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n,1);
        int cnt=0;
        for(int p=2;p<n;p++)
        {
            if(primes[p])
            {
                cnt++;
                for(int i=p*2;i<n;i+=p)
                {
                    primes[i]=0;
                }
            }
        }


        //or
        // for(int p=2;p*p<n;p++)
        // {
        //     if(primes[p])
        //     {
        //         cnt++;
        //         for(int i=p*p;i<n;i+=p)
        //         {
        //             primes[i]=0;
        //         }
        //     }
        // }
        // int cnt=0;
        // for(int i=2;i<n;i++)
        // {
        //     if(primes[i])
        //     {
        //         cnt++;
        //     }
        // }
        return cnt;
    }
};