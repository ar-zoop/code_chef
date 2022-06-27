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
    int left=0, right=0, mid=0;
    //base case
    if(idx==n-1){
        if(target-menu[idx]==0){
            return 1;
        }
        else {
            return 0;
        }
    }
    if(target<=0) return 0;
    
    //left
    if(target-menu[idx] >=0){
        left=sub(idx, target-menu[idx], menu,n)+1;
        // cout<<left<<" ";
    }
    //mid
    if(target-menu[idx] >=0){
        mid=sub(idx+1,target-menu[idx],menu,n)+1;
        // cout<<mid<<" ";
    }

    //right
    if(target-menu[idx]>=0){
        right=sub(idx+1,target,menu,n)+0;
        // cout<<right<<" ";
    }
   
    //return min count
    return left+right+mid; 
}

int main(){
    int t;
    cin>>t;
    int menu[12];
    for (int i=0;i<12;i++){
        menu[i]=expo(2,i);
    }
    int min=INT_MAX;
    while(t--){
        int p;
        cin>>p;
        int temp=sub(0,p,menu,12);
        if(temp<min){
            min=temp;
        }
        cout<<min<<endl;
    }
    return 0;
}