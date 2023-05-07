//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sort_stack(stack<int> &s){
    stack <int> aux;
    // while(!s.empty()){
    if(s.empty()) return;
    
    int x=s.top();
    s.pop();
    
    sort_stack(s);
    
    
    while(!s.empty() && x<s.top()){
        aux.push(s.top());
        s.pop();
    }
    s.push(x);
  
    while(!aux.empty()){
        s.push(aux.top());
        aux.pop();
    }
    
    // }
}

void SortedStack :: sort()
{
   //Your code here
  
   sort_stack(s);
}