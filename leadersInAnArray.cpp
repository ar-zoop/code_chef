class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector <int> res;
        int big=INT_MIN;
        int i;
        for(i=n-1; i>=0;i--){
            if(a[i]>=big){
                // cout<<a[i];
                big=a[i];
                res.push_back(big);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};