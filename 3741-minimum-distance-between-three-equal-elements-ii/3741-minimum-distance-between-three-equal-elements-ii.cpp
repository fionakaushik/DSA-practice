class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)  //(el.(idx1,idx2))
        {
            mp[nums[i]].push_back(i);

        }
        int ans=INT_MAX;
        //go through the map 
        for(auto &it:mp)   //o(n) as a whole(eventho all uniq el,tot el is n)
        {
            auto &v=it.second;
            if(v.size()<3) continue;

            //when v.size()>=3 we find triples and minimize it w sliding window
            //in the vec v 
            for(int k=0;k+2<v.size();k++) //group of triples(0,1,2),(1,2,3)...
            {
                int mini = 2* (v[k+2] - v[k]);
                ans=min(ans,mini);
            }
        }
        return (ans==INT_MAX?-1:ans);
        
    }
};