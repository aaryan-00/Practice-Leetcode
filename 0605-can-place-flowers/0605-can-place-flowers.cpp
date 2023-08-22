class Solution {
public:
    // bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    //     int i=0;
    //     while(i<flowerbed.size() && flowerbed[i]==0)
    //     {
    //         i++;
    //     }
    //     if(i==flowerbed.size())n-=(i+1)/2;
    //     else n-=(i/2);
    //     for(;i<flowerbed.size();)
    //     {
    //         if(flowerbed[i]==1)
    //         {
    //             int j=i+1;
    //             while(j<flowerbed.size() && flowerbed[j]==0)
    //             {
    //                 j++;
    //             }
    //             if(j==flowerbed.size()) n-=(j-i-1)/2;
    //             else n-=(j-i-2)/2;

    //             i=j;
    //         }
    //         else i++;
    //     }
    //     return n<=0;
    // }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        return count >= n;
    }
};