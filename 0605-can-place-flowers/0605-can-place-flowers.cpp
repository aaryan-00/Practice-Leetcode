class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size() && flowerbed[i]==0)
        {
            i++;
        }
        if(i==flowerbed.size())n-=(i+1)/2;
        else n-=(i/2);
        for(;i<flowerbed.size();)
        {
            if(flowerbed[i]==1)
            {
                int j=i+1;
                while(j<flowerbed.size() && flowerbed[j]==0)
                {
                    j++;
                }
                // cout<<i<<" "<<j<<endl;
                
                if(j==flowerbed.size()) n-=(j-i-1)/2;
                else n-=(j-i-2)/2;

                i=j;
            }
            else i++;
        }
        return n<=0;
    }
};