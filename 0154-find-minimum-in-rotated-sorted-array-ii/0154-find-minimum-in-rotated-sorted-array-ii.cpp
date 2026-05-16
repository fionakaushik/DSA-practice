class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int mini=INT_MAX; 

        //if is roated n times(n=nums.size()) then arr[low<=arr[mid] && arr[mid]<=arr[high]]
        
        while(low<=high)
        {
            
            // if(nums[low]<=nums[mid]&& nums[mid]<=nums[high])
            // {  //sorted array entirely
            //     mini=min(mini,arr[low]);
            //     break;
            // }        fails in [2,2,2,2,0,1,2]

            //handle 2 PTR DUPLICATEs
            while(low<high && nums[low+1]==nums[low]) low++;
            while(low<high && nums[high-1]==nums[high]) high--;

            int mid=(low+high)/2;

            if(nums[mid]>=nums[low]) //sorted ...pick min from here and eliminate this half
            {
                //left sorteedd
                mini=min(nums[low],mini);
                low=mid+1;
            }
            else 
            {  //right sorted
                mini=min(mini,nums[mid]);        //pick the min el from this half
                high=mid-1; //eliminate right half
            }

        }
        return mini;

    }
};