class Solution {
public:
    // int reverse(long long n)
    // {
    //     long long rev_num=0;
    //     while (n>0)
    //     {
    //         long long dig=n%10;
    //         rev_num=rev_num*10+dig;
    //         n/=10;
    //     }
    //     return rev_num;
    // }
    // int same_digits(long long n1,long long n2)
    // {
    //     int sameDig=0;
    //     while(n1>0 && n2>0)
    //     {
    //         int d1=n1%10;
    //         int d2=n2%10;
    //         if(d1==d2)
    //             sameDig++;
    //         n1/=10;
    //         n2/=10;

    //     }
    //     return sameDig;
    // }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //TRIED SOLVING IT LIKE THIS BUT WRONG

        // int maxLen=0;
        // for( int i =0;i<arr1.size();i++)
        // {
        //     long long num1=reverse(arr1[i]);
        //     for( int j=0;j<arr2.size();j++)
        //     {
        //         long long nums2=reverse(arr2[j]);
        //         int len= same_digits(num1,nums2);
        //         maxLen= max(maxLen,len);

        //     }
        // }
        // return maxLen;


        //OPTIMAL APPROACH ->use set and math and push all the prefixes 
        unordered_set<int>prefixes;
        // Step 1: Chops off digits from right-to-left.
        // e.g., 100 -> inserts 100, then 10, then 1. Zeros are perfectly preserved!
        for(int val: arr1)
        {
            while(val>0)
            {
                prefixes.insert(val);
                val/=10;
            }
        }
        int maxlen=0;
        // Step 2: Do the same for arr2 and find matches
        for( int val:arr2)
        {
            while(val>0)
            {
                if(prefixes.count(val))
                {
                    // Calculate digit length mathematically 
                    int len =log10(val)+1;
                    maxlen=max(maxlen,len);
                    break;         //no need to look for smaller length of thst val if found
                }
                val/=10;
            }
        }
        return maxlen;

        
    }
};