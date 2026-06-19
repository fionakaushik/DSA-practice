class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude=0;
        int curr_altitude=0;

        for( int g:gain)
        {
            curr_altitude+=g;// Building the prefix sum on the fly
            max_altitude=max(max_altitude,curr_altitude); // Tracking the peak
        }
        return max_altitude;
    }
};