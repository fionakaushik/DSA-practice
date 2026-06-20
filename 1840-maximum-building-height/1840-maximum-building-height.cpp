class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Step 1: Add boundary restrictions
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        // Sort restrictions by building ID
        std::sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Step 2: Left-to-Right Pass
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            restrictions[i + 1][1] = std::min(h2, h1 + (id2 - id1));
        }
        
        // Step 3: Right-to-Left Pass
        for (int i = m - 1; i > 0; --i) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            restrictions[i - 1][1] = std::min(h1, h2 + (id2 - id1));
        }
        
        // Step 4: Calculate the absolute max height between adjacent restrictions
        int max_height = 0;
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            
            int peak = (h1 + h2 + (id2 - id1)) / 2;
            max_height = std::max(max_height, peak);
        }
        
        return max_height;
    }
};