#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin>>t;
    t=2*t;
    
    while(t--){
        
        
        stack<int> stack;
        vector<int> v;
        int n;
        cin>>n;        
        int result[100],data[100];
         
        for (int i=0;i<n;i++){
            cin>>data[i];
            stack.push(data[i]);
            
        }
       
        int current = stack.top();
        v.push_back(current);
        stack.pop();
        
        while(stack.top()>=current && !stack.empty()){
            current=stack.top();
            v.push_back(current);           
            stack.pop();
        }
       
        
        current=stack.top();
        stack.pop();
        sort (v.begin(),v.end());
        vector <int>::iterator ptr=v.begin();    
        
        stack.push(*ptr);
        v.push_back(current);
        v.erase(v.begin());
        
        
        sort(v.begin(),v.end());
        for (ptr=v.begin();ptr<v.end();ptr++){
            stack.push(*ptr);
        }
        
        int i=-1,temp;
        while(!stack.empty()){
            result[++i]=stack.top();
            stack.pop();
        }
         for (int c=0;c<=i;c++){
            cout<<result[c]<<" ";
        }
        /*
        for (int i=0;i<(n/2);i++){
            temp=result[i];
            result[i]=result[n-i-1];
            result[n-1-i]=temp;
        }
        int flag=0;
        for (int i=0;i<n;i++){
            
            if(result[i]!=data[i]){
                flag=1;
                break;
            }
            
        }
        if(flag==0) cout<<-1<<endl;
        else{
            for(int i=0;i<n;i++){
                cout<<result[i]<<" ";
            }
        }
        cout<<endl;
        */
    }
    
    return 0;
}