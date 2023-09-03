class Solution {
public:
const int m=1e9+7;

/* Iterative Function to calculate (x^y)%p
in O(log y) */
long long power(long long x, int y, int p)
{
    long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
// Returns n^(-1) mod p
long long modInverse(long long n, long p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
long long nCrModPFermat(long long n,
                                 long r, long p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}



    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> hashh(26,0);
        for(auto &i:s)
        {
            hashh[i-'a']++;
        }
        vector<int> temp;
        for(auto &i:hashh)
        {
            if(i!=0)
            {
                temp.push_back(i);
            }
        }
        if(temp.size()<k) return 0;
        sort(temp.begin(),temp.end(),greater<int>());
        unordered_map<int,int> mp;
        for(int i=0;i<temp.size();i++)
        {
            mp[temp[i]]++;
        }
        vector<pair<int,int>> final;
        for(auto i:mp)
        {
            final.push_back({i.first,i.second});
        }
        sort(final.rbegin(),final.rend());
        long long ans=1;
        for(int i=0;i<final.size() && k>0;i++)
        {
            if(final[i].second<=k)
            {
                long long alpha=power(final[i].first,final[i].second,m);
                alpha%=m;
                ans=(ans*alpha)%m;
                k-=final[i].second;
            }
            else
            {
                long long leli=final[i].second;
                long long ncrr=nCrModPFermat(leli,k,m)%m;
                long long curr=ncrr*power(final[i].first,k,m);
                curr%=m;
                ans=(ans*curr)%m;
                k=0;  
            }
        }
        return ans;
    }
};