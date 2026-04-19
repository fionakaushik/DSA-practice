class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxDist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            // If the condition is met, calculate distance and try to increase j
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            } else {
                // If nums1[i] is too large, we must increase i
                i++;
                // Optimization: j must be at least equal to i
                if (j < i) {
                    j = i;
                }
            }
        }
        
        return maxDist;
    }
        
    
};