class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // Initialize dp array with -1 (meaning the index is currently unreachable)
        vector<int> dp(n, -1);
        
        // Base case: 0 jumps to stay at the starting index
        dp[0] = 0;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if index i is reachable and if the jump condition is met
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};