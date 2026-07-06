class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort: ascending by start, descending by end if starts are equal
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = 0;
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end is past the max_end tracked,
            // it is not completely covered.
            if (interval[1] > max_end) {
                remainingCount++;
                max_end = interval[1]; // Update the boundary
            }
        }
        
        return remainingCount;
    }
    
};