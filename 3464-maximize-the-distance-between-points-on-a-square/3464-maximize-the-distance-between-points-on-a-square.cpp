class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> pos;
        long long s = side;

        // 1. Unroll the square boundary to 1D
        for (auto& p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == s) pos.push_back(s + y);
            else if (y == s) pos.push_back(2 * s + (s - x));
            else if (x == 0) pos.push_back(3 * s + (s - y));
        }

        sort(pos.begin(), pos.end());
        long long totalLen = 4 * s;

        // 2. Greedy check function
        auto check = [&](long long mid) {
            // We only need to test starting points within the first possible "gap"
            for (int i = 0; i < n; ++i) {
                if (pos[i] > pos[0] + mid) break;

                int count = 1;
                long long lastPos = pos[i];
                long long firstPos = pos[i];
                int currIdx = i;

                for (int j = 1; j < k; ++j) {
                    auto it = lower_bound(pos.begin() + currIdx + 1, pos.end(), lastPos + mid);
                    if (it == pos.end()) {
                        count = -1; 
                        break;
                    }
                    lastPos = *it;
                    currIdx = distance(pos.begin(), it);
                    count++;
                }

                // Check the wrap-around distance to the first point
                if (count == k && (totalLen - (lastPos - firstPos)) >= mid) {
                    return true;
                }
            }
            return false;
        };

        // 3. Binary Search
        long long low = 1, high = totalLen / k;
        long long ans = 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
        
    }
};