class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // visited array to keep track of explored cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Mapping street types to the directions they connect: {row_offset, col_offset}
        // Directions: Up: {-1, 0}, Down: {1, 0}, Left: {0, -1}, Right: {0, 1}
        map<int, vector<pair<int, int>>> directions = {
            {1, {{0, -1}, {0, 1}}},  // Left, Right
            {2, {{-1, 0}, {1, 0}}},  // Up, Down
            {3, {{0, -1}, {1, 0}}},  // Left, Down
            {4, {{0, 1}, {1, 0}}},   // Right, Down
            {5, {{0, -1}, {-1, 0}}}, // Left, Up
            {6, {{0, 1}, {-1, 0}}}   // Right, Up
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If we reached the bottom-right cell, return true
            if (r == m - 1 && c == n - 1) return true;

            int streetType = grid[r][c];
            for (auto& dir : directions[streetType]) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check bounds and if already visited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int nextStreet = grid[nr][nc];
                    bool canConnect = false;

                    // A neighbor is connected only if it has a pipe pointing back to us
                    for (auto& backDir : directions[nextStreet]) {
                        if (nr + backDir.first == r && nc + backDir.second == c) {
                            canConnect = true;
                            break;
                        }
                    }

                    if (canConnect) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};
        
  