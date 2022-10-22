class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        int n=arr.length();
       int count[26]={0};
       char output[n];
       for(int i=0; i<n; i++){
           count[arr[i]-97]++;
       }
       
       for(int i=1; i<26; i++){
           count[i]+=count[i-1];
       }
       
       for(int i=0;i<n; i++){
           output[--count[arr[i]-97]]=arr[i];
       }
       
       string res="";
       
       for(int i=0;i<n; i++){
           res+=output[i];
       }
       
       return res;
    }
};