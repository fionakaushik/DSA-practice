class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If not visited, start a new DFS
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
             int i, int j, int pi, int pj, char target) {
        
        visited[i][j] = true;
        
        // Direction vectors: Right, Down, Left, Up
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            // Check bounds and character match
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == target) {
                // If neighbor is visited and it's NOT the parent, we found a cycle!
                if (visited[ni][nj]) {
                    if (ni != pi || nj != pj) return true;
                } else {
                    // Standard recursive DFS
                    if (dfs(grid, visited, ni, nj, i, j, target)) return true;
                }
            }
        }
        
        return false;
    }
        
    
};