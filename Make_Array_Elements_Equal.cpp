#include <bits/stdc++.h> 
int findMinimumCost(vector<int> &arr, int n)
{
    // Write your code here
    sort(arr.begin(), arr.end());
    int median, sum=0;
    if(n%2!=0){
        median=n/2;
    }
    else{
        median=-999;
    }
    if(median>0){
        for(int i=0; i<n;i++){
            sum+=abs(arr[median]-arr[i]);
        }
    }
    else{
        int temp;
        median=n/2;
        for(int i=0; i<n;i++){
            temp+=abs(arr[median]-arr[i]);
        }
        sum=temp;
        temp=0;
        median=(n/2)-1;
        for(int i=0; i<n;i++){
            temp+=abs(arr[median]-arr[i]);
        }
        sum=min(temp,sum);
    }
    return sum;
    
}
