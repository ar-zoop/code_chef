
string printSequence(string strs)
{
    //code here.
    string res="";
    for(int i=0 ; i<strs.size(); i++){
        if(strs[i]==' '){
            res+=to_string(0);
        }
        else
            {char letter=strs[i];
            int num=letter-65;
            int keypad=num/3;
            keypad+=2;
            if(keypad>=7){
                if(strs[i]=='P' || strs[i]=='Q' || strs[i]=='R' || strs[i]=='S'){
                    if(strs[i]=='P'){
                        res+=to_string(7);
                    }
                    else if(strs[i]=='Q'){
                        res+=to_string(77);
                    }
                    else if(strs[i]=='R'){
                        res+=to_string(777);
                    }
                    else if(strs[i]=='S'){
                        res+=to_string(7777);
                    }
                }
                else if(strs[i]=='T' || strs[i]=='U' || strs[i]=='V'){
                    if(strs[i]=='T'){
                        // cout<<"pass1";
                        res+=to_string(8);
                    }
                    else if(strs[i]=='U'){
                        // cout<<"pass2";
                        res+=to_string(88);
                    }
                    else if(strs[i]=='V'){
                        // cout<<"pass3";
                        res+=to_string(888);
                    }
                }
                else {
                    if(strs[i]=='W'){
                        res+=to_string(9);
                    }
                    else if(strs[i]=='X'){
                        res+=to_string(99);
                    }
                    else if(strs[i]=='Y'){
                        res+=to_string(999);
                    }
                    else{
                        res+=to_string(9999);
                    }
                }
            }
            else{
                
                int rep= num%3;
                rep++;
                for(int j=0;j<rep;j++){
                    res+=to_string(keypad);
                }
            }
        }
        
    }
    return res;
    
}