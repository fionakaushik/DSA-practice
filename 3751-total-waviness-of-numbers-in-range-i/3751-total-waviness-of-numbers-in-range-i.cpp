class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        for (int i = num1; i <= num2; ++i) {
            string s = to_string(i);
            int n = s.length();
            
            // Numbers with fewer than 3 digits have 0 waviness
            if (n < 3) continue;

            // Check all middle digits
            for (int j = 1; j < n - 1; ++j) {
                // Check if it's a Peak
                if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
                    total_sum++;
                }
                // Check if it's a Valley
                else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
                    total_sum++;
                }
            }
        }
        return total_sum;
                    
    }
};