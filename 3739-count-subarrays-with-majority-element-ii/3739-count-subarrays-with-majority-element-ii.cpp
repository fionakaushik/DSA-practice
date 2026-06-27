//First, solve LeetCode 525, then learn the Fenwick Tree, and finally come back to this problem—it will feel quite easy.


#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


// Custom tree structure that acts like a multiset but allows order queries
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long total_subarrays = 0;
        int current_prefix_sum = 0;
        
        // Structure to store all prefix sums seen so far
        ordered_multiset seen_prefixes;
        
        // Base case: prefix sum before processing any element is 0
        seen_prefixes.insert(0);
        
        for (int num : nums) {
            // Step 1: Transform element into +1 or -1
            if (num == target) {
                current_prefix_sum += 1;
            } else {
                current_prefix_sum -= 1;
            }
            
            // Step 2: Find how many previous prefixes are strictly less than current_prefix_sum
            // order_of_key returns the number of elements strictly smaller than the argument
            total_subarrays += seen_prefixes.order_of_key(current_prefix_sum);
            
            // Step 3: Insert the current prefix sum into our tracked set
            seen_prefixes.insert(current_prefix_sum);
        }
        
        return total_subarrays;
    }
};