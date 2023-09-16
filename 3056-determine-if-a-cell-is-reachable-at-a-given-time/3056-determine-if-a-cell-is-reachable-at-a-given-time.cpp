class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int ans=0;
        int diffx=abs(sx-fx);
        int diffy=abs(sy-fy);
        int mini=max(diffx,diffy);
        if(mini==0) return t!=1;
        else if(t>=mini) return true;
        else return false;

    }
};