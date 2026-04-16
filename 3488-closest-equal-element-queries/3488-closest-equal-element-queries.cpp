class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        //crute (o(q*n)) will give TLE


        //optimal
        int n=nums.size();

        unordered_map<int,vector<int>>idxarr;

        for(int i=0;i<nums.size();i++)
        {
            idxarr[nums[i]].push_back(i);

        }
        vector<int>result;

        for(int qi:queries)
        {
            int el=nums[qi];
            vector<int>&vec=idxarr[el];

            int sz=vec.size();

            //no more occurence of tht el 
            if(sz==1)
            {
                result.push_back(-1);
                continue;
            }
            int pos=lower_bound(vec.begin(),vec.end(),qi)-vec.begin();
            int res=INT_MAX;

            //right neighbour=pos+1;
            int right=vec[(pos+1)%sz];
            int d=abs(qi-right);
            int circular_dist=n-d;
            res=min({res,d,circular_dist});

            //left neighbour=pos+1;
            int left=vec[(pos-1+sz)%sz];
            d=abs(qi-left);
            circular_dist=n-d;
            res=min(res,min(d,circular_dist));

            result.push_back(res);



        }
        return result;

    }
};