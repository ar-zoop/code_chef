//sum and fact on n numbers using recursion
//the time complexity is O(n)
#include <bits/stdc++.h>
using namespace std;

int sum(int i, int n){
    if(i>n)return 0;
    return i+sum(i+1,n);
}

int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}

int arr[]={1,2,3,4,5};

//reverse array 
void rev(int i, int size){
    if(i==size/2)return;
    int temp=arr[i];
    arr[i]=arr[size-1-i];
    arr[size-1-i]=temp;
    rev(i+1,size);
    
}

int main(){
    // int res=sum(1,3);
    // cout<<res<<endl;
    // res=fact(4);
    // cout<<res<<endl;
    rev(0,5);
    for(int i=0;i<5;i++) cout<<arr[i];
    return 0;
}