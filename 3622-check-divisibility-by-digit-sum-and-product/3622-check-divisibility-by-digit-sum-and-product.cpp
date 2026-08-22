class Solution {
public:
    bool checkDivisibility(int n) {
        //get digits 
        int dig_sum=0;
        int dig_prod= 1;
        int temp=n;
        while(temp>0)
        {
            int dig=temp%10;
            temp/=10;
            dig_sum +=dig;
            dig_prod*=dig;
        }

        if(n%(dig_sum+dig_prod)==0)
            return true;
        return false;
    }
};