class Solution {
    private:
    const int MOD = 1e9 + 7;
    int max_depth = 0;

    // DFS to find the maximum depth from the root
    void dfs(int node, int parent, int current_depth, const vector<vector<int>>& adj) {
        max_depth = max(max_depth, current_depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, current_depth + 1, adj);
            }
        }
    }

    // Fast Fourier Exponentiation / Binary Exponentiation
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        // Step 1: Build adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Find the maximum depth starting from root (node 1)
        max_depth = 0;
        dfs(1, 0, 0, adj);
        
        // Step 3: Return 2^(max_depth - 1) % MOD
        // If max_depth is 0 (shouldn't happen per constraints), return 0
        if (max_depth == 0) return 0; 
        
        return power(2, max_depth - 1);
    }
};