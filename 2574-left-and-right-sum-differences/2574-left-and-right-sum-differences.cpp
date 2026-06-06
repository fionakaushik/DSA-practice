class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,0);
        int l=1;
        int lSum=nums[0];
        int r=n-2;
        int rSum=nums[n-1];
        while(l<=n-1)
        {
            
            ans[l]=lSum;
            lSum+=nums[l];
            l++;
        }
        while(r>=0)
        {
            
            ans[r]=abs(ans[r]-rSum);
            rSum+=nums[r];
            r--;
        }
        ans[0]=rSum-nums[0];
        ans[n-1]=lSum-nums[n-1];
        return ans;

    }
};