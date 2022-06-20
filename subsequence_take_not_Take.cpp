#include <bits/stdc++.h>
using namespace std;

void sub(int idx, vector <int> &v,int n, int arr[]){
    //base case with printing the vector
    if(idx==n){
        vector<int>::iterator itr;
        for (itr=v.begin();itr!=v.end();itr++){
            
            cout<<*itr<<" ";
        }
        if(v.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }

    //take 
    v.push_back(arr[idx]);
    sub(idx+1, v, n, arr);
    v.pop_back();

    //not take
    sub(idx+1, v, n, arr);
}

int main(){
    vector <int > v;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    // for (int i=0;i<n;i++){
    //     cout<<arr[i];
    // }
    sub(0, v, n, arr);
    return 0;
}