class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int totalSubarrays = 0;  /// Reset count for the new starting point 'i'
        for( int i=0;i<nums.size();i++)
        {
            int targetCount = 0;
            for( int j=i;j<nums.size();j++)
            {
                // 1. Update the count if the current element matches the target
                if ( nums[j]==target)
                    targetCount++;
                //length of current subarray 
                int len=j-i+1;
                //as j moves to the right, we check if nums[j] == target
                //f it is, we increment our running count.
                //check if it meets the majority condition({count*2 >{length}

                //3. Check if target is the strict majority
                if (targetCount * 2 > len) {
                    totalSubarrays++;
                }

            }
        }
        return totalSubarrays;
    }
};