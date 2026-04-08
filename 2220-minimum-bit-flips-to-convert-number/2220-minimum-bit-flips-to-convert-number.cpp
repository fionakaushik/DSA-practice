class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start ^ goal;

        //loop through the ans bits(set bits of ans is our required ans
        int cnt=0;
        while(ans>1)
        {
            if(ans&1)  //ans%2==1(odd)
                cnt+=1;
            ans=ans>>1;     //ans=ans/2
        }
        if(ans==1) cnt+=1;
        return cnt;

        
    }
};