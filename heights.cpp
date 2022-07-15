#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>mpp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi=max(maxi,arr[i]);
            if(mpp.find(arr[i])!=mpp.end()){
                mpp[arr[i]]=1;

            }
            else{
                mpp[arr[i]]++;
            }
        }
        int k=0,ele;
        map<int,int> ::iterator imr;
        for(imr=mpp.begin();imr!=mpp.end();imr++){
            if((*imr).second==1){
                k++;
                ele=(*imr).first;
            }
        }
        if(k==1){
            if(ele!=max){
                count++;
            }
            else {
                int count_3=0, count2=0;
                for(imr=mpp.begin();imr!=mpp.end();imr++){
                    if((*imr).second>=3){
                        count_3++;
                    }
                    else if((*imr).second==2){
                        count_2++;
                    }
                }
                if(count_3>0){
                    count++;
                }
                else if(count_2>0){
                    count+=2;
                }
            }
        }
        else if(k>1){
            if(k%2==0){
                count+=(k/2);
            }
            else{
                count+=(k/2)+1;
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}