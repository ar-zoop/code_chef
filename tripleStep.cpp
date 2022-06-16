#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;
void func(int idx, int size, vector <int> &ds){
    if(idx==size){
        s.insert(ds);
        // cout<<"pass1"  <<endl;
        return;
    }
    if(idx>size){
        // cout<<"pass2"<<endl;
        return;
    }     
    for (int i=1;i<3;i++){
        if(size-idx<i){
            // cnt++;
            // cout<<"pass3"<<endl;
            return;
        }
        // cout<<"for i="<<i<<"and idx= "<<idx <<" idx+i= "<<idx+i<<" ";
        // cout<<"pass4"<<endl;
        ds.push_back(idx);
        func(idx+i, size, ds);
        ds.pop_back();
        
    }
}

void printVector(vector<int> myVector)
{
  cout << "[ ";
  for(auto element : myVector)
    cout << element << ' ';
  cout << "]\n";
}

int main(){
    vector <int> ds;
    
    int n,count=0;
    cin>>n;
    for (int i=0;i<n;i++){
        // cout<<"pass0"<<endl;    
        for (int j=0;j<i;j++){
            ds.push_back(j);
        }
        func(i, n, ds);
        ds.clear();
    }
    for (auto itr=s.begin();itr!=s.end();itr++){
        // printVector(*itr);
        count++;
    }
    cout<<count;
    return 0;
}
