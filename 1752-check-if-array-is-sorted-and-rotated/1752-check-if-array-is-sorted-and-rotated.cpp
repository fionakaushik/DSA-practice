class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int countbreak=0;
        //there should be only 1 break for sorted and rotated non dec array(0 for duplicates)
        //check circularly if the current element is greater than the next (circularly)
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
                countbreak++;

        }
        return countbreak<=1;
        
    }
};