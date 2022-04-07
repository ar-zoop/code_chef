#include <bits/stdc++.h>
using namespace std;
int area;
int main(){
    int t;
    cin>>t;    
    while(t--){
        area=1;
        int n, num;
        cin>>n;
        map <int , int> mpp ;
        map <int , int>  :: reverse_iterator itr;
        for (int i=0;i<n;i++){
            cin>>num;
            mpp[num]++;
        }
        
        // for(auto it:mpp){
        //     cout << it.first << " = " << it.second << '\n';
        // }
        int count=0;
        for (itr=mpp.rbegin(); itr!= mpp.rend(); itr++){
            // cout << itr->first << " = " << itr->second << '\n';
            if (itr->second >=4 && area==1){
              
                    area=itr->first*itr->first;
                    count=2;
                    break;
                
               
            }
            else if (itr->second >= 2){
                ++count;
                area*=itr->first;//area=area*first->key
                if (count==2){
                    break;
                }
            }            
        }
        if (count<2){
            cout<<-1<<endl;
        }
        else if (count==2){
            cout<<area<<endl;
        }
    }
    return 0;
}