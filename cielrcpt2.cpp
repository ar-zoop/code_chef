#include <bits/stdc++.h>
using namespace std;

int expo(int base, int power){
    int a=1;
    for (int i=0;i<power;i++){
        a=a*base;
    }
    return a;
}

int sub(int idx, int target, int menu[],int n){
    // cout<<"wassup";
    int left=  0 , mid=0,right=0;
    if(target<=0){
        // cout<<"here";
        return 1;
    }
    if(idx==n-1){
        // cout<<"hi";
        return 0;
    }
    if(target>=menu[idx]){
        // cout<<"hello";
        left=sub(idx,target-menu[idx],menu,n);
        mid=sub(idx+1,target-menu[idx],menu,n);
        right=sub(idx+1,target,menu,n);
        if(left!=INT_MIN) cout<<left<<" ";
        if(right!=INT_MIN) cout<<left<<" ";
        if(mid!=INT_MIN) cout<<left<<" ";
        cout<<endl;
        
    }
    
    return left+mid+right ;
    
}

int main(){
    int t;
    cin>>t;
    int menu[12];
    for (int i=0;i<12;i++){
        menu[i]=expo(2,i);
    }
    while(t--){
        int p;
        cin>>p;
        int min=sub(0,p,menu,12);
        cout<<min<<endl;
    }
    return 0;
}