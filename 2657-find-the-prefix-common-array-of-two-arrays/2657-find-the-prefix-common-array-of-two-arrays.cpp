class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        // Frequency array to store counts of numbers (1-indexed, so size n + 1)
        vector<int> freq(n + 1, 0);
        int common_count = 0;

        for (int i = 0; i < n; ++i) {
            // Process element from array A
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common_count++;
            }

            // Process element from array B
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common_count++;
            }

            // Store the current count of common elements
            C[i] = common_count;
        }

        return C;
    }
};