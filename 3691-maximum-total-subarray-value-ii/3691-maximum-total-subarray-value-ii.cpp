class Solution {
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;

    // Build Sparse Tables for O(1) Max/Min range queries
    void buildSparseTable(const vector<int>& nums, int n) {
        int max_log = log2(n) + 1;
        st_max.assign(n, vector<int>(max_log));
        st_min.assign(n, vector<int>(max_log));
        
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    long long getVal(int l, int r) {
        int j = lg[r - l + 1];
        int mx = max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
        int mn = min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
        return (long long)mx - mn;
    }
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        buildSparseTable(nums, n);

        // Max-heap: stores { subarray_value, {left_index, right_index} }
        priority_queue<pair<long long, pair<int, int>>> pq;

        // Step 1: Initialize heap with the best option for every starting position 'l'
        for (int l = 0; l < n; l++) {
            pq.push({getVal(l, n - 1), {l, n - 1}});
        }

        long long total_value = 0;

        // Step 2: Extract top k elements
        while (k-- > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long val = top.first;
            int l = top.second.first;
            int r = top.second.second;

            total_value += val;

            // Step 3: Push the next best subarray for this 'l' (shrink right boundary)
            if (r > l) {
                pq.push({getVal(l, r - 1), {l, r - 1}});
            }
        }

        return total_value;
        
    }
};