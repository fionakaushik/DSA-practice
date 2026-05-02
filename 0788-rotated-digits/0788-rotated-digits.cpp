class Solution {
private:
    bool isgood(int i) {
        bool hasRotationDigit = false;
        while (i > 0) {
            int digit = i % 10;
            // Check for invalid digits
            if (digit == 3 || digit == 4 || digit == 7) {
                return false; 
            }
            // Check if it contains a digit that actually changes the number
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasRotationDigit = true;
            }
            i /= 10;
        }
        return hasRotationDigit;
    }
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (isgood(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};