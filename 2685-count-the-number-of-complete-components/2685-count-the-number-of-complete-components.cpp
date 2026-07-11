class Solution {
public:

    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& vertexCount, int& degreeSum) {
        visited[node] = true;
        vertexCount++;
        degreeSum += adj[node].size(); // Add the degree of the current node
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertexCount, degreeSum);
            }
        }
    }



    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int completeComponentsCount = 0;
        
        // Step 2: Iterate through all nodes to find each connected component
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int degreeSum = 0;
                
                // Run DFS to explore the entire component
                dfs(i, adj, visited, vertexCount, degreeSum);
                
                // Step 3: Check if the component is complete
                if (degreeSum == vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};