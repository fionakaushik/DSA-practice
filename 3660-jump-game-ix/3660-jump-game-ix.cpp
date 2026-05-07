class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        // prefixMax[i] is the max value from index 0 to i
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        
        // suffixMin[i] is the min value from index i to n-1
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        
        // Identify "cut" points where the array can be partitioned
        // A cut exists at i if prefixMax[i] <= suffixMin[i+1]
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || prefixMax[i] <= suffixMin[i + 1]) {
                // Find the max in this connected component [start, i]
                int currentMax = 0;
                for (int k = start; k <= i; k++) {
                    currentMax = max(currentMax, nums[k]);
                }
                // Fill the result for this component
                for (int k = start; k <= i; k++) {
                    ans[k] = currentMax;
                }
                start = i + 1;
            }
        }
        
        return ans;
        
    }
};