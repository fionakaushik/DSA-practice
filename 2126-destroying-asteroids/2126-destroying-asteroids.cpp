class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end()); //non dec order sorting(ascending order)
        int sum=mass;
        for( int i=0;i<n;i++)
        {
            if(asteroids[i]>sum)
                return false;
                
            else if(sum>1e5)    //given constraint no asteroid[i] >10^5
                return true;     //early rwturn

            sum+=asteroids[i];
        }
        return true;
    }
};