class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        // Track indices for 26 English alphabets
        vector<int> last_lowercase(26, -1);
        vector<int> first_uppercase(26, -1);

        // Populate the tracking arrays
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (islower(ch)) {
                last_lowercase[ch - 'a'] = i; // Keep updating to find the last occurrence
            } else {
                if (first_uppercase[ch - 'A'] == -1) //means we are seeing it for the first time
                {
                    first_uppercase[ch - 'A'] = i; // Store only the first occurrence
                }
            }

        }
        int special_count = 0;

        // Validate conditions for each character
        for (int i = 0; i < 26; i++) {
            if (last_lowercase[i] != -1 && first_uppercase[i] != -1) //make sure the char exist ion stirng
            {
                if (last_lowercase[i] < first_uppercase[i]) {
                    special_count++;
                }
            }
        }
        
        return special_count;
    }
};