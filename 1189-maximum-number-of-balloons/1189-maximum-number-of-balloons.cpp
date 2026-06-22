class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0; // counter for all letters
        for( char ch: text)
        {
            if( ch=='b')
                b++;
            else if(ch=='a')
                a++;
            else if( ch=='l')
                l++;
            else if( ch=='o')
                o++;
            else if( ch=='n')
                n++;
            
        }
        l=l/2; // since these 2 letters appears twice 
        o=o/2;   //divide by two 

        // the minimum occurance among these letters is the answer
        int ans = min(l,o);
        ans=min(ans,b);
        ans=min(ans,a);
        ans= min(ans,n);
        return ans;
        
    }
};