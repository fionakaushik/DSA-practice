class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;

            //if search space alr sorted then ....
            //alwats arr[low] will be the min
            //rotated n time(size of arr)
            if(nums[low]<=nums[high])   //nums[low]<=nums[mid]<=nums[high]
            {
                ans=min(ans,nums[low]);
                break;
            }

            //identify sorted part:
            //left sorted check
            if(nums[low]<=nums[mid]) //implies left sorted
            {
               ans=min(ans,nums[low]);      //pick the min el from this half
               low=mid+1;                //eliminate left half
            }
               
            else 
            {  //right sorted
                ans=min(ans,nums[mid]);        //pick the min el from this half
                high=mid-1; //eliminate right half
            }
            


        }
        return ans;
        
        
    }
};