class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Clone the original array
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // Map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int num : sortedArr) {
            // If the element is not already ranked, assign it the current rank
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }
        
        // Replace each element in the original array with its rank
        vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};