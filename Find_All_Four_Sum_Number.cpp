class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int start, end, sum, temp_sum;
        for(int i=0; i<n-3; i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1; j<n-2; j++){
                if(j-1>i && arr[j]==arr[j-1])continue;
                start=j+1;
                end=n-1;
                sum=k-arr[i]-arr[j];
                int prev_pushback_start=-999, prev_pushback_end=-999;
                while(start<end){
                    temp_sum=arr[start]+arr[end];
                    if(sum==temp_sum){
                        if(arr[start]!=prev_pushback_start && arr[end]!=prev_pushback_end){
                            res.push_back({arr[i],arr[j],arr[start],arr[end]});
                            prev_pushback_start=arr[start]; prev_pushback_end= arr[end];
                        }
                        start++;
                        end--;
                    }
                    else if(sum<temp_sum){
                        end--;
                    }
                    else{
                        start++;
                    }
                }
            }
        }
        return res;
    }
};