#include <bits/stdc++.h>
using namespace std;
void jnext (){       
        
        stack<int> stack;
        vector<int> v;
        int n;
        cin>>n;        
        int result[n],data[n];//replace w n
         
        for (int i=0;i<n;i++){
            cin>>data[i];
            stack.push(data[i]);
            
        }

        //3 cases possible
        int data2[n];//replace w n
        for (int i =0;i<n;i++){
            data2[i]=data[i];
        }
       
        //descending:
        sort(data2,data2+n,greater<int>());
        int flag=1;
        for (int i=0;i<n;i++){
            if(data2[i]!=data[i]){
                flag=0;
                break;
            }
        }
        if (flag==1){
            cout<<-1<<endl;
            return;
        }

        //ascending:
        sort(data2,data2+n);
        flag=1;
        for (int i=0;i<n;i++){
            if(data2[i]!=data[i]){
                flag=0;
                break;
            }
        }

        if (flag==1)        {
            int temp= data2[n-1];
            data2[n-1]=data2[n-2];
            data2[n-2]=temp;
            for(int i=0;i<n;i++){
                cout<<data2[i]<<" ";
            }
            return;
        }
        
        //generalised case:
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
        int ptr_counter=0;  
        while (*ptr<current){
            ptr++;
            ptr_counter++;
        }
        if(*ptr>current ){
            stack.push(*ptr);
            v.push_back(current);
            v.erase(v.begin()+ptr_counter);
        }
        
        
        sort(v.begin(),v.end());
        for (ptr=v.begin();ptr<v.end();ptr++){
            stack.push(*ptr);
        }
        
        int i=-1,temp;
        while(!stack.empty()){
            result[++i]=stack.top();
            stack.pop();
        }
         
        for (int i=0;i<(n/2);i++){
            temp=result[i];
            result[i]=result[n-i-1];
            result[n-1-i]=temp;
        }
       
        
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        
        cout<<endl;    
    
    
    return;
}

int main(){
    int t;
    cin>>t;
    t=2*t;
    
    while(t--){
        jnext();
    }
    return 0;
}