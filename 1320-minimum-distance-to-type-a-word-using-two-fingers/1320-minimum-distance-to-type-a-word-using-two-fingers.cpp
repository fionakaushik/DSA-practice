class Solution {
public:
    int minimumDistance(string word) {
            // dp[other_finger] represents the minimum distance where one finger 
            // is at word[i-1] and the other finger is at 'other_finger'.
            // 26 represents the 'initial' state where the second finger hasn't been placed.
            vector<int> dp(27, 2000); 
            dp[26] = 0;

            for (int i = 0; i < word.length() - 1; ++i) {
                int curr = word[i] - 'A';
                int next = word[i+1] - 'A';
                vector<int> next_dp(27, 2000);

                for (int other = 0; other <= 26; ++other) {
                    if (dp[other] == 2000) continue;

                    // Option 1: Move the finger currently at 'curr' to 'next'
                    next_dp[other] = min(next_dp[other], dp[other] + getDist(curr, next));

                    // Option 2: Move the 'other' finger to 'next'
                    int move_cost = (other == 26) ? 0 : getDist(other, next);
                    next_dp[curr] = min(next_dp[curr], dp[other] + move_cost);
                }
                dp = move(next_dp);
            }

            return *min_element(dp.begin(), dp.end());
        }

    private:
        int getDist(int a, int b) {
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
        }

    
};