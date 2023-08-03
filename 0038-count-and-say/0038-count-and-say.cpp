class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        int i=2;
        while(i<=n)
        {
            string curr="";
            int j=ans.size()-1;
            while(j>=0)
            {
                char temp=ans[j];
                curr=ans[j]+curr;
                int cnt=0;
                while(j>=0 && ans[j]==temp)
                {
                    j--;
                    cnt++;
                }
                curr=char(cnt+'0')+curr;  

            }
            ans=curr;
            i++;
            
        }
        return ans; 
    }
};