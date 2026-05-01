class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long f = 0;
        
        // Calculate total sum of array and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }
        
        long long max_val = f;
        
        // Compute F(k) from F(k-1) in O(1)
        // We iterate backwards to pick the element that 
        // shifts from the last index to the first index (index 0)
        for (int i = n - 1; i > 0; i--) {
            f = f + sum - n * nums[i];
            max_val = max(max_val, f);
        }
        
        return (int)max_val;
    }
        
    
};