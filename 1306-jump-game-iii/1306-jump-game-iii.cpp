class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Base cases: Out of bounds or already visited
        if (start < 0 || start >= arr.size() || arr[start] < 0) {
            return false;
        }
        
        // Target found
        if (arr[start] == 0) {
            return true;
        }
        
        // Flip the value to negative to mark it as visited
        arr[start] = -arr[start];
        
        // Recursively check right jump and left jump using the original step size
        // (We use -arr[start] because the value is currently negative)
        bool jumpRight = canReach(arr, start - arr[start]);
        bool jumpLeft  = canReach(arr, start + arr[start]);
        
        return jumpRight || jumpLeft;
    }
};