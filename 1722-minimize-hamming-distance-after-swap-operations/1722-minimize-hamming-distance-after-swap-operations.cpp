class Solution {
public:
    // Standard Union-Find find function with path compression
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Union the indices that can be swapped
        for (auto& swap : allowedSwaps) {
            int root1 = find(parent, swap[0]);
            int root2 = find(parent, swap[1]);
            if (root1 != root2) parent[root1] = root2;
        }

        // Group elements of source by their root component
        unordered_map<int, unordered_map<int, int>> groups;
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            groups[root][source[i]]++;
        }

        int hammingDistance = 0;
        // Compare target elements with available elements in the same group
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            if (groups[root][target[i]] > 0) {
                groups[root][target[i]]--;
            } else {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
      

    
};