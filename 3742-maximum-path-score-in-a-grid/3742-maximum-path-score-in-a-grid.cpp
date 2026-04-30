class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][cost] = max_score
        // Initialize with -1 to represent unreachable states
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Base case: Starting cell (0,0)
        // grid[0][0] is guaranteed to be 0 per constraints
        dp[0][0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int c = 0; c <= k; ++c) {
                    if (dp[i][j][c] == -1) continue;

                    // Try moving Right (i, j+1) and Down (i+1, j)
                    int directions[2][2] = {{0, 1}, {1, 0}};
                    for (auto& dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        if (ni < m && nj < n) {
                            int val = grid[ni][nj];
                            int moveCost = (val == 0) ? 0 : 1;
                            int moveScore = val;

                            if (c + moveCost <= k) {
                                dp[ni][nj][c + moveCost] = max(dp[ni][nj][c + moveCost], dp[i][j][c] + moveScore);
                            }
                        }
                    }
                }
            }
        }

        // Find the maximum score in the last cell (m-1, n-1) across all valid costs
        int maxScore = -1;
        for (int c = 0; c <= k; ++c) {
            maxScore = max(maxScore, dp[m - 1][n - 1][c]);
        }

        return maxScore;
        
    }
};