class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        
        // Mark the presence of each character
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }
        
        // Count how many characters have both flags set to true
        int specialCount = 0;
        for (int i = 0; i < 26; ++i) {
            if (lower[i] && upper[i]) {
                specialCount++;
            }
        }
        
        return specialCount;
        
    }
};