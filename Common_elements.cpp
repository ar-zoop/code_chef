class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            map<int,int> freq;
            vector<int> res;
            for(int i=0; i<n1;i++){
                if(i>0 && A[i]!=A[i-1])
                    freq[A[i]]++;
                else if(i==0){
                    freq[A[i]]++;
                }
            }
            for(int i=0;i<n2;i++){
                if(i>0 && B[i]!=B[i-1]){
                    freq[B[i]]++;
                }
                else if(i==0){
                    freq[B[i]]++;
                }
            }
            for(int i=0;i<n3;i++){
                if(i>0 && C[i]!=C[i-1]){
                    freq[C[i]]++;
                }
                else if(i==0){
                    freq[C[i]]++;
                }
            }
            for(auto &x:freq){
                if(x.second>=3){
                    res.push_back(x.first);
                }
            }
            return res;
        }
};