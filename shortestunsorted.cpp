//problametic ele will be stored in min and max variable and we will place them in their correct position
class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int minn=INT_MAX;
        int maxx=INT_MIN;
        int n=nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {//you cant check before first ele
                if(nums[i]>nums[i+1])
                {
                    minn = min(minn,nums[i]);// currmin and nums[i] me se jo bhi min hoga
                    maxx=max(maxx,nums[i]);

                }
            }
            else if(i==n-1)
            {
                if(nums[i]<nums[i-1])
                {//you cant check beyond last ele
                    minn = min(minn,nums[i]);// currmin and nums[i] me se jo bhi min hoga
                    maxx=max(maxx,nums[i]);

                }

            }


            else
            {
                if(nums[i]<nums[i+1] || nums[i]>nums[i-1])//both the neighbour
                {
                  minn = min(minn,nums[i]);// currmin and nums[i] me se jo bhi min hoga
                  maxx=max(maxx,nums[i]);
                }
            }
        }
        if(minn==INT_MAX || maxx==INT_MIN ) return 0;

        //find the posi o min and max,find the len,max,min
        int i,j;

        for( i=0;i<n && nums[i]<=minn;i++);
        for( j=n-1;j>=0 && nums[j]>=maxx;j--);

        return j-i+1;





    }
};
