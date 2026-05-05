class Solution {
public:
    int trap(vector<int>& height) {
        // //an lmax and rmax array for each idx of array that tells for each i in array whats max ht of building on its left and right
        // int n =height.size();
        // vector<int>lmax(n,0);
        // vector<int>rmax(n,0);

        // lmax[0]=height[0];
        // for(int i=1;i<n;i++)
        //     lmax[i]=max(lmax[i-1],height[i]);

        // rmax[n-1]=height[n-1];
        // for( int i=n-2;i>=0;i--)
        //     rmax[i]=max(rmax[i+1],height[i]);
        
        // //use formula : min(lmax,rmax)-ht[i] ,  thsi is the amt of water that'll be logged
        // int total=0;
        // for( int i =0;i<n;i++)
        // {
        //     total+=min(lmax[i],rmax[i])-height[i];
        // }
        // return total ;                       //T.C:0(3N)=O(N) , S.C: O(2N)


        //optimising space from first approach by not keeping two arrays for lmax and rmax at each i rather calcuklating em on the go ;

        //2 POINTER APPROACH
        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0;
        int total=0;
        while(l<=r)
        {
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);

            //onlye shorter of lmax or rmax matter
            if(lmax<=rmax)
            {
                total+=lmax-height[l];
                l++;
            }
            else
            {
                total+=rmax-height[r];
                r--;
            }
        }
        return total;


        
    }
};