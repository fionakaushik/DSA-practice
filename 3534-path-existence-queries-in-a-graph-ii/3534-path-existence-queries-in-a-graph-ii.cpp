class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Pair of {value, original_index}
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        // Map original index to sorted index position
        vector<int> sorted_pos(n);
        for (int i = 0; i < n; ++i) {
            sorted_pos[sorted_nodes[i].second] = i;
        }

        // Binary lifting table configuration
        int max_power = 18; // Since 2^17 = 131,072 > 10^5
        vector<vector<int>> up(max_power, vector<int>(n));

        // Step 2 & 3: Find 1-step greedy target and fill DP table
        for (int i = 0; i < n; ++i) {
            // Find the furthest element to the right within maxDiff
            auto it = upper_bound(sorted_nodes.begin(), sorted_nodes.end(), 
                                  make_pair(sorted_nodes[i].first + maxDiff, n));
            int steps_to_right = distance(sorted_nodes.begin(), it) - 1;
            up[0][i] = steps_to_right;
        }

        for (int j = 1; j < max_power; ++j) {
            for (int i = 0; i < n; ++i) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        // Step 4: Process Queries
        for (const auto& q : queries) {
            int u = sorted_pos[q[0]];
            int v = sorted_pos[q[1]];

            if (u == v) {
                answer.push_back(0);
                continue;
            }
            if (u > v) swap(u, v); // Keep u to the left of v

            int distance_steps = 0;
            // Binary lifting search
            for (int j = max_power - 1; j >= 0; --j) {
                if (up[j][u] < v) {
                    distance_steps += (1 << j);
                    u = up[j][u];
                }
            }

            // Take the final step to reach or overshoot v
            distance_steps += 1;
            u = up[0][u];

            // If even after moving forward we couldn't cross/reach v, it's impossible
            if (u < v) {
                answer.push_back(-1);
            } else {
                answer.push_back(distance_steps);
            }
        }

        return answer;
    }
};