class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a,a+n, greater <int>());
        sort(b,b+n, greater<int>());
        // for(int i=0;i<n;i++){
            // cout<<a[i]<<" "<<b[i]<<endl;
            if(a[0]+b[0]>=k) return true;
        
        return false;
    }
};