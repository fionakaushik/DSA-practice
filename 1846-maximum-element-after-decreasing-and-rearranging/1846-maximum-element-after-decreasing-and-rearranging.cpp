class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Step 1: Sort the array to process elements in increasing order
        sort(arr.begin(), arr.end());
        
        // Step 2: Enforce the first condition
        arr[0] = 1;
        
        // Step 3: Iterate through the array and limit the jump to at most 1
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        // The last element will hold the maximum value possible
        return arr.back();
    }
};