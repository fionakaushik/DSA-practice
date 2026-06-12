class Solution {
    int MOD = 1e9 + 7;
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;

    // Fast exponentiation to compute (2^(k-1)) % MOD
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

    // DFS to precalculate depths and immediate parents (up[v][0])
    void dfs(int node, int p, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = p;
        for (int i = 1; i < LOG; ++i) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        for (int neighbor : adj[node]) {
            if (neighbor != p) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Function to find the LCA of u and v
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        // Lift u up to the same depth as v
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;

        // Lift both u and v simultaneously until they are just below their LCA
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, 1));

        // Initialize binary lifting table from the root (Node 1)
        dfs(1, 1, 0, adj);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int distance = depth[u] + depth[v] - 2 * depth[lca];

            // Number of ways is 2^(distance - 1) % MOD
            answer.push_back(power(2, distance - 1));
        }

        return answer;
        
    }
};