#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,que;
        cin>>n>>que;
        int length[n],queries[que];
        for(int i=0;i<n;i++){
            cin>>length[i];
            
        }
        
        sort(length, length+n);

        map<int,int> mpp;
        map<int,int>::iterator imp;
       
       for (int q=0;q<que;q++){
        cin>>queries[q];
       }
       int start=0;
       sort(queries,queries+que);
       for(int q=0;q<que;q++){
            if(mpp.find(queries[q])!=mpp.end()){
                imp=mpp.find(queries[q]);
                // cout<<"hello";
                cout <<imp->second<<endl;
            }
            else{
                int index = upper_bound(length, length+n, queries[q]-1) - length;
                cout<<"index"<<index<<endl;
                int count=n-index;
                int end=index-1;
                if(end==0){
                    mpp[queries[q]]=count;
                    cout<<count<<endl;
                }
                else{
                    while(end>start){
                        if(length[end]<queries[q]){
                            start++;
                            length[end]++;
                            
                            if(length[end]==queries[q]){
                                count++;
                                end--;
                            }
                        }
                    }
                    mpp[queries[q]]=count;
                    cout<<count<<endl;
                }
            }
        }
    }
    return 0;
}