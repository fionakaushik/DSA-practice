class Solution {
public:
    int numberOfSubstrings(string s) {
      //brute 
    //   int n=s.size();
      
    //   for(int i=0;i<n;i++)
    //   {
    //         vector<int>v(3,0);
    //         for(int j=i;j<n;j++)
    //         {
    //             char ch=s[j];
    //             v[ch-'a']=1;
    //             if((v[0]+v[1]+v[2])==3)
    //             {
    //                 cnt+=n-j;
    //                 break;
    //             }

    //         }
    //   }
    //   return cnt;    T.C=O(N^2)

    

    // //Better(O(2N))
    // int i=0,j=0,cnt=0;
    // vector<int>freq(3,0);
    // while(j<n)
    // {
    //     char ch=s[j];
    //     freq[ch-'a']++;
    // Shrink the window from the left while all three characters are present
    //     while(v[0]>0 &&v[1]>0&&v[2]>0)
    //     {
    //         cnt+=n-j;
    //         //move i while j is at that idx only so we get every substr ending at j
    //         v[s[i]-'a']--;
    //         i++;
    //     }
    //     j++;
    // }
    // return cnt;
    


    //OPTIMAL(MOST)-O(N)
    // with every char there's many sybstr that end at that char
    vector<int>lastseen(3,-1); //stores idx at which char was last seen
    int n =s.length();
    int cnt=0;
    for( int i=0;i<n;i++)
    {
        char ch=s[i];
        lastseen[ch-'a']=i;
        if(lastseen[0]!=-1 &&lastseen[1]!=-1 && lastseen[2]!=-1)
        {
            //find minimal window min idx of valid string +1 =cnt
            cnt=cnt+(1+min({lastseen[0],lastseen[1],lastseen[2]}));
        }
    }
    return cnt;
    }
        
    
};