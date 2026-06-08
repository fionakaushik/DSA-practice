class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        //2 ptr aaproach
        int left=0;
        int right= n-1;
        //left and right pointers track res array
        //i and j pointers track nums array
        vector<int>res(n);
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            if(nums[i]<pivot)
            {
                res[left]=nums[i];
                left++;
            }
            if(nums[j]>pivot)
            {
                res[right]=nums[j];
                right--;
            }
        }
        //fill remaining from left <= till high w elemnts ==pivot
        while(left<=right)
        {
            res[left]=pivot;
            left++;
        }
        return res;
        
    }
};