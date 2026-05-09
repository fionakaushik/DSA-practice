class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int num_layers = min(m, n) / 2;

        for (int layer = 0; layer < num_layers; ++layer) {
            vector<int> elements;
            
            // 1. Extract Top row (left to right)
            for (int j = layer; j < n - layer - 1; ++j) elements.push_back(grid[layer][j]);
            // 2. Extract Right column (top to bottom)
            for (int i = layer; i < m - layer - 1; ++i) elements.push_back(grid[i][n - layer - 1]);
            // 3. Extract Bottom row (right to left)
            for (int j = n - layer - 1; j > layer; --j) elements.push_back(grid[m - layer - 1][j]);
            // 4. Extract Left column (bottom to top)
            for (int i = m - layer - 1; i > layer; --i) elements.push_back(grid[i][layer]);

            // Calculate effective rotation
            int len = elements.size();
            int net_k = k % len;
            
            // 5. Re-insert elements starting from index net_k
            int idx = net_k;
            
            for (int j = layer; j < n - layer - 1; ++j) grid[layer][j] = elements[idx++ % len];
            for (int i = layer; i < m - layer - 1; ++i) grid[i][n - layer - 1] = elements[idx++ % len];
            for (int j = n - layer - 1; j > layer; --j) grid[m - layer - 1][j] = elements[idx++ % len];
            for (int i = m - layer - 1; i > layer; --i) grid[i][layer] = elements[idx++ % len];
        }
        
        return grid;
    }
};