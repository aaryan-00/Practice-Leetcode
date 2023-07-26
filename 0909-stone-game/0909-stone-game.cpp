class Solution {
public:
    // turn==0 for alice and 1 for bob
    bool getWinner(vector<int> &piles,int turn,int start,int end,int alice,int bob)
    {
        if(start<=end)
        {
            if(turn==1)
            {
                return getWinner(piles,!turn,start+1,end,alice,bob+piles[start])||getWinner(piles,!turn,start,end-1,alice,bob+piles[end]);
            }
            else if(turn==0)
            {
                return getWinner(piles,!turn,start+1,end,alice+piles[start],bob)||getWinner(piles,!turn,start,end-1,alice+piles[end],bob);
            } 
        }
        return alice>bob;

        
    }
    bool stoneGame(vector<int>& piles) {
        // return getWinner(piles,0,0,piles.size()-1,0,0);
        return true;
    }
};