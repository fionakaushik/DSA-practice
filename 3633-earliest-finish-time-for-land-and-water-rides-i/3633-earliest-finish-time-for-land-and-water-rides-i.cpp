class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int earliestPossTime1=INT_MAX;
        int earliestPossTime2=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int start=landStartTime[i];
            int finish=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++)
            {
                int endtime=0;
                if(waterStartTime[j]<=finish)
                {
                    int starttime=finish;
                    endtime=starttime+waterDuration[j];
                }
                else{
                    int starttime=waterStartTime[j];
                    endtime=waterStartTime[j]+waterDuration[j];
                }
                earliestPossTime1 = min(earliestPossTime1,endtime);

            }
        }
        for(int i=0;i<m;i++)
        {
            int start=waterStartTime[i];
            int finish=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++)
            {
                int endtime=0;
                if(landStartTime[j]<=finish)
                {
                    int starttime=finish;
                    endtime=starttime+landDuration[j];
                }
                else{
                    int starttime=landStartTime[j];
                    endtime=landStartTime[j]+landDuration[j];
                }
                earliestPossTime2 = min(earliestPossTime2,endtime);

            }
        }
        
        return min(earliestPossTime2,earliestPossTime1);
    }
};