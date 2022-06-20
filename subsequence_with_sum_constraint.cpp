#include <bits/stdc++.h>
using namespace std;

void sub(int idx, vector <int> &v, int sum, int arr[], int n, int target){
    if(idx==n){
        if (sum==target){
            vector <int> ::iterator itr;
            for (itr=v.begin();itr!=v.end();itr++) cout<<*itr;
            cout<<endl;
        }
        return;
    }
    //take
    v.push_back(arr[idx]);
    sub(idx+1, v, sum+arr[idx],arr, n, target);
    v.pop_back();

    //not take
    sub(idx+1, v, sum,arr,  n, target);

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