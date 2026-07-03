class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // 1. Build the adjacency list
        // adj[u] = vector of pairs {v, cost}
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
        }
        
        // 2. Find Topological Sort of the DAG
        // We calculate in-degrees first
        for (int u = 0; u < n; ++u) {
            for (const auto& neighbor : adj[u]) {
                inDegree[neighbor.first]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Helper lambda function to check if a minimum edge cost of 'mid' is achievable
        auto check = [&](int mid) -> bool {
            // dist[i] stores the minimum total path cost to reach node i
            // Initialize with a value larger than any possible valid path cost (k)
            vector<long long> dist(n, -1);
            dist[0] = 0;
            
            // Process nodes in topological order
            for (int u : topoOrder) {
                if (dist[u] == -1) continue;
                
                // If the current node is offline and it's not the start/end node, we can't route through it
                if (!online[u] && u != 0 && u != n - 1) continue;
                
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int cost = neighbor.second;
                    
                    // Only consider edges that satisfy the binary search condition
                    if (cost >= mid) {
                        if (dist[v] == -1 || dist[u] + cost < dist[v]) {
                            dist[v] = dist[u] + cost;
                        }
                    }
                }
            }
            
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };
        
        // 3. Binary search on the maximum possible minimum edge cost
        int low = 0, high = 1e9;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;       // 'mid' is possible, try to find a larger minimum edge cost
                low = mid + 1;
            } else {
                high = mid - 1;  // 'mid' is too restrictive, lower the required edge cost
            }
        }
        
        return ans;
    }
};