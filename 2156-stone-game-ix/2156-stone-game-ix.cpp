class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zero=0,one=0,two=0;
        for(auto i:stones)
        {
            if(i%3==0) zero++;
            else if(i%3==1) one++;
            else two++;
        }
        if(one==0 && two==0) return false;
        if(one==0)
        {
            if(two<=2)
            {
                return false;
            }
            else
            {
                if(zero%2==0) return false;
                else return true;
            }
        }
        if(two==0)
        {
            if(one<=2)
            {
                return false;
            }
            else
            {
                if(zero%2==0) return false;
                else return true;
            }
        }
        
        if ((zero + 1) % 2 == 0) 
        {
            if (two - 2 >  one) {
                return true;
            }
            if (one - 2 > two) return true;
        }
        else 
        {
            if (one - 2 < two) return true;
            if (two - 2 < one) return true;
        }

        return false;
    }
};