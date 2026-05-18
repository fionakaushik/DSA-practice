class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Group all indices by their element values
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; i++) {
            valueToIndices[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        // Initialize BFS from index 0
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                // If we reached the last index, return the step count
                if (curr == n - 1) return steps;

                // Option 1: Jump to curr + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Option 2: Jump to curr - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Option 3: Jump to any index with the same value
                if (valueToIndices.count(arr[curr])) {
                    for (int nextIdx : valueToIndices[arr[curr]]) {
                        if (nextIdx != curr && !visited[nextIdx]) {
                            visited[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                    // CRITICAL: Clear the list so we don't look at these shortcuts again
                    valueToIndices.erase(arr[curr]);
                }
            }
            steps++;
        }

        return -1;
    }
};