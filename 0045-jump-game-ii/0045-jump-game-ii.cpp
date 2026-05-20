class Solution {
public:
    int jump(vector<int>& nums) {
        
        if (nums.size()==1)
            return 0;
        
        int jumps=0,l=0,r=0;
        while( r<nums.size()-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++) // a given range at any time is l-r
            {
                farthest=max(i+nums[i],farthest);  //for each range l to r we find farthest idx we can go to from that range

            }
            //update new range 
            l=r+1;
            r=farthest;
            jumps++;

        }
        return jumps;
        
    }
};