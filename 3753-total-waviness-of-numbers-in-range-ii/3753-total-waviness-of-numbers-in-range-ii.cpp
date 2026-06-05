class Solution {
private:
    // memo[index][prev][prev_prev][is_less][is_started]
    // Max digits ~ 20, digits 0-9 (plus 10 for dummy/unset state)
    long long memo[20][11][11][2][2];

    long long dp(int idx, int prev, int prev_prev, bool is_less, bool is_started, const string& S) {
        if (idx == S.length()) {
            return 0; // Base case: reached the end of the number
        }

        if (memo[idx][prev][prev_prev][is_less][is_started] != -1) {
            return memo[idx][prev][prev_prev][is_less][is_started];
        }

        long long total = 0;
        int limit = is_less ? 9 : (S[idx] - '0');

        for (int digit = 0; digit <= limit; ++digit) {
            bool next_less = is_less || (digit < limit);
            bool next_started = is_started || (digit > 0);

            long long waviness_contributed = 0;

            // We only check for a peak/valley at 'prev' if we have at least 3 valid active digits
            if (is_started && prev != 10 && prev_prev != 10) {
                // Peak condition: prev_prev < prev > digit
                if (prev > prev_prev && prev > digit) {
                    waviness_contributed = 1;
                }
                // Valley condition: prev_prev > prev < digit
                else if (prev < prev_prev && prev < digit) {
                    waviness_contributed = 1;
                }
            }

            // Standard Digit DP configuration logic
            if (!next_started) {
                // Still processing leading zeros
                total += dp(idx + 1, 10, 10, next_less, false, S);
            } else {
                // How many valid sequences are generated downstream?
                long long downstream_sequences = get_combinations(idx + 1, digit, prev, next_less, true, S);
                
                // Add the local waviness multiplied by how many times this pattern repeats downstream
                total += (waviness_contributed * downstream_sequences) 
                       + dp(idx + 1, digit, prev, next_less, true, S);
            }
        }

        return memo[idx][prev][prev_prev][is_less][is_started] = total;
    }

    // Secondary DP array to count the sheer *number* of valid numerical arrangements downstream
    long long count_memo[20][11][11][2][2];
    
    long long get_combinations(int idx, int prev, int prev_prev, bool is_less, bool is_started, const string& S) {
        if (idx == S.length()) return 1;
        if (count_memo[idx][prev][prev_prev][is_less][is_started] != -1) {
            return count_memo[idx][prev][prev_prev][is_less][is_started];
        }

        long long total = 0;
        int limit = is_less ? 9 : (S[idx] - '0');

        for (int digit = 0; digit <= limit; ++digit) {
            bool next_less = is_less || (digit < limit);
            bool next_started = is_started || (digit > 0);

            if (!next_started) {
                total += get_combinations(idx + 1, 10, 10, next_less, false, S);
            } else {
                total += get_combinations(idx + 1, digit, prev, next_less, true, S);
            }
        }
        return count_memo[idx][prev][prev_prev][is_less][is_started] = total;
    }

    long long solve(long long num) {
        if (num < 100) return 0; // Numbers under 3 digits cannot have peaks/valleys
        string S = to_string(num);
        memset(memo, -1, sizeof(memo));
        memset(count_memo, -1, sizeof(count_memo));
        return dp(0, 10, 10, false, false, S);
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        //digit DP 
        return solve(num2) - solve(num1 - 1);
    }
};