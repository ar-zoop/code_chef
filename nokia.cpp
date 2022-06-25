#include <bits/stdc++.h>
using namespace std;
/*
int target;


int summation(set<int>s,int ele, int size){
    int left, right;
    for (itr = s.begin(); itr!=s.find(ele); itr++) {
        left=*itr;
    }
    itr++;
    right=*(++itr);

    if(left==s.end()&&right==s.end()){
        return ele+size-ele+1;
    }
    else if(left==s.end()){
        return ele+right-ele;
    }
    else if (right==s.end()){
        return ele-left+size-ele+1;
    }
    
    else{
        return ele-left + right- ele;
    }
}


int summation(vector <int>&v,int ele,int size){
    sort(v.begin(),v.end());
    // int count=-1;
    vector <int> :: iterator x;
    for(x=v.begin(); x<v.end();x++){
        // count++;
        if(*x==ele){
            break;
        }
    }
    // left=count-1;
    // right=count+1;
    int left,right;
    if(++x!=v.end()) right=*x;
    else right=-1;
     x--;
    if(--x!=v.end())left=*x;
    else left=-1;
    cout<<left<<" " <<right<<endl;


      if(left==-1&&right==-1){
        return ele+size-ele+1;
    }
    else if(left==-1){
        return ele+right-ele;
    }
    else if (right==-1){
        return ele-left+size-ele+1;
    }
    
    else{
        return ele-left + right- ele;
    }

}

bool f(int idx, int sum, vector <int> &ds, int arr[],int n, vector <int> &s){
    if(idx==n){
        if(sum==target){
            for(auto x: ds) cout<<x<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[idx]);
    s.push_back(arr[idx]);
    //sum calcs 
    sum=summation(s,arr[idx],n);
    // cout<<sum; /////////////////////////////////////////
    if(f(idx+1, sum,ds,arr,n,s))return true;
        
   
    ds.pop_back();
    s.pop_back();
    //sum calcs
    sum=summation(s,arr[idx],n);
    // cout<<sum; ////////////////////////////////////////
    if(f(idx+1, sum, ds, arr,n,s))return true;
        

    return false;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int>ds,s;
        int n;
        cin>>n>>target;
        int arr[31];
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
        if(f(0,0,ds,arr,n,s)) cout<<1;
        else cout<<0;
    }
 ;
    return 0;
}
*/;

int dac(int left, int right){
    int sum=0, sum_left=0, sum_right=0;
    //base cases
    if(left==right) return 2;

    int mid=(left+right)/2;

    //cases
    if((mid+1)<=right){
        sum_right= dac(mid+1, right)+((right-mid)+1);
    }
    else  sum_right= 1;
    if((mid-1)>=left){
        sum_left=dac(left, mid-1)+((mid-left)+1);
    }    
    else sum_left= 1;
    
    //return sum
    return sum_left+sum_right;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,max=0,min;
        cin>>n>>m;
        for (int i=2;i<n+2;i++){
            max+=i;
        }
        min= dac(0,n-1);
        // cout<<max<<endl<<min;
        int flag=0;

        for (int i=min;i<=max;i++){
            if (i==m) {
                cout<<0;
                flag=1;
                break;
            }
        }
        if(flag==0) {
            if(m>max) cout<<m-max;
            else cout<<-1;
        }
    }

    return 0;
}