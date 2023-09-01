class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> ans;
        int n=a.size(),m=b.size(),i=0,j=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                if(ans.size()==0 || ans.back()!=a[i])
                {
                    ans.push_back(a[i]);
                }
                i++;j++;
            }
            else if(a[i]<b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};