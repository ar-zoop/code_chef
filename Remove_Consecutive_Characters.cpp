class Solution
    {public:
        string removeConsecutiveCharacter(string S)
        {
            // code here.
            int i=0;
            // if(S.length)
            while(i<S.length()-1){
                if(S[i]==S[i+1]){
                    S.erase(i,1);
                    // cout<<S[i]<<" "<<i<<" ";
                    // cout<<S<<endl;
                }
                else{
                    i++;
                }
            }
            return S;
        }
    };