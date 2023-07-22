class Solution {
public:
// Moore’s Voting Algorithm:
    int majorityElement(vector<int>& nums) {
        //size of the given array:
        int n = nums.size();
        int cnt = 0; // count
        int el; // Element

        //applying the algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i]) cnt++;
            else cnt--;
        }
        return el;

        // //checking if the stored element
        // // is the majority element:
        // int cnt1 = 0;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == el) cnt1++;
        // }

        // if (cnt1 > (n / 2)) return el;
        // return -1;

    }
};