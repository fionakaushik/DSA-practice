class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n =cost.size();
        //sort first 
        sort(cost.begin(),cost.end());
        //traverse from backwards
        int cnt=0;
        int amt=0;
        for( int i=n-1;i>=0;i--)
        {
            cnt++;
            if(cnt<3)
                amt+=cost[i];
            else
                cnt=0;
        }
        return amt;

        
    }
};