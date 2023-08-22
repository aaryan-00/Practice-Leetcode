class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(!st.empty() && asteroids[i]<0)
            {
                while(!st.empty() && asteroids[i]<0)
                {
                    if(st.top()>0)
                    {
                        if(st.top()>abs(asteroids[i]))
                        {
                            break;
                        }
                        else if(st.top()<abs(asteroids[i]))
                        {
                            cout<<"cbjsb"<<endl;
                            st.pop();
                        }
                        else
                        {
                            st.pop();
                            break;
                        }
                    }
                    else
                    {
                        st.push(asteroids[i]);
                        break;
                    }
                    if(st.empty())
                    {
                        st.push(asteroids[i]);
                        break;
                    }
                }
                
            }
            else
                st.push(asteroids[i]);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};