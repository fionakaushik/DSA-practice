class Solution {
int func(vector<int>&nums,int goal)
    {
        if(goal<0)
            return 0;
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size())
        {
            sum+=nums[r]%2;
            while(sum>goal)
            {
                sum-=nums[l]%2;
                l++;
            }
            // This counts all subarrays ending at r with sum <= goal
            cnt+=r-l+1;
            r++;
        }
        return cnt;

    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //its similar to the question binary subarrays w sum =k
        //inthis Q , we consider of no;s such as 1 and even no;s as 0 and then find sum==k(means no of 1's means odd no's )

        // in this also subarrqyas <=k odd no's (1's) - subarrays <=k-1 odd no's (1's)

         //most optimal is (all subarrys w sum <=goal)-(all subarrys w sum<=goal-1)==all subarrys w sum==goal
        

        int cnt1=func(nums,k);
        int cnt2=func(nums,k-1);

        return (cnt1-cnt2); //all subarrays w sum(no's of 1's ,odd no's) exctly equal to k 
        
    }

        
    
};