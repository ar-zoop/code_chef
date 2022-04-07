#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool comparator(pair<long long, long long >p1, pair<long long, long long >p2) {
	if(p1.second > p2.second) {
		return true; 
	} else if(p1.second == p2.second){
		if(p1.first<p2.first) return true; 
	}
	return false; 
}

int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long d;
        cin>>n>>d;
        pair <long long, long long > p[n];
        for (int i=0;i<n;i++){
            cin>>p[i].first;
        }
        for (int i=0;i<n;i++){
            cin>>p[i].second;
        }        
        sort(p,p+n,comparator);
        int count=0;
        long long sum=0;
        
        for (int i=0;i<n;i++){
            if (count==2 || d==0){
                break;
            }
            else if (d>=p[i].first){
                count++;
                sum+=p[i].second;//sweetness additoin
                d-=p[i].first;//price dedduciton
                // printf("sum= %d d= %d count=%d p[i]=%lld\n",sum, d, count,p[i].second);
            }
            
        }
        
        // for (int i=0;i<n;i++){
        //     cout<<p[i].first<<" "<<p[i].second<<endl;
        // } 
        cout<<sum<<endl;
    }
}