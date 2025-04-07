int missingNumber(int* nums, int n) 
{
    int sum = 0,total = (n*(n+1))/2;
    for(int i = 0;i<n;i++)
    {
        sum += nums[i];
    }
    return total-sum;
      
}