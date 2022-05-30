#include<bits/stdc++.h>
using namespace std;

set<int, greater<int>> factor;

void find_factors(int m){
    int sqr=sqrt(m);
    for (int i=1;i<=sqr;i++){
        if(m%i==0){
            factor.insert(i);
            factor.insert(m/i);
        }
    }
}

bool isprime(int m){
    int sqr=sqrt(m);
    for(int i=2;i<sqr;i++){
        if(m%i==0){
            return false;
        }        
    }
    return true;
}

int trans(int n,int m){
    if(n==m) return 0;
    
    
    else if(isprime(m)) return -1;
    
    else{
        find_factors(n);
        
        set<int,greater<int>>::iterator itr;        
        itr=factor.begin();
        int count=0,div;
        while(m!=1 && div!=1){            
            div=*itr;
            if(m%(*itr)==0 ){
                // cout<<"hi";
                count++;
                m=(div);
            }
            else itr++;

        }
        return count;
        
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    int res=trans(n,m);
    cout<<res;
    return 0;
}