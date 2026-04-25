class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //approach 1:sort and give k-1th idx el t,c: o(nlogn)
        //approach2:
        //heap->priority queue 

        priority_queue<int,vector<int>, greater<int>>pq; //min heap 

        //step 1:push first k elemnts into heap
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);    
        }

        //step 2: for rem elemnts compare root node 
        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
                

        }
        //hence at last we have minheap of k elemts hving k largest elmnts
        //ans=root node(pq.top()) will have kth largest el
        int ans= pq.top();
        return ans;


        
    }
};