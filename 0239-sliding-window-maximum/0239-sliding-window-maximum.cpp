class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ls;
        deque<int>dq;       //dq stores indexes
        for(int i=0;i<nums.size();i++)
        {
            //make sure the window size is valid
            // 1. Remove indices that are out of the window range
            if(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();

            //make sure to keep max in front and smaller in back ,if new max found push and remove from back
            //2. Remove smaller elements from the back (they can't be the max anymore)
            while(!dq.empty() && nums[dq.back()]<=nums[i])  //new max for the window found     
                dq.pop_back();

            dq.push_back(i);

            //first window encountered to n-1
            // 3. Start adding to results once the first window is complete
            if(i>=k-1)
                ls.push_back(nums[dq.front()]);

            

        }
        return ls;
    }
};