bool cmp(string s1, string s2){
	    if (s1.length() == s2.length()) {
            return s1 > s2;
        }
        
        else{
            string s3=s1+s2, s4=s2+s1;
            if(s3>s4){
                return true;
            }
            else {
                return false;
            }
        }
        
      
	}
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), cmp);
	   
	    string res="";
	    for(int i=0; i<arr.size(); i++){
	        res+=arr[i];
	    }
	    return res;
	}
};