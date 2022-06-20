#include <bits/stdc++.h>
using namespace std;

bool sub(int idx, vector <int> &v, int sum, int arr[], int n, int target){
    if(idx==n){
        if (sum==target){
            vector <int> ::iterator itr;
            for (itr=v.begin();itr!=v.end();itr++) cout<<*itr;
            cout<<endl;
            return true;
        }
        return false;
    }
    //take
    v.push_back(arr[idx]);
    if(sub(idx+1, v, sum+arr[idx],arr, n, target)==true) return true;
    v.pop_back();

    //not take
    if(sub(idx+1, v, sum,arr,  n, target)==true) return true;        
    
    return false;
    
}

int main(){
    vector <int> v;
    int t, sum;
    cout<<"enter number of elements in array: ";
    cin>>t;
    int arr[t];
    cout<<"enter elements: ";
    for (int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<"Enter sum: ";
    cin>>sum;
    sub(0,v,0,arr,t,sum);
}