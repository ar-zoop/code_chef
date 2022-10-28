class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recur(int idx, int arr[], int n, int memo[]){
        if(idx>=n) return 0;
        if(memo[idx]!=-1) return memo[idx];
        int take, not_take;
        take=recur(idx+2, arr,n, memo)+ arr[idx];
        
        not_take=recur(idx+1,arr,n, memo)+0;
        
        return memo[idx]=max(take, not_take);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int memo[n];
        memset(memo, -1, sizeof(memo));
        return (recur(0,arr,n,memo));
    }
};