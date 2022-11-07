class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        for(int i=1; i<n; i++){
            arr[i]+=arr[i-1];
        }
       
        int count=0;
        
        map<ll, int> freq;
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
            // cout<<freq[arr[i]];
        }
        int m=0;
        for(auto x: freq){
            if(x.first == 0) count+=(x.second);
            if(x.second>1){
                m=x.second;
                count+=(m*(m-1)/2);
            }
            
        }
        // if(arr[0]==0) count++;
        
        return count;
    }
};