class Solution {
private:
    int sumOfDig(int & n)
    {
        int sum=0;
        while (n>0)
        {
            int dig=n%10;
            sum+=dig;
            n/=10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for( int i=0;i<nums.size();i++)
        {
            int s=sumOfDig(nums[i]);
            nums[i]=s;
            mini=min(nums[i],mini);
        }
        return mini;
        
    }
};