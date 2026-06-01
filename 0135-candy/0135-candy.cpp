class Solution {
public:
    int candy(vector<int>& ratings) {
        // int n = ratings.size();
        // vector<int>arr(n,1);
        // for( int i=1;i<n;i++)
        // {
        //     if(ratings[i]>ratings[i-1])
        //         arr[i]=arr[i-1]+1;
        // }
        // for( int i=n-2;i>=0;i--)
        // {
        //     if(ratings[i]>ratings[i+1]){
                
        //             arr[i]=max(arr[i+1]+1,arr[i]);
        //     }
        // }
        // int sum=0;
        // for (int candy :arr)
        // {
        //     sum+=candy;
        // }
        // return sum;


        //most optimal -> Slope /TREND approach
        
        // Size of the ratings array
        int n = ratings.size(); 
        if (n <= 1) return n;
        //we iterate from 2nd child
        int i=1;              //bcz first child(ratings[0])gets 1 candy
        /*Initialize the total number of candies,
        starting with one candy for the first child*/
        int sum = 1; 
        
        while(i<n)
        {
            //flat trend:(ratings[i]==ratings[i-1])

            /*Check if the current child's rating
            is equal to the previous one*/
            if(ratings[i]==ratings[i-1])
            {
                //If so, give the current child one candy 
                sum = sum + 1; 
                
               //Move to the next child*/
                i++; 
                
                /*Skip the rest of the loop and
                move to the next iteration*/
                continue;           
            }
            //upwards trend(ratings[i]>ratings[i+1])

            else{

                /* Initialize the candy count
                for increasing rating trend*/
                int peak=1;
                while(i<n && ratings[i]>ratings[i-1])
                {
                    /*Increment candy count
                    for increasing trend*/
                    peak+=1;
                    //update tot candy cnt
                    sum+=peak;
                    i++;
                }
                //downward trend (we care  about sum of cnadies and not correct distribution of candis)

                /*Initialize the candy count
                for decreasing rating trend*/
                int down =1;
                while(i<n && ratings[i]<ratings[i-1])
                {
                    /*Update the total number of
                    candies for decreasing trend*/
                    sum+=down;
                    i++; //move to next
                    down++;  //condy given to next downward child

                }
                /*Check if the candy count for
                decreasing trend exceeds the peak*/
                if(down>peak)
                {
                    /*Adjust the total number of
                    candies to satisfy the condition*/
                    sum+=down-peak;
                }
            }

            
        }
        return sum;
        
    }
//We use continue in flat case because the work is fully finished.

//We don't use continue after increase loop because we still need to check for a possible downhill part of the same mountain.
};