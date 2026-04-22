class Solution {
private:
    int helper(vector<int>&nums,int k){
        int i=0,j=0,cnt=0;
        unordered_map<int,int>mpp;

        while(j<nums.size())
        {
            mpp[nums[j]]++;
            while(mpp.size()>k)
            {
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0)
                    mpp.erase(nums[i]);
                i++;
                
            }
            if(mpp.size()<=k)
                cnt+=j-i+1;
            j++;

        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
        int atmostk=helper(nums,k)-helper(nums,k-1);

        return atmostk;
        
    }
};