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
    if(ch2!='?' && pos==(s.length()-1)) num2=(int)s[0] -48;

    for (int i=0;i<k;i++){  
        if(num1==i || num2==i) {
         
            continue;
        }
        else {
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
        getline(cin,arr);
        int q_flag=0,inv_flag=0;

        
        //checking for invalid inputs and number of '?'
        
            for(int i=0;i<arr.length();i++){
                if(arr[i]=='?'){
                    q_flag+=1;
                }
                if((arr[i]==arr[i+1]||arr[arr.length()-1]==arr[0] )&& arr[i]!='?'){
                    inv_flag=1;
                    break;
                }
            }

            //invalid string
            if(inv_flag==1 ){
                // cout<<" pass1 ";
                cout<<"NO"<<endl;
            }

            //string entered is valid and full
            else if(q_flag==0 && inv_flag==0){
                // cout<<" pass2 ";
                cout<<arr<<endl;
            }
            
            //when the entire string is '?'
            else if (q_flag==arr.length()){
                if(k==1 && arr.length()>1) cout<<"NO";
                else if (k==2 && arr.length()%2!=0 && arr.length()>2)cout<<"NO";
                // else if (k==2 && arr.length()%2==0){
                //     cout<<" pass6 ";
                //     //to do
                //     ;
                // }
                else{
                    // cout<<" pass5 ";
                    hardcode(arr.length());
                }
                cout<<endl;
            }
          

            else  {
                //  cout<<" pass7 ";
                if(k==2){
                    
                    for(int i=0;i<arr.length();i++){
                    }
                }
                else{
                    for(int i=0;i<arr.length();i++)
                    {
                        if(arr[i]=='?'){
                            char ch1='a',ch2='a';
                            if(i!=0)ch1=arr[i-1];
                            if(i!=arr.length()-1) ch2=arr[i+1];
                            fill_q(i,arr,k,ch1,ch2);
                        }
                        else{
                            cout<<arr[i];
                        }
                    }
                    cout<<endl;
                }
            }
            
        }
    
    
    return 0;
}