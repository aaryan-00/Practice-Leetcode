class NumArray {
public:
    vector<int> bit;
    vector<int> num;
    int sum(int i)
    {
        // i=i+1;
        int ans=0;
        for(;i>0;i-=i&(-i))
        {
            ans+=bit[i];
        }
        return ans;
    }
    void update_all(int i, int val) {
        // i=i+1;
        for(;i<=bit.size()-1;i+=i&(-i))
        {
            bit[i]+=val;
        }
    }
    NumArray(vector<int>& nums) {
        int n=nums.size();
        bit.resize(n+1,0);
        num=nums;
        for(int i=0;i<n;i++)
        {
            // update_all(i,nums[i]);
            update_all(i+1,nums[i]);
        }
    }
    
    void update(int i, int val) {
        // update_all(i,val-num[i]);
        update_all(i+1,val-num[i]);
        num[i]=val;
    }
    
    int sumRange(int left, int right) {
        // return sum(right)-sum(left-1);
        return sum(right+1)-sum(left-1+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */