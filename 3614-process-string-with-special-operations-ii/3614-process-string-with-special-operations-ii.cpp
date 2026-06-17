class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        // Store the length of the string *after* processing s[i]
        vector<long long> lengths(n, 0);
        long long current_len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*') {
                if (current_len > 0) current_len--;
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {
                // Length stays the same
            }
            lengths[i] = current_len;
        }

        // If k is completely out of the final string's bounds
        if (k < 0 || k >= current_len) {
            return '.';
        }

        // Walk backwards to decode where 'k' lands
        for (int i = n - 1; i >= 0; --i) {
            // Find the length *before* the current operation s[i]
            long long prev_len = (i == 0) ? 0 : lengths[i - 1];

            if (s[i] >= 'a' && s[i] <= 'z') {
                // If s[i] was appended and k is pointing to this newly added index
                if (k == lengths[i] - 1) {
                    return s[i];
                }
            } else if (s[i] == '*') {
                // Backspace was applied. Since we are moving backwards, 
                // we don't change k, because k represents the index in the text 
                // that survived up to this point.
            } else if (s[i] == '#') {
                // Duplication was applied.
                // If k is in the second half, wrap it around to the first half.
                if (k >= prev_len) {
                    k %= prev_len;
                }
            } else if (s[i] == '%') {
                // Reverse was applied.
                // Mirror the index k based on the current length of the string.
                k = lengths[i] - 1 - k;
            }
        }

        return '.';
    }
};