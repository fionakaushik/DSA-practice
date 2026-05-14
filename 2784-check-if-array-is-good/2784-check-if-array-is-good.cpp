class Solution {
public:
    bool isGood(vector<int>& nums) {
        // //approach 1: max_el amd hashmap vector for freq maintain
        // int n = nums.size();
        // int max_el= n-1;  // The expected max element
        // vector<int>cnt(max_el+1,0); //kinda simulation of base array
        // for( int x:nums)
        // {
        //     if(x>max_el||x<1) return false;
        //     cnt[x]++;
        // }
        // // Check 1 to n-1 appear once
        // for( int i=1;i<max_el;i++)
        // {
        //     if(cnt[i]!=1) return false;
        // }
        // //check n appears twice
        // return cnt[max_el]==2; 


        //approach 2:sort the nums and then idx wil have elemnt idx+1 till n-2
        // sort(nums.begin(),nums.end());  //nlog n 
        // for( int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i]!=i+1) return false;

        // }
        // return (nums[nums.size()-1]==nums.size()-1);


        //APPROACH 3:SINGLE PASS MOST OPTIMAL
        //.......use elmnts as indexes 
        int n=nums.size();
        int max_el=n-1;
        int max_el_freq=0;
        for(int num:nums)
        {
            int val=abs(num); //val is idx now

            if(val>max_el||val<1) return false;

            if(val==max_el) max_el_freq++;

            if(nums[val]<0)   //means we already visisted this val idx once
            {
                if(val!= max_el) return false;
                else if(max_el_freq>2) return false;

            }
            else
                nums[val]*=-1;
        }
        return true;


    }
};