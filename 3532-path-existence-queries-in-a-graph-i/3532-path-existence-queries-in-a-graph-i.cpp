class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // component[i] will store the ID of the connected component for node i
        vector<int> component(n, 0);
        int currentComponent = 0;
        
        // Step 1: Preprocess and find connected components in O(n)
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentComponent++; // Start a new component if the gap is too large
            }
            component[i] = currentComponent;
        }
        
        // Step 2: Answer each query in O(1)
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            // If they belong to the same continuous component, a path exists
            answer.push_back(component[u] == component[v]);
        }
        
        return answer;
        
    }
};