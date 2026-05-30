class Solution {
private:
    static bool cmp(vector<int>& val1,vector<int>& val2)
    {
        return val1[1]<val2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //this question is similar to N meetings in one room Q 
        //we choose amd sort intervals asc to des on the basis of end times
        // (smaller end times are prioritise)
        int n=intervals.size();
        // step 1:sort inervals on the basis of endtimes
        sort(intervals.begin(),intervals.end(),cmp);
        //step 2:
        int last_end_time=intervals[0][1] ; //0th row 1st col (firat interv always chosen)
        int cnt=1;
        for( int i=1;i<n;i++)
        {
            if(intervals[i][0]>=last_end_time)
            {
                cnt++;
                last_end_time=intervals[i][1];  //update the lastendtime

            }

        }
        return n-cnt;


        
    }
};