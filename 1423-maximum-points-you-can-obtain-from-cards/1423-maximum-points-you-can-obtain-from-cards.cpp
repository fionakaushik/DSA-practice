class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int lsum=0;       //leftsum
        int rsum=0;       //rightsum
        int maxsum=0;
        //first of calculate sum of el from starting of array of eindow size k
        for(int i=0;i<k;i++)
            lsum+=cardPoints[i];

        maxsum=lsum;      //initialize maximum

        //now we gotta start removing from lsum and adding from rightsum
        int rightIdx=n-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=cardPoints[i]; //subtrack one el from lsum
            rsum+=cardPoints[rightIdx];  //add el at rightIDX(back)
            rightIdx--;

            maxsum=max(maxsum,lsum+rsum);

            
        }
        return maxsum;
    }

};