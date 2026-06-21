class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //counting sort counts the no of different keys avl. in the array like a frequency array with length = max_el+1 so that max_ el has an idx too

        //step 1: find the max el in the costs array 
        int max_el = costs[0];
        for ( auto cost : costs)            //O(N)
        {
            max_el=max(max_el,cost);
        }
        //step 2: count the freq of el in array
        vector<int>freq(max_el+1);
        for(int cost: costs)             //O(N)
        {
            freq[cost]++;
        }

        //now we go through the freq array created and add ice creams
        int count=0; //total count o\f ice crems we buy
        for( int i=1;i<freq.size();i++) //idxes represent costs of ice cream      //O(MAX_EL+1)
        {
            if(i>coins)
                break;
            if( freq[i]==0)
                continue; //no ice cream of that cost in costs array
            
            int quantity=min(freq[i],coins/i);//min of the available stock of that cost ice cream and the max no of that cost ice-cream we can buy(coins/cost(i))
            count+=quantity;
            coins-=quantity*i;
            
        }
        return count;

    }
};