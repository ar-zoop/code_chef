int majorityElement(int arr[], int size)
    {
        
        // your code here
        int count=1, ele=arr[0];
        for(int i=1; i<size; i++){
            if(arr[i]!=ele){
                count--;
                // flag=1;
            }
            else{
                count++;
                // flag=1;
            }
            if(count==0){
                ele=arr[i];
                count=1;
                // flag=0;
            }
        }
        // cout<<ele;
        count=0;
        for(int i=0; i<size; i++){
            if(ele==arr[i]) count++;
        }
        if(count>(size/2)) return ele;
        return -1;
        
        
    }
};