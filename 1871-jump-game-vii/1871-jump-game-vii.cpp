class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        //Approach 1: BFS with a Sliding Window (Recommended)
        // int n = s.length();
        // if (s[n - 1] == '1') return false;

        // queue<int> q;
        // q.push(0);
        
        // // Keeps track of the furthest index we've already tried to push to the queue
        // int max_reached = 0; 

        // while (!q.empty()) {
        //     int i = q.front();
        //     q.pop();

        //     if (i == n - 1) return true;

        //     // The window of valid jumps from the current index `i`
        //     int start = max(i + minJump, max_reached + 1);
        //     int end = min(i + maxJump, n - 1);

        //     for (int j = start; j <= end; j++) {
        //         if (s[j] == '0') {
        //             q.push(j);
        //         }
        //     }
        //     // Update max_reached so the next nodes don't re-examine these indices
        //     max_reached = max(max_reached, i + maxJump);
        // }

        // return false;

        //Approach 2: DP with Sliding Window (Count of reachable sources)
        int n = s.length();
        if (s[n - 1] == '1') return false;

        vector<bool> dp(n, false);
        dp[0] = true; // We start at index 0
        
        int reachable_count = 0;

        for (int i = 1; i < n; i++) {
            // Add the new element entering the window from the right side
            if (i >= minJump && dp[i - minJump]) {
                reachable_count++;
            }
            
            // Remove the old element exiting the window from the left side
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachable_count--;
            }

            // If there is at least one reachable index that can jump to `i`, and s[i] is '0'
            if (reachable_count > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};