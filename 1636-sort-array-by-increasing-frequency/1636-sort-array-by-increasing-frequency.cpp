class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int>freqmap;
        for(int n : nums)
        {
            freqmap[n]++;
        }
        //custom sort using comparator:
        sort(nums.begin(),nums.end(),[&freqmap](int a,int b){
            if(freqmap[a]!=freqmap[b]){
                return freqmap[a]<freqmap[b]; //lower freq comes first
            }
            return a>b;    //else return the larger number
        });
        
        return nums;
    }
};