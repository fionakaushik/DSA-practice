class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //for each i ->2 sum
        
        //step 1:sort the array for 2 sum implementation
        sort(nums.begin(),nums.end());
        //min difference of sum from target will be our ans

        int res=0;
        int min_diff=INT_MAX;
        for( int i =0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1; 
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)==0)  //sum could be smaller,equal,greater than target
                    return sum;  //best ans if sum==target
                
                if(sum<target)
                {
                    int diff=abs(sum-target);
                    if(diff<min_diff)
                    {
                        min_diff=diff;
                        res=sum;
                    }
                    j++;
                }
                else if(sum>target)
                {
                    int diff=sum-target;
                    if(diff<min_diff)
                    {
                        min_diff=diff;
                        res=sum;
                    }
                    k--;
                }
            }
        

        }
        return res;
    }
};