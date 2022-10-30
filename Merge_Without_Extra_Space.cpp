class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int ptr1= 0, ptr2=0, max=n;
            while(ptr1<max && ptr2<m){
                if(arr1[ptr1]<=arr2[ptr2]){
                    ptr1++;
                }
                else{
                    int temp=arr1[max-1];
                    arr1[--max]=arr2[ptr2];
                    arr2[ptr2]=temp;
                    // desc=ptr2;
                    ptr2++;
                    // ptr1++;
                    // max--;
                    
                }
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
            // return;
        } 
};