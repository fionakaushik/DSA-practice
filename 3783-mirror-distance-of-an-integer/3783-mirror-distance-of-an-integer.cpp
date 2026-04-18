class Solution {
private:
    int getreverse(int n)
    {
        int rev=0;
        while(n>0)
        {
            int rem=n%10;
            rev=rev*10+rem;

            n/=10;

        }
        return rev;
    }
public:
    int mirrorDistance(int n) {
        
        int dist=abs(n- getreverse(n));
        return dist;
    }
    
};