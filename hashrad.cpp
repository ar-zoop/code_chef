#include <bits/stdc++.h>
using namespace std;

bool lexi(int num, int total, int length, vector <int> &v, string og){
    
    if(length==v.size() && num==total){
        string temp;
        for (auto x: v){
            // cout<<char(x+96);
            char shit=char(x+96);
            temp+=shit;
            // cout<<temp;
        }
        int res=temp.compare(og);
        if (res==0) return 0;
        else {
            cout<<temp;
            return 1;
        }
    }
    else if(length==v.size()){
        return 0;
    }
    for (int i=1;i<27;i++){
        v.push_back(i);
        int a=lexi(i+num, total, length, v,og);
        v.pop_back();
        if (a==1) return 1;
    } 
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int>v;
        int sum=0;
        char word[100001];
        cin>>word;
        for (int i=0;i<strlen(word);i++){
            sum+=((int)word[i])-96;
        }
        int a;
        for (int i=1;i<27;i++){
            v.push_back(i);
            a=lexi(i,sum,strlen(word), v, word);
            v.pop_back();
            if(a==1) break;
        }
        if(a==0)cout<<-1;
        cout<<endl;
    }
    return 0;
}