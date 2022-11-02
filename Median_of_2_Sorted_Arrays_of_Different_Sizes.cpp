class Solution{
    public:
    int mid_pos;
    
    double merge(vector<int>& array1, vector<int>& array2, int n, int m, int mid){
        vector <int> arr(n+m);
        int left=0, right=0, k=-1;
        while(k<mid && left<n && right<m){
            if(array2[right]<array1[left]){
                arr[++k]=array2[right];
                right++;
            }
            else{
                arr[++k]=array1[left];
                left++;
            }
        }
        while(k<mid && left<n){
            arr[++k]=array1[left];
            left++;
        }
        while(k<mid && right<m){
            arr[++k]=array2[right];
            right++;
        }
        if((n+m) %2==0){
            return (arr[k]+arr[k-1])/2.0;
        }
        return arr[k];
        
    }
    
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n=array1.size();
        int m= array2.size();
        mid_pos=(n+m)/2;
        return merge(array1, array2,n,m, mid_pos);
    
    }
};