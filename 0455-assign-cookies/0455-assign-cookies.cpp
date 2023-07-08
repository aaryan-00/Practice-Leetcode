class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,iter=0;
        while(i<g.size() && iter<s.size())
        {
            if(g[i]<=s[iter])
            {
                i++;
                iter++;
            }
            else if(g[i]>s[iter])
            {
                iter++;
            }
        }
        return i;

    }
};