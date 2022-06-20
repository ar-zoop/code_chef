// #include <iostream>
#include <bits/stdc++.h>
// #include <stack>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll count=0;
        stack<pair<char,int>> mystack;
        string s;
        cin >> s;
        int index=1;
        for (ll i = 0; i<s.length(); i++)
        {
            if(s[i]=='<')mystack.push(make_pair(s[i],i));
            else if(s[i]=='>')
            {
                if(!mystack.empty())
                {
                    mystack.pop();
                    count+=2;
                    index=i;
                    
                }
                else{
                    break;
                }
            }
        }
        pair<char, int> p;
        if(!mystack.empty()){
            while(!mystack.empty()){
                p=mystack.top();
                int pos=p.second;
                if (pos<index){ count=0;break;}
                mystack.pop();
            }
            
        }
        cout<<count<<endl;
    }
    return 0;
}