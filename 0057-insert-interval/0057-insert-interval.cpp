class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n=intervals.size();
        //new ressultant 2D array 
        vector<vector<int>>res;
        //the intervals array is divided into 3 halves :leftmost & rightmost non overlapping middle overlapping
        int i=0;
        //leftmost non overlapping
        //end time of intervals[i][1] is less than start time of newINterval
        while( i<n && intervals[i][1]<newInterval[0]) 
        {
            res.push_back(intervals[i]);
            i++;
        }
        //middle overlapping interval : end of interval is greater than newInterval and start of interval is less than end of newInterval 
        //since end is grester than start of newInterval is obv implied we only gotta check one condn
        while(i<n && intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        //rightmost non overlapping interval
        //end time of newInterval is less than start time of intervals
        while(i<n )
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
        
    }
    
    
};