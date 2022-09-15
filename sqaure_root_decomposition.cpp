#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0 ;i<n;i++){
        cin>>arr[i];
    }
    
    int len=sqrtl(n);
    vector <int> grouping_sum(len, 0);
    
    
    for(int i=0; i<n;i++){
        grouping_sum[i/len]+=arr[i];
    }
    
    int q;
    cin>>q;
    while(q--){
        
        
        int l,r;
        cin>>l>>r;
        int sum=0;      
        for(int i=l; i<=r ; ){
            if(l%len==0 && i+len-1 <=r) {           
                sum+=grouping_sum[i/len];
                i+=len;
            }
            else{
                sum+=arr[i];
                i++;
            }
        }
        cout<<sum;
        
    }
}