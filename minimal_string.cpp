#include <bits/stdc++.h>
using namespace std;
int main(){
    queue<char>s;
    stack<char>t;
    vector <char> u;
    string og;
    cin>>og;
    for (int i=0;i<og.length();i++){
        s.push(og[i]);
    }
    sort(og.begin(),og.end());
    int i=0;
    while(!s.empty()){
        t.push(s.front());
        s.pop();
        if(og[i]==t.top()){
            u.push_back(t.top());
            t.pop();
            i++;
        }
    }
    while(!t.empty()){
        u.push_back(t.top());
        t.pop();
    }
    vector<char>::iterator itr;
    for (itr=u.begin();itr<u.end();itr++){
        cout<<*itr;
    }
    return 0;
}