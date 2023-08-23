class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    // int i=0;
    // int next(int price) {
    //     while(!st.empty() && st.top().first <= price)
    //     {
    //         st.pop();
    //     }
    //     int ans;
    //     if(st.empty())
    //     {
    //         ans=i+1;
    //     }
    //     else
    //     {
    //         ans=i-st.top().second;
    //     }
    //     st.push({price,i});
    //     i++;
    //     return ans; 
    // }

    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top().first <= price)
        {
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans; 

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */