#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long d;
    cin>>n>>d;
    int arr[100001]; 
    for (int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n,greater<int>());
    int i=0;
    int count=0;
    while(i<n-1){
        if((arr[i]-arr[i+1])<=d) {
            i+=2;
            count++;
        }
        else i++;
    }
    cout<<count<<endl;
    return 0;
}