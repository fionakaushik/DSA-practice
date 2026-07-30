class Solution {
public:
    int minimumPushes(string word) {
        int n= word.size();
        int ans = 0;
        
        // Count min pushes for each group of 8 letters(reassigning is possible )
        if (n <= 8) {
            ans += n * 1;
        } else if (n <= 16) {
            ans += 8 * 1 + (n - 8) * 2;
        } else if (n <= 24) {
            ans += 8 * 1 + 8 * 2 + (n - 16) * 3;
        } else {
            ans += 8 * 1 + 8 * 2 + 8 * 3 + (n - 24) * 4;
        }
        
        return ans;
    
    }
};