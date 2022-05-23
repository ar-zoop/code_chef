#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int x,y,k,n,p,c;
    cin>>t;    
    while(t--){
        vector<pair<int,int>> notebook;
        cin>>x>>y>>k>>n;
        for (int i=0;i<n;i++){
            cin>>p>>c;
            notebook.push_back(make_pair(p,c));
        }
        sort(notebook.begin(), notebook.end());
        int flag=0;
        for (auto it:notebook){
            if(it.first >= (x-y) && k>=it.second){
                cout<<"LuckyChef\n";
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"UnluckyChef\n";
        }
    }
    return 0;
}