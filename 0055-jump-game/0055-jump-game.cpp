class Solution {
public:
    bool canJump(vector<int>& nums) {
        //keep a track of the maxIdx u csn reach from each ids i 
        int maxIdx=0;
        for ( int i=0;i<nums.size();i++)
        {
            //break early if we reach an i > maxIdx coz that ain;t possible himanly 
            if( i > maxIdx) return false;
            //calculate the maxIdx //if the loop completely iterates we always reach end
            maxIdx=max(maxIdx,i+nums[i]);
            
            //optimization step but not necessary ,early exit
            if(maxIdx>=nums.size()-1)
                return true;

        }
        //since we reached the end of the loop and our false condition didn't get triggered 
        return true;
        
    }
};