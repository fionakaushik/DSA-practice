class Solution {
private:
    int func(vector<int>&nums,int goal)
    {
        if(goal<0)
            return 0;
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            // This counts all subarrays ending at r with sum <= goal
            cnt+=r-l+1;
            r++;
        }
        return cnt;

    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //most optimal is (all subarrys w sum <=goal)-(all subarrys w sum<=goal-1)==all subarrys w sum==goal
        

        int cnt1=func(nums,goal);
        int cnt2=func(nums,goal-1);

        return (cnt1-cnt2);
        
    }
};