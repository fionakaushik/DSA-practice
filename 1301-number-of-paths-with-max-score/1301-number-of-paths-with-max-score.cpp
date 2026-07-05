class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // dp[r][c] stores {max_score, path_count}
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        // Base case: Start at 'E' (0, 0)
        dp[0][0] = {0, 1};
        
        // Directions to look back to: up, left, up-left diagonal
        int dr[] = {-1, 0, -1};
        int dc[] = {0, -1, -1};
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                // Skip the starting point (already initialized) and obstacles
                if ((r == 0 && c == 0) || board[r][c] == 'X') continue;
                
                int max_val = -1;
                long long paths = 0;
                
                // Check all 3 incoming directions
                for (int i = 0; i < 3; ++i) {
                    int prev_r = r + dr[i];
                    int prev_c = c + dc[i];
                    
                    // Check boundaries and if the previous cell is reachable
                    if (prev_r >= 0 && prev_c >= 0 && dp[prev_r][prev_c].first != -1) {
                        int current_score = dp[prev_r][prev_c].first;
                        
                        if (current_score > max_val) {
                            max_val = current_score;
                            paths = dp[prev_r][prev_c].second;
                        } else if (current_score == max_val) {
                            paths = (paths + dp[prev_r][prev_c].second) % MOD;
                        }
                    }
                }
                
                // If this cell is reachable from at least one valid cell
                if (max_val != -1) {
                    // Add current cell's value (treating 'S' as 0)
                    int cell_value = (board[r][c] == 'S') ? 0 : (board[r][c] - '0');
                    dp[r][c] = {max_val + cell_value, paths};
                }
            }
        }
        
        // The result is stored at the bottom-right corner 'S' (n-1, n-1)
        pair<int, int> result = dp[n - 1][n - 1];
        if (result.first == -1) {
            return {0, 0};
        }
        return {result.first, result.second};
    
       
    } 
};