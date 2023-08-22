class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            // if(!st.empty() && asteroids[i]<0)
            // {
            //     while(!st.empty() && asteroids[i]<0)
            //     {
            //         if(st.top()>0)
            //         {
            //             if(st.top()>abs(asteroids[i]))
            //             {
            //                 break;
            //             }
            //             else if(st.top()<abs(asteroids[i]))
            //             {
            //                 st.pop();
            //             }
            //             else
            //             {
            //                 st.pop();
            //                 break;
            //             }
            //         }
            //         else
            //         {
            //             st.push(asteroids[i]);
            //             break;
            //         }
            //         if(st.empty())
            //         {
            //             st.push(asteroids[i]);
            //             break;
            //         }
            //     }
                
            // }
            // else
            //     st.push(asteroids[i]);
            bool flag=1;
            while(!st.empty() &&st.top()>0 && asteroids[i]<0)
            {
                if(st.top()>abs(asteroids[i]))
                {
                    flag=0;
                    break;
                }
                else if(st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                else
                {
                    st.pop();
                    flag=0;
                    break;
                }
            }
            if(flag)
            {   
                st.push(asteroids[i]);
            }
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