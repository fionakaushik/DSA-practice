class Solution {
private:
    int dfs(int i, const vector<int>& arr, int d, vector<int>& memo) {
        // If already calculated, return the cached result
        if (memo[i] != -1) return memo[i];
        
        int n = arr.size();
        int max_jumps = 1; // You can always at least stay at the current index (1 town visited)
        
        // 1. Jump to the right: i + x
        for (int x = 1; x <= d && i + x < n; ++x) {
            // Blocked if we hit a bar that is >= current height
            if (arr[i + x] >= arr[i]) break; 
            max_jumps = max(max_jumps, 1 + dfs(i + x, arr, d, memo));
        }
        
        // 2. Jump to the left: i - x
        for (int x = 1; x <= d && i - x >= 0; ++x) {
            // Blocked if we hit a bar that is >= current height
            if (arr[i - x] >= arr[i]) break;
            max_jumps = max(max_jumps, 1 + dfs(i - x, arr, d, memo));
        }
        
        return memo[i] = max_jumps;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);
        int ans = 0;
        
        // Try starting from every possible index
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, arr, d, memo));
        }
        
        return ans;
        
    }
};