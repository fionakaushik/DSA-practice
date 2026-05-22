class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;  //target will eventually always end up at mid idx
            //identify sorted part:
            //left sorted check
            if(nums[low]<=nums[mid]) //implies left sorted
            {
                if(nums[low]<=target &&target <=nums[mid])//means target lies winthn it
                {
                    high=mid-1;                 //eliminate right half

                }
                else
                    low=mid+1;
            }
            else 
            {  //right sorted
                if(nums[mid]<=target&& target <=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            


        }
        return -1;
    }
};