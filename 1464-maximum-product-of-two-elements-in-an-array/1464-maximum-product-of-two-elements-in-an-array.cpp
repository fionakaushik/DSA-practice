class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute force: O(N^2)
        int ans=0;
        int maxi=INT_MIN;
        for( int i=0;i<nums.size();i++)
        {
            for ( int j=i+1;j<nums.size();j++)
            {
                ans=(nums[i]-1)*(nums[j]-1);
                maxi=max(ans,maxi);
            }
        }
        return maxi;

        //optimal
        ///find largest and swcond largest el in a single pass
        int max1=0;
        int max2=0;
        for( int n : nums)
        {
            if(n>max1){
                max2=max1;
                max1=n;
            }
            else if(n>max2)  //a num that is > max2 but not max1
                max2=n;

        }
        return ((max1-1)*(max2-1));
    }
};