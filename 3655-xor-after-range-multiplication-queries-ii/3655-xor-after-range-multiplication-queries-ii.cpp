class Solution {

    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = 200; // Adjusted B for better balance with batching
        
        // Final multipliers for each index
        vector<long long> final_mult(n, 1);
        
        // Store queries for small k to batch process
        vector<vector<pair<int, int>>> small_k_queries(B);
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                // Large k: Still handled directly to save memory
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                // Small k: Store parameters for later
                small_k_queries[k].push_back({l, v});
                // We'll calculate the 'end' of the range logic inside the batch loop
                // to avoid storing every single r_i.
            }
        }

        // Process each small k independently to save space
        for (int k = 1; k < B; ++k) {
            if (small_k_queries[k].empty()) continue;

            vector<long long> diff(n + k, 1);
            // Re-run queries for this specific k to build the difference array
            for (auto& q : queries) {
                if (q[2] != k) continue;
                int l = q[0], r = q[1], v = q[3];
                
                diff[l] = (diff[l] * v) % MOD;
                int next_out = l + ((r - l) / k + 1) * k;
                if (next_out < n) {
                    diff[next_out] = (diff[next_out] * modInverse(v)) % MOD;
                }
            }

            // Prefix product with stride k
            for (int i = 0; i < n; ++i) {
                if (i >= k) diff[i] = (diff[i] * diff[i - k]) % MOD;
                final_mult[i] = (final_mult[i] * diff[i]) % MOD;
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= (int)((1LL * nums[i] * final_mult[i]) % MOD);
        }

        return result;
    }

        

};