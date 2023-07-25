class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        // int xor1 = 0, xor2 = 0;
        

        // for (int i = 0; i < n; i++) {
        //     xor2 = xor2 ^ nums[i]; // XOR of array elements
        //     xor1 = xor1 ^ (i+1); //XOR up to [1...N]
        // }
        // return (xor1 ^ xor2); // the missing number
        

        //Summation of first N numbers:
        int sum = (n * (n + 1)) / 2;

        //Summation of all array elements:
        int s2 = 0;
        for (int i = 0; i < n; i++) {
            s2 += nums[i];
        }

        int missingNum = sum - s2;
        return missingNum;

    }
};