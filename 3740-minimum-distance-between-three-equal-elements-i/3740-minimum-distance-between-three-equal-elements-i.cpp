class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp; //nums[i],cnt
        for(int i=0;i<nums.size();i++)
        {
            //insertion in map ,stores(nums[i],indices where num[i] appears)
            mpp[nums[i]].push_back(i)  ;


        }
        int ans=INT_MAX;
        //iterate through map
        for(auto&it:mpp)
        {
            auto&v=it.second;

            if(v.size()<3) continue; //continue means go back dont proceed

            //iterate through triples
            for(int i=0;i+2<v.size();i++)
            {
                int dist=2*(v[i+2]-v[i]); //for same nums[i] , minimize(k-i)
                ans=min(ans,dist);
            }


        }
        return ans==INT_MAX?-1:ans;


    

         
        
    }
};