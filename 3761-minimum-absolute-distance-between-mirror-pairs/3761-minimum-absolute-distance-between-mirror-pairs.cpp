class Solution {
private :
    int getrev(int n )
    {
        int rev=0;
        while(n>0)
        {
            int rem=n%10;
            rev=rev*10+rem;
            n/=10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
       unordered_map<int, int> mp; // Target Mirror -> Original Index
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            // Check if current number completes a mirror pair
            if (mp.find(nums[i]) != mp.end()) {
                res = min(res, i - mp[nums[i]]);
            }
            
            // Store the reverse so a future number can find it
            // Note: If duplicates exist, updating to the latest index 
            // ensures the "minimum" distance for the next pair found.
            mp[getrev(nums[i])] = i;
        }

        return (res == INT_MAX) ? -1 : res;
    }
};