class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        // Storage Limits of int vs long longint (32-bit): Can only hold values up to about $2 \times 10^9$ ($2,147,483,647$).long long (64-bit): Can hold values up to about $9 \times 10^{18}$.
        int max_val=nums[0];
        int min_val=nums[0];
        //find global max and min coz we keep choosing the same(say entire array ) k no of times
        for( int i=1;i<n;i++)
        {
            max_val=max(max_val,nums[i]);
            min_val=min(min_val,nums[i]);
        }
        //maxm val of a single subarray 
        long long max_single_value = max_val-min_val;
        //multiply by k bcz we can choose it k times
        return max_single_value*k;
    }
};