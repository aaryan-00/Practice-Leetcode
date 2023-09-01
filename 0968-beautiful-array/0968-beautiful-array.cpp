class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};

        while(ans.size()<n){
            vector< int> temp;
            for(int it: ans){
                if((it*2)-1 <= n) temp.push_back(it*2-1);
            }
            for(int it: ans){
                if((it*2) <= n) temp.push_back(it*2);
            }
            ans = temp;
        }
        return ans;
    }
};