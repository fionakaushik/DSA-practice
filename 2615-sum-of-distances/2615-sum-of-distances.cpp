class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {
        // APPROACH 1: KINDA SLIMMY

        // int n = nums.size();
        // vector<long long > ans(n,0);
        // unordered_map<int, vector<int>> mpp;

        // // Group indices by their value
        // for (int i = 0; i < n; i++) {
        //     mpp[nums[i]].push_back(i);
        // }

        // for (auto& it : mpp) {
        //     vector<int>& v = it.second;
        //     int k = v.size();
        //     if (k <= 1) continue;

        //     // Calculate total sum of indices for this number
        //     long long total_sum = 0;
        //     for (int index : v) total_sum += index;

        //     long long prefix_sum = 0;
        //     for (int i = 0; i < k; i++) {
        //         long long current_index = v[i];
                
        //         // Sum of distances to the left
        //         long long left_dist = (current_index * i) - prefix_sum;
                
        //         // Sum of distances to the right
        //         long long suffix_sum = total_sum - prefix_sum - current_index;
        //         long long right_dist = suffix_sum - (current_index * (k - 1 - i));
                
        //         ans[current_index] = left_dist + right_dist;
                
        //         // Update prefix_sum for the next element
        //         prefix_sum += current_index;
        //     }
        // }

        // return ans;


        //APPROACH 2:kinda easy and nice
        
        int n=nums.size();
        vector <ll>ans(n,0);

        unordered_map<int,ll>indexSum; //nums[i]->sum of i's(i.e indexes)
        unordered_map<int,ll>indexCount;  //nums[i]->freq of i

        //left to right
        for(int i=0;i<n;i++)
        {
            //foreach nums[i] look in map first if it has prefix idxsum and idxfreq
            ll freq=indexCount[nums[i]];
            ll sum=indexSum[nums[i]];

            ans[i]+=(freq*i)-sum;//observation

            //insert sum of idx i and freq of i in both mp
            indexSum[nums[i]]+=i;
            indexCount[nums[i]]+=1;
        }

        //clear the maps
        indexSum.clear();
        indexCount.clear();

        //right to left
        for(int i=n-1;i>=0;i--)
        {
            ll freq=indexCount[nums[i]];
            ll sum=indexSum[nums[i]];

            ans[i]+=sum-(freq*i);//observation

            //insert sum of idx i and freq of i in both mp
            indexSum[nums[i]]+=i;
            indexCount[nums[i]]+=1;
        }
        return ans;

    }
};