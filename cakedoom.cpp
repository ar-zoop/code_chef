#include <bits/stdc++.h>
using namespace std;

void hardcode(int n){
    for (int i =1; i<=n/2; i++){
        cout<<0<<1;
    }
    if(n==1){
        cout<<0;
    }
    else if(n%2!=0){
        cout<<2;
    }
}

void fill_q(int pos, string &s, int  k, char ch1, char ch2){
    int num1=-1;
    int num2=-1; 
    
    if(ch1!='?'&& pos!=0 && ch1!='a')num1=(int)ch1-48;
    if(ch2!='?' && pos!=(s.length())-1 && ch2!='a') num2=(int)ch2-48;
    // if(pos!=0) num1=((int)s[pos-1])-48;
    // if(pos!=(s.length())-1 && s[pos+1]!='?') num2=((int)s[pos+1])-48;
    // cout<<"num1= "<<num1<<" "<<"num2= "<<num2<<"" ;
    for (int i=0;i<k;i++){  
        if(num1==i || num2==i) {
            
            // cout<<" prob13 ";
            // cout<<s[pos-1]<<" "<< s[pos+1];
            continue;
        }
        else {
            // cout<<" prob14 ";
            // cout<<"pass";
            // s[pos]=i;
            string temp;
            temp+=to_string(i);
            s.replace(pos,1,temp);
            cout<<i;
            return;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string arr;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // std::cin.ignore();
        getline(cin,arr);
        // cout<<"prob1";
        
        int q_flag=0,inv_flag=0;
        // cout<<"prob2";
        for(int i=0;i<arr.length();i++){
            // cout<<"prob3";
            if(arr[i]=='?'){
                // cout<<"prob4";
                q_flag+=1;
            }
            if((arr[i]==arr[i+1]||arr[arr.length()-1]==arr[0] )&& arr[i]!='?'){
                inv_flag=1;
                break;
            }
        }

    //    cout<<"prob5";
        if(inv_flag==1 ){
            // cout<<"prob6";
            cout<<"NO"<<endl;
        }
        else if(q_flag==0 && inv_flag==0){
            // cout<<"prob7";
            cout<<arr<<endl;
        }
         
        else if (q_flag==arr.length()){
            // cout<<"prob8";
            //least combo possible from the spaces given
            if(k==1 && arr.length()>1) cout<<"NO";
            else if (k==2 && arr.length()%2!=0 && arr.length()>2)cout<<"NO";
            else hardcode(arr.length());
            cout<<endl;
        }
        else{
            // cout<<"prob9";

            //make the least combo
            for(int i=0;i<arr.length();i++)
            {
                // cout<<" prob10 ";
                // cout<<endl<<arr<<endl;
                if(arr[i]=='?'){
                    // cout<<" prob11 ";
                    char ch1='a',ch2='a';
                    if(i!=0)ch1=arr[i-1];
                    if(i!=arr.length()-1) ch2=arr[i+1];
                    fill_q(i,arr,k,ch1,ch2);
                }
                else{
                    // cout<<" prob12 ";
                    cout<<arr[i];
                }
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}