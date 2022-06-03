#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[1001];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        map <int ,int, greater<int>> m;
        for (int i=0;i<n;i++){
            if(m.find(arr[i])==m.end()){
                m[arr[i]]=1;
            }
            else{
                m[arr[i]]++;
            }
        }
        
        int flag=0,store;
        int max_area=0;
        map <int, int>:: iterator itr;
        for(itr=m.begin();itr!=m.end();itr++){
            if((*itr).second >=4){
                flag=1;             
                max_area=(*itr).first*((*itr).first );
                break;
                               
            }
            else if ((*itr).second>=2){
                store=(*itr).first;
                flag=2;
                break;
            }
        }
        
        if(flag==0) cout<<-1<<endl;
        else if(flag==1)cout<<max_area<<endl;
        
        else{
            itr++;
            flag=0;
            while(itr!=m.end()){
                if ((*itr).second>=2){
                    cout<<store*(*itr).first<<endl;
                    break;
                }
                itr++;
                
            }
            if (flag==0) cout<<-1<<endl;
        }
        

    }
    
    return 0;
}