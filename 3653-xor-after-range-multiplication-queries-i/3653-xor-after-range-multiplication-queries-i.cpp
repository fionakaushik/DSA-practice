class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        long long mod=1e9+7;

        for(int i=0;i<n;i++)
        {
            int idx=queries[i][0];
            int r = queries[i][1];
            int step = queries[i][2];
            int mul = queries[i][3];

            while(idx<=r)
            {
                nums[idx]=(1LL*nums[idx]* queries[i][3])%mod;
                idx+=step;
            }
        }
        int ans=0;
        for(int x:nums)
        {
            ans=ans^x;
        }

        return ans;
        
    }
};