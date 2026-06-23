class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int M = r - l + 1;
        long long MOD = 1e9 + 7;
        
        // If n = 1, any single element in the range is valid
        if (n == 1) return M;
        
        // dp_up[x]: ending at x, next element must be > x
        // dp_down[x]: ending at x, next element must be < x
        vector<long long> dp_up(M, 1);
        vector<long long> dp_down(M, 1);
        
        // For length 2, any pair of unequal elements is valid.
        // The base initialization of 1 means any single element can go up or down.
        // We iterate from length 2 up to n.
        for (int i = 2; i <= n; ++i) {
            vector<long long> next_up(M, 0);
            vector<long long> next_down(M, 0);
            
            // Optimize transitioning using prefix and suffix sums
            // next_down[y] = sum(dp_up[x]) for x < y (Prefix Sum)
            long long prefix_sum = 0;
            for (int y = 0; y < M; ++y) {
                next_down[y] = prefix_sum;
                prefix_sum = (prefix_sum + dp_up[y]) % MOD;
            }
            
            // next_up[y] = sum(dp_down[x]) for x > y (Suffix Sum)
            long long suffix_sum = 0;
            for (int y = M - 1; y >= 0; --y) {
                next_up[y] = suffix_sum;
                suffix_sum = (suffix_sum + dp_down[y]) % MOD;
            }
            
            dp_up = move(next_up);
            dp_down = move(next_down);
        }
        
        // Total valid configurations of length n is the sum of all ending states
        long long total_arrays = 0;
        for (int x = 0; x < M; ++x) {
            total_arrays = (total_arrays + dp_up[x] + dp_down[x]) % MOD;
        }
        
        return total_arrays;
    }
};