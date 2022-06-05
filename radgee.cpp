#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        queue <int> r,g,extra;
        int rpt=0,gpt=0,temp;
        for (int i=0;i<n;i++) {
            cin>>temp;
            r.push(temp);
        }
        for (int i=0;i<n;i++) {
            cin>>temp;
            g.push(temp);
        }
        for (int i=0;i<m;i++) {
            cin>>temp;
            extra.push(temp);
        }
        while(!r.empty() || !g.empty()){
            if(r.front()>g.front()){
                rpt++;
                r.pop();
                g.pop();
                if(!extra.empty()){
                    r.push(extra.front());
                    extra.pop();
                    g.push(extra.front());
                    extra.pop();
                }
            }
            else{
                gpt++;
                g.pop();
                r.pop();
                if(!extra.empty()){
                    g.push(extra.front());
                    extra.pop();
                    r.push(extra.front());
                    extra.pop();
                }
            }
        }
        if(rpt>gpt){
            cout<<"Radhesh wins";
        }
        else if(gpt<rpt){
            cout<<"Geethakoomaree wins";
        }
        else{
            cout<<"Tie";
        }
    }
    return 0;
}