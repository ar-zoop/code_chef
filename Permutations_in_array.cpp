public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n, greater<int>());
        for(int i=0;i<n;i++){
            // cout<<a[i]<<" "<<b[i]<<endl;
            if(a[i]+b[i]>=k) return true;
        }
        return false;
    }
};