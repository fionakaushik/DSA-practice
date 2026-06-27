class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //Count Frequencies: Put all numbers into a frequency map
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        //Handle 1s: Initialize your global maximum length with the maximum odd number of 1s available.edge case 
        int max_len = 0;
        if (freq.count(1)) {       //.count() is like .find()
            max_len = freq[1] % 2 == 0 ? freq[1] - 1 : freq[1];
        }

        // Check for patterns starting at each x > 1
        for (auto& [val, count] : freq) {
            if (val == 1) continue;
            
            int current_len = 0;
            long long x = val;
            
            // Keep extending the sides as long as we have at least 2 copies
            while (freq.count(x) && freq[x] >= 2) {
                current_len += 2;
                x = x * x; // move to x^2
            }
            // The final 'x' can be the peak if it exists at least once
            if (freq.count(x) && freq[x] >= 1) {
                current_len += 1;
            } else {
                // If it doesn't exist, the previous element we processed 
                // has to become the peak instead of an extension.
                current_len -= 1; 
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;

    }
};