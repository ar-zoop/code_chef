#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, pair <long long, int>> & a,
         pair<long long, pair <long long, int>>& b)
{
    return a.second.first < b.second.first;
}
int main(){
int t;
cin>>t;
while(t--){
    int n, count=0;
    cin>>n;
    map <long long, pair <long long, int>> ::iterator itr;
    map <long long, pair <long long, int>> mpp;
    long long b[n], l[n];
    for (int i=0;i<n;i++){
        cin>>b[i]>>l[i];
    }
    int temp;
    for (int i=0;i<n;i++){
        if((itr=mpp.find(b[i]))!=mpp.end()){
            if (itr->second.first > l[i]){
                temp=itr->second.first;
                itr->second.first=l[i];
                itr->second.second=i;
                l[i]=0;
                int j=itr->second.second;
                l[j]=temp;
            }
        }
        else{
            mpp.insert(make_pair(b[i],make_pair(l[i],i)));
            l[i]=0;
            count++;
        }
    }
    //
void sort(map<long long, pair <long long, int>>& M)
{
  
    // Declare vector of pairs
    vector<long long, pair <long long, int>> A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    // Print the sorted value
    for (auto& it : A) {
  
        cout << it.first << ' '
             << it.second,first << endl;
    }
}
    //

    int sum=0;
    int i=1;
    cout<<"map";
   for(auto it:mpp){
            // cout << it.first << " = " << it.second.first << "and"<<it.second.second<<'\n';
        sum+=it.second.first  *i;
        cout<<sum<<" ";
    }
    cout<<"array";
    for (int i=0;i<n;i++){
        // cout<<b[i]<<"="<<l[i]<<endl;
        sum+=count*l[i];
        cout<<sum<<" ";
    }
    cout<<count<<endl;


}
    return 0;
}