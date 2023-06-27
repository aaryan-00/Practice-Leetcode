class Solution {
public:
    bool rotateString(string s, string goal) {
        // char pivot=goal[0];
        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i]==pivot)
        //     {
        //         string curr="";
        //         curr+=s.substr(i)+s.substr(0,i);
        //         // cout<<curr<<endl;
        //         if(curr==goal) return true;
        //     }
        // }
        // return false;

        return s.size()==goal.size() && (s+s).find(goal)!=string::npos;
    }
};