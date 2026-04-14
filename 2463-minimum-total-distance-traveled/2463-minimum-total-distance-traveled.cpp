class Solution {
public:
    typedef long long ll;
        ll memo[101][10001];
        const ll INF = 1e15; // Large value to represent infinity

        ll solve(int rIdx, int fIdx, vector<int>& robot, vector<int>& factorySlots) {
            // Base Case: All robots are repaired
            if (rIdx == robot.size()) return 0;
            // Base Case: Out of factory slots but robots remain
            if (fIdx == factorySlots.size()) return INF;

            if (memo[rIdx][fIdx] != -1) return memo[rIdx][fIdx];

            // Option 1: Skip this factory slot
            ll skip = solve(rIdx, fIdx + 1, robot, factorySlots);

            // Option 2: Use this factory slot for the current robot
            ll take = abs(robot[rIdx] - factorySlots[fIdx]) + 
                    solve(rIdx + 1, fIdx + 1, robot, factorySlots);

            return memo[rIdx][fIdx] = min(take, skip);
        }

public:
        long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
            sort(robot.begin(), robot.end());
            sort(factory.begin(), factory.end());

            // Flatten factories: [pos, limit] -> [pos, pos, pos...]
            vector<int> factorySlots;
            for (auto& f : factory) {
                for (int i = 0; i < f[1]; ++i) {
                    factorySlots.push_back(f[0]);
                }
            }

            // Initialize memoization table with -1
            for(int i = 0; i < 101; i++) 
                for(int j = 0; j < 10001; j++) 
                    memo[i][j] = -1;

            return solve(0, 0, robot, factorySlots);
        }
            
        
};