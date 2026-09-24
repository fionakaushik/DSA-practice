class Solution {
private:
    int digiSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int dig=n%10;
            sum=sum+dig;
            n/=10;
        }
        return sum;

    }

public:
    int smallestIndex(vector<int>& nums) {
        int ans=0 ;
        for( int i =0;i<nums.size();i++){
           if(digiSum(nums[i])==i)
            return i;

        }

       return -1;

    }
};