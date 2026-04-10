class Solution {

    // RECURSIVE APPROACH

// private:    
//     void findCombinations(vector<int>&ds,vector<vector<int>>&ans,vector<int>& nums,int idx)
//     {
        
//         ans.push_back(ds);
//         for(int i=idx;i<nums.size();i++)
//         {
//             // if(i!=idx&& nums[i]==nums[i-1]) continue;
//             ds.push_back(nums[i]);
//             findCombinations(ds,ans,nums,i+1);
//             ds.pop_back();

//         }
//     }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        //  vector<vector<int>>ans;
        // vector<int>ds;

        // sort(nums.begin(),nums.end());

        // findCombinations(ds,ans,nums,0);

        // return ans;

//BIT MANIPULATION APPROACH

    int n =nums.size();
    int subsets=1<<n;  //(2^n)
    vector<vector<int>>ans;

    for(int num=0;num<subsets;num++) //num is truth table combination of idxs  
    {
        vector<int>ls;  //new subset list evertime
        for(int i=0;i<n;i++)
        {
            //check if the ith bit is set or not in num
            if(num & (1<<i))  //true means set
                ls.push_back(nums[i]);
            
        }
        ans.push_back(ls);

    }
    return ans;   //same time&space complexity as recursive(only recursive stack space decreases)

        
    }

        
    
};