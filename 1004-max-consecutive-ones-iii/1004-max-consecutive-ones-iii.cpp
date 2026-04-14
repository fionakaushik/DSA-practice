class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //optimal(2ptr +sliding w)
        int maxlen=0;
        int l=0,r=0,zeros=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
                zeros++;
            
            if(zeros>k)
            {
                if(nums[l]==0)
                    zeros--;
                l++; //movin l until first zero encountered to lessen 
            }
            if(zeros<=k)
            {
                int len= r-l+1;
                maxlen=max(maxlen,len);
            }
            r++;

        }
        return maxlen;

        
    }
};