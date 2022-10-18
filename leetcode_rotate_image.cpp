class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int temp,temp2,r=matrix.size()-1,l=0,t=0,b=r, p1,p2,p3,p4;
        p1=l;
        p2=t;
        p3=r;
        p4=b;
        // cout<<"pointers"<<endl;
        // cout<<l<<r<<t<<b<<endl;
        // cout<<p1<<p2<<p3<<p4<<endl;
        
        while(l<=r && t<=b && p1<matrix.size() && p2<matrix.size() && p3>=0 && p4>=0 ){
            // cout<<"pointers"<<endl;
            // cout<<l<<r<<t<<b<<endl;
            // cout<<p1<<p2<<p3<<p4<<endl;
            // cout<<matrix[t][p1]<<" "<<matrix[t][p2]<<" "<<matrix[b][]
            
             if(p1==r){
                // cout<<"helloo ";
                t++;
                b--;
                l++;
                r--;
                p1=l;
                p2=t;
                p3=r;
                p4=b;
                // cout<< matrix[t][p1]<<matrix[p2][r]<<matrix[b][p3]<<matrix[p4][l]<<endl;
                
            }
            if(l<=r && t<=b && p1<r && p2<b && p3>=0 && p4>=0)
           { temp=matrix[p2][r];
            matrix[p2][r]=matrix[t][p1];
            temp2=matrix[b][p3];
            matrix[b][p3]=temp;
            temp=matrix[p4][l];
            matrix[p4][l]=temp2;
            matrix[t][p1]=temp;
            p1++;
            p2++;
            p3--;
            p4--;}
            
            
            
        }
        
     
    }
};