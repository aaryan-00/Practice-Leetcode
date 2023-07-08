class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,tens=0;
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
            else if(bills[i]==10)
            {
                if(five==0)return false;
                five--;
                tens++;
            }
            else
            {
                if(tens>0 && five>0)
                {
                    tens--;five--;
                }
                else if(tens==0 && five>=3)
                {
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};