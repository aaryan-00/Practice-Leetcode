#define ll long long
typedef vector<ll> vi;
class Solution {
public:
    ll dp[11][2][11];
    ll getAns(vi &num, ll pos, bool tight,int cnt)
    {
        if (pos == num.size())
        {
            return cnt;
        }
        if (dp[pos][tight][cnt] != -1)
        {
            return dp[pos][tight][cnt];
        }
        ll ans = 0;
        ll ub = 9;
        if (tight == 1)
        {
            ub = num[pos];
        }
        for (ll dig = 0; dig <= ub; dig++)
        {
            ans += getAns(num, pos + 1, tight & (dig == ub), cnt+(dig==1));
        }
        return dp[pos][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        vi curr;
        while (n > 0)
        {
            curr.push_back(n%10);
            n /= 10;
        }
        reverse(curr.begin(),curr.end());
        memset(dp, -1, sizeof(dp));
        return getAns(curr,0,1,0);
    }
};