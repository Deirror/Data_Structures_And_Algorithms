class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        int prev1 = 0;
        int prev2 = 0;
        for(auto num : nums) {
            int temp = prev1;
            prev1 = max(num + prev2, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};
